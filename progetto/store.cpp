#include "store.h"
#include "GUI/baselayout.h"

Store::Store()
{

}

Store::~Store()
{

}


void Store::setPath(const QString x)
{
  path = x;
}

int Store::getTypeInt(Computer *x) const
{
  if (x->getType() == "Desktop")
    return 0;
  if (x->getType() == "Laptop")
    return 1;
  if (x->getType() == "Tablet")
    return 2;
  return -1;
}

void Store::addItem(Computer*x)
{
  container.push_back(x);
}

// saveJson, createJsonarray, writeJsonDoc => per salvare il file
// Per salvare la lista corrente in un file json basta chiamare la funzione saveToJson()
void Store::saveJson()
{
  QJsonObject jsonObj;
  QJsonArray jsonArray;
  for (auto it=container.begin(); it!=container.end(); ++it) {
      jsonObj = createJsonObj(*it);
      jsonArray.push_back(jsonObj);
    }
  writeJsonDoc(&jsonArray);
}

QJsonObject Store::createJsonObj(Computer *x) const
{
  QJsonObject jsonObj;

  switch (getTypeInt(x)) {
  case 0:{
        Desktop *d = static_cast<Desktop*>(x);
        jsonObj["type"] = "Desktop";
        jsonObj["numMonitors"] = QString::number(d->getNumMonitor()).toInt();
      }break;
  case 1:{
        Laptop *l = static_cast<Laptop*>(x);
        jsonObj["type"] = "Laptop";
        jsonObj["screenSize"] = QString::fromStdString(l->getScreenSize());
      }break;
  case 2:{
        Tablet *t = static_cast<Tablet*>(x);
        jsonObj["type"] = "Tablet";
        jsonObj["touch"] = t->isTouch();
      }break;
    }

  jsonObj["operativeSystem"] = QString::fromStdString(x->getOperativeSystem());
  jsonObj["name"] = QString::fromStdString(x->getName());
  jsonObj["sizeCase"] = QString::fromStdString(x->getSizeCase());
  jsonObj["colorCase"] = QString::fromStdString(x->getColorCase());
  jsonObj["gaming"] = x->isForGaming();
  jsonObj["peripherals"] = x->hasPeripherals();
  jsonObj["hdd"] = QString::number(x->getHdd()).toInt();
  jsonObj["ram"] = QString::number(x->getRam()).toInt();
  return jsonObj;
}

void Store::writeJsonDoc(QJsonArray *array) const
{
  QFile saveFile(path);
  saveFile.open(QFile::WriteOnly);
  QJsonDocument jsonDoc(*array);
  saveFile.write(jsonDoc.toJson());
  saveFile.close();
}

// readJson(QString) prende come input il path di un file json. Da quel file json costruisce gli oggetti.
void Store::readJson()
{
  QFile file;
  file.setFileName(path);
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QString jsonString;
  jsonString = file.readAll();
  file.close();

  auto jsonDoc=QJsonDocument::fromJson(jsonString.toUtf8());
  QJsonArray jsonArray = jsonDoc.array();

  for (int i=0;i<jsonArray.count();++i) {
      if (jsonDoc.array()[i].toObject().value("type") == "Desktop") {
          Desktop *d = new Desktop
              (jsonDoc.array()[i].toObject().value("operativeSystem").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("name").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("sizeCase").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("colorCase").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("gaming").toBool(),
               jsonDoc.array()[i].toObject().value("peripherals").toBool(),
               jsonDoc.array()[i].toObject().value("hdd").toInt(),
               jsonDoc.array()[i].toObject().value("ram").toInt(),
               jsonDoc.array()[i].toObject().value("numMonitors").toInt()
                );
          addItem(d);
        }
      if (jsonDoc.array()[i].toObject().value("type") == "Laptop") {
          Laptop *l = new Laptop
              (jsonDoc.array()[i].toObject().value("operativeSystem").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("name").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("sizeCase").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("colorCase").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("gaming").toBool(),
               jsonDoc.array()[i].toObject().value("peripherals").toBool(),
               jsonDoc.array()[i].toObject().value("hdd").toInt(),
               jsonDoc.array()[i].toObject().value("ram").toInt(),
               jsonDoc.array()[i].toObject().value("screenSize").toString().toStdString()
                );
          addItem(l);
        }
      if (jsonDoc.array()[i].toObject().value("type") == "Tablet") {
          Tablet *t = new Tablet
              (jsonDoc.array()[i].toObject().value("operativeSystem").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("name").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("sizeCase").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("colorCase").toString().toStdString(),
               jsonDoc.array()[i].toObject().value("gaming").toBool(),
               jsonDoc.array()[i].toObject().value("peripherals").toBool(),
               jsonDoc.array()[i].toObject().value("hdd").toInt(),
               jsonDoc.array()[i].toObject().value("ram").toInt(),
               jsonDoc.array()[i].toObject().value("touch").toBool()
                );
          addItem(t);
        }
    }
}

void Store::search(QString type, QString name, QString color, QString system, double x, double y)
{
  bool noType = false;
  bool noName = false;
  bool noColor = false;
  bool noSystem = false;
  bool noPrice = false;

  if (type == nullptr)
    noType = true;
  if (name == nullptr)
    noName = true;
  if (color == nullptr)
    noColor = true;
  if (system == nullptr)
    noSystem = true;
  if (x < 0 && y < 0)
    noPrice = true;

  for (auto it=container.begin(); it!=container.end(); ++it) {
      if (noType)
        type = QString::fromStdString((*it)->getType());
      if (noName)
        name = QString::fromStdString((*it)->getName());
      if (noColor)
        color = QString::fromStdString((*it)->getColorCase());
      if (noSystem)
        system = QString::fromStdString((*it)->getOperativeSystem());
      if (noPrice){
          x = 0;
          y = 9999;
        }

      if (type == QString::fromStdString((*it)->getType())
         && name == QString::fromStdString((*it)->getName())
         && system == QString::fromStdString((*it)->getOperativeSystem())
         && color == QString::fromStdString((*it)->getColorCase())
         && x < (*it)->getTotalPrice()
         && (*it)->getTotalPrice() < y) {
          resContainer.push_back(*it);
        }
    }
}


QString Store::getInfo(Computer *x) const
{
  QString info = "Nome: " + QString::fromStdString(x->getName()) + "\n"
      + "Sistema Operativo: " + QString::fromStdString(x->getOperativeSystem()) + "\n"
      + "Colore: " + QString::fromStdString(x->getColorCase()) + "\n"
      + "Dimensione case: " + QString::fromStdString(x->getSizeCase()) + "\n"
      + "HDD: " + QString::number(x->getHdd()) +" GB" + "\n"
      + "RAM: " + QString::number(x->getRam()) +" GB" + "\n"
      + "Accessori? " + (x->hasPeripherals() ? "Si":"No") + "\n"
      + "Gaming? " + (x->isForGaming() ? "Si":"No") +"\n";

  switch (getTypeInt(x)) {
  case 0:{
        Desktop *d = static_cast<Desktop*>(x);
        info = info + "Numero monitors: " + QString::number(d->getNumMonitor()) + "\n";
      }break;
  case 1:{
        Laptop *d = static_cast<Laptop*>(x);
        info = info + "Dimensione schermo: " + (d->getScreenSize() == "Big" ? "Big":"Small") + "\n";
      }break;
  case 2:{
        Tablet *d = static_cast<Tablet*>(x);
        info = info + "Touch? "+ (d->isTouch() ? "Yes":"No") + "\n";
      }break;
    }
  info = info + "Prezzo: " + QString::number(x->getTotalPrice()) + " €";
  return info;
}





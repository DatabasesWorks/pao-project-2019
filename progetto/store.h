#ifndef STORE_H
#define STORE_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QVariant>
#include <QDir>

#include "qontainer.h"
#include "hierarchy/computer.h"
#include "hierarchy/desktop.h"
#include "hierarchy/laptop.h"
#include "hierarchy/tablet.h"

class Controller;
class Store
{
public:
  Store();
  ~Store();
  Qontainer<Computer*> container;
  Qontainer<Computer*> resContainer;
  QString path;   // QString che contiene il path del file da salvare o aprire

public:
  void setPath(const QString);        // Setta la variabile 'path'
  int getTypeInt(Computer*) const;    // Ritorna un indice int che rappresenta il tipo di Computer
  void addItem(Computer*);            // Aggiunge un oggetto computer nel container di tipo Qontainer  

  // json - salvataggio
  void saveJson();
  QJsonObject createJsonObj(Computer*)const;
  void writeJsonDoc(QJsonArray*)const;

  // json - apertura
  void readJson();

  void search(QString, QString, QString, QString, double, double);

  QString getInfo(Computer*) const;    // Prende le informazioni di un oggetto computer
};

#endif // STORE_H

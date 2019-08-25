#include "GUI/controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Store *s = new Store();
  Controller *w = new Controller(s);
  w->show();
  return a.exec();
}

#ifndef MONITORCOMBOBOX_H
#define MONITORCOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita dal numero di monitor che e' possibile ordinare
*/

class MonitorComboBox: public QComboBox
{
  Q_OBJECT
public:
  MonitorComboBox()
  {
    for (int i = 0;i<=5;++i)
      insertItem(i, QString::number(i));
  }
};


#endif // MONITORCOMBOBOX_H

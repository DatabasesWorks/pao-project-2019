#ifndef HDDCOMBOBOX_H
#define HDDCOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita con le possibili dimensioni hard disk
*/

class HddComboBox: public QComboBox
{
  Q_OBJECT
public:
  HddComboBox()
  {
    insertItem(0, QString::number(128));
    insertItem(1, QString::number(256));
    insertItem(2, QString::number(512));
  }
};

#endif // HDDCOMBOBOX_H

#ifndef RAMCOMBOBOX_H
#define RAMCOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita dalla quantita' di ram che si puo' acquistare
*/

class RamComboBox: public QComboBox
{
  Q_OBJECT
public:
  RamComboBox()
  {
    insertItem(0, QString::number(4));
    insertItem(1, QString::number(8));
    insertItem(2, QString::number(16));
  }
};

#endif // RAMCOMBOBOX_H

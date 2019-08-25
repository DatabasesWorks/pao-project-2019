#ifndef OPERATIVESYSTEMCOMBOBOX_H
#define OPERATIVESYSTEMCOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita con i possibili sistemi operativi
*/

class OperativeSystemComboBox: public QComboBox
{
  Q_OBJECT
public:
  OperativeSystemComboBox()
  {
    insertItem(0, "Windows");
    insertItem(1, "Linux");
    insertItem(2, "Android");
    insertItem(3, "No Operative System");
  }
};

#endif // OPERATIVESYSTEMCOMBOBOX_H

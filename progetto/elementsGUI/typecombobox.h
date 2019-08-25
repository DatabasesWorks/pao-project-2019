#ifndef TYPECOMBOBOX_H
#define TYPECOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita dal tipo di computer che e' possibile scegliere
*/

class TypeComboBox: public QComboBox
{
  Q_OBJECT
public:
  TypeComboBox()
  {
    insertItem(0, "Desktop");
    insertItem(1, "Laptop");
    insertItem(2, "Tablet");
  }
};

#endif // TYPECOMBOBOX_H

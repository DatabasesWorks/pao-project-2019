#ifndef CASESIZECOMBOBOX_H
#define CASESIZECOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita con le possibili grandezze di un case di un desktop
*/

class CaseSizeComboBox: public QComboBox
{
  Q_OBJECT
public:
  CaseSizeComboBox()
  {
    insertItem(0, "XL-ATX");
    insertItem(1, "ATX");
    insertItem(2, "MINI-ATX");
  }
};


#endif // CASESIZECOMBOBOX_H

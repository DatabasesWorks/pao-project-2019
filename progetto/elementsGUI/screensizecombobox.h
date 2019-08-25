#ifndef SCREENSIZECOMBOBOX_H
#define SCREENSIZECOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita con le scelte di grandezze schermo laptop
*/

class ScreenSizeComboBox: public QComboBox
{
  Q_OBJECT
public:
  ScreenSizeComboBox()
  {
    insertItem(0, "Small");
    insertItem(1, "Big");
  }
};

#endif // SCREENSIZECOMBOBOX_H

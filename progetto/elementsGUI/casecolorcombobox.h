#ifndef CASECOLORCOMBOBOX_H
#define CASECOLORCOMBOBOX_H

#include <QComboBox>

/*
  Classe derivata da QComboBox riempita dai colori di Qt
*/

class CaseColorComboBox: public QComboBox
{
  Q_OBJECT
public:
  CaseColorComboBox()
  {
    const QStringList colorNames = QColor::colorNames();
    for (int i = 0; i<colorNames.size();) {
        const QString &colorName = colorNames.at(i);
        const QColor color(colorName);
        addItem(colorName, color);
        const QModelIndex idx = model()->index(i++, 0);
        model()->setData(idx, color, Qt::DecorationRole);
      }
  }
};


#endif // CASECOLORCOMBOBOX_H

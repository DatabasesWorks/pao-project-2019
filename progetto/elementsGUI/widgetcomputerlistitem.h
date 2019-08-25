#ifndef WIDGETCOMPUTERLISTITEM_H
#define WIDGETCOMPUTERLISTITEM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "stylegui.h"

class WidgetComputerListItem: public QWidget
{
public:
  WidgetComputerListItem();
  virtual ~WidgetComputerListItem();
  QWidget* createLayoutPriceWidget(QString str);

public:
  QWidget *priceWidget;
  QHBoxLayout *layoutPriceWidget;
  QLabel *priceLabel;
};

#endif // WIDGETCOMPUTERLISTITEM_H

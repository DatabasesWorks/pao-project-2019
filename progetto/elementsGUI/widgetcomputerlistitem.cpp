#include "widgetcomputerlistitem.h"

WidgetComputerListItem::WidgetComputerListItem()
{

}

WidgetComputerListItem::~WidgetComputerListItem()
{

}

QWidget* WidgetComputerListItem::createLayoutPriceWidget(QString str)
{
  priceWidget = new QWidget(this);
  layoutPriceWidget = new QHBoxLayout();
  priceLabel = new QLabel();
  priceLabel->setStyleSheet("QLabel { qproperty-alignment: 'AlignVCenter | AlignRight'; }");
  priceLabel->setFont(StyleGUI::listFont);
  layoutPriceWidget->addWidget(priceLabel);
  priceWidget->setLayout(layoutPriceWidget);
  priceLabel->setText(str + " €");
  return priceWidget;
}

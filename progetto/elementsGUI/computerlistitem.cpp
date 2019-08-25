#include "computerlistitem.h"

ComputerListItem::ComputerListItem(Computer *obj):ptr(obj)
{

}

ComputerListItem::~ComputerListItem()
{
  if(ptr)
    delete ptr;
}

bool ComputerListItem::operator<(const QListWidgetItem &item) const
{
  if (this->data(Qt::UserRole) > item.data(Qt::UserRole))
    return false;
  return true;
}

Computer* ComputerListItem::getPtr() const
{
  if (ptr)
    return ptr;
  return nullptr;
}

void ComputerListItem::setInfo()
{
  Computer *obj = this->getPtr();
  this->setData(Qt::UserRole, obj->getTotalPrice());
  this->setText(QString::fromStdString(obj->getName()));
}

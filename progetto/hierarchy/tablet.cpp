#include "tablet.h"
#include <QDebug>

double Tablet::pricePen = 19.99;
double Tablet::priceTouch = 30.15;

Tablet::Tablet(string s, string n, string sC, string cC, bool g, bool p, int h, int r, bool t)
  : Computer(s,n,sC,cC,g,p,h,r),
    touch(t)
{

}

Tablet::~Tablet()
{

}

Tablet::Tablet(const Tablet& other)
  : Computer (other),
    touch(other.touch)
{

}

bool Tablet::isTouch() const
{
  return touch;
}

void Tablet::setTouch(bool b)
{
  touch = b;
}

double Tablet::getTotalPrice() const
{
  return Computer::getTotalPrice() + (isTouch()? priceTouch:0) + (hasPeripherals()? pricePen:0);
}

string Tablet::getType() const
{
  return "Tablet";
}


// ==== overloading operatori '==' e '!=' ====
bool Tablet::operator==(const Tablet& other) const
{
  return Computer::operator==(other) && touch == other.touch;
}

bool Tablet::operator!=(const Tablet& other) const
{
  return Computer::operator!=(other) || touch != other.touch;
}

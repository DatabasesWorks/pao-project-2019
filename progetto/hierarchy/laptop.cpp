#include "laptop.h"

// ==== dati di tipo statico ====
double Laptop::priceBig = 70.95;

// ==== costruttore e costruttore di copia
Laptop::Laptop(string s, string n, string sC, string cC, bool g, bool p, int h, int r, string size)
  : Computer(s,n,sC,cC,g,p,h,r),
    screenSize(size)
{

}

Laptop::~Laptop()
{

}

Laptop::Laptop(const Laptop& other)
  : Computer (other),
    screenSize(other.screenSize)
{

}

string Laptop::getScreenSize() const
{
  return screenSize;
}

void Laptop::setScreenSize(string str)
{
  screenSize = str;
}

string Laptop::getType() const
{
  return "Laptop";
}


double Laptop::getTotalPrice() const
{
  return Computer::getTotalPrice() + (getScreenSize()=="Big"? priceBig:0);
}

// ==== overloading operatori '==' e '!=' ====
bool Laptop::operator==(const Laptop& other) const
{
  return Computer::operator==(other) && screenSize == other.screenSize;
}

bool Laptop::operator!=(const Laptop& other) const
{
  return Computer::operator!=(other) || screenSize != other.screenSize;
}

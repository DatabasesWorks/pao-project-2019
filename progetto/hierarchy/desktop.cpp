#include "desktop.h"

double Desktop::priceMonitor = 120.75;

// ==== costruttore e costruttore di copia ====
Desktop::Desktop(string s, string n, string sC, string cC, bool g, bool p, int h, int r, int nM)
  : Computer(s,n,sC,cC,g,p,h,r),
    numMonitor(nM)
{

}

Desktop::~Desktop()
{

}

Desktop::Desktop(const Desktop& other)
  : Computer (other),
    numMonitor(other.numMonitor)
{

}


int Desktop::getNumMonitor() const
{
  return numMonitor;
}
void Desktop::setNumMonitor(int x)
{
  numMonitor = x;
}

string Desktop::getType() const
{
  return "Desktop";
}

// ==== metodo getTotalPrice ====
double Desktop::getTotalPrice() const
{
  return Computer::getTotalPrice() + priceMonitor*numMonitor;
}

// ==== overloading operatori '==' e '!=' ====
bool Desktop::operator==(const Desktop& other) const
{
  return Computer::operator==(other) && numMonitor == other.numMonitor;
}

bool Desktop::operator!=(const Desktop& other) const
{
  return Computer::operator!=(other) || numMonitor != other.numMonitor;
}



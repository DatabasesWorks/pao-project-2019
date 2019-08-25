#include "computer.h"
// Static data
double Computer::priceBase = 450.50;          // prezzo per computer 4gb ram
double Computer::priceGaming = 150.95;        // Extra per hardware piu' performante
double Computer::priceRam = 20.05;
double Computer::priceHdd = 32.20;

// Costruttore e costruttore di copia
Computer::Computer(string s, string n, string sC, string cC, bool g, bool p, int h, int r)
  : operativeSystem(s),
    name(n),
    sizeCase(sC),
    colorCase(cC),
    gaming(g),
    peripherals(p),
    hdd(h),
    ram(r)
{

}

Computer::Computer(const Computer& other)
  : operativeSystem(other.operativeSystem),
    name(other.name),
    sizeCase(other.sizeCase),
    colorCase(other.colorCase),
    gaming(other.gaming),
    peripherals(other.peripherals),
    hdd(other.hdd),
    ram(other.ram)
{

}

Computer::~Computer()
{

}

double Computer::getTotalPrice() const
{
    return priceBase + (isForGaming() ? priceGaming : 0) + ((getRam()/4)*priceRam) + ((getHdd()/128)*priceHdd);
}

// Overloading operatori
bool Computer::operator==(const Computer& other) const
{
  return operativeSystem == other.operativeSystem &&
      name == other.name &&
      sizeCase == other.sizeCase &&
      colorCase == other.colorCase &&
      peripherals == other.peripherals &&
      gaming == other.gaming &&
      hdd == other.hdd &&
      ram == other.ram;

}

bool Computer::operator!=(const Computer& other) const
{
  return
      operativeSystem != other.operativeSystem ||
      name != other.name ||
      sizeCase != other.sizeCase ||
      colorCase != other.colorCase ||
      peripherals != other.peripherals ||
      gaming != other.gaming ||
      hdd != other.hdd ||
      ram != other.ram;
}

// Metodi GET
string Computer::getOperativeSystem() const
{
  return operativeSystem;
}

string Computer::getName() const
{
  return name;
}

string Computer::getSizeCase() const
{
  return sizeCase;
}

string Computer::getColorCase() const
{
  return colorCase;
}

int Computer::getHdd() const
{
  return hdd;
}

int Computer::getRam() const
{
  return ram;
}

bool Computer::hasPeripherals() const
{
  return peripherals;
}

bool Computer::isForGaming() const
{
  return gaming;
}

// Metodi SET
void Computer::setOperativeSystem(string str)
{
  operativeSystem = str;
}

void Computer::setName(string str)
{
  name = str;
}

void Computer::setSizeCase(string str)
{
  sizeCase = str;
}

void Computer::setColorCase(string str)
{
  colorCase = str;
}

void Computer::setHdd(int x)
{
  hdd = x;
}

void Computer::setRam(int x)
{
  ram = x;
}

void Computer::setGaming(bool b)
{
  gaming = b;
}

void Computer::setPeripherals(bool b)
{
  peripherals = b;
}



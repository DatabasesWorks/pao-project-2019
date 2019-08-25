#ifndef DESKTOP_H
#define DESKTOP_H

#include "computer.h"

class Desktop: public Computer
{
private:
  int numMonitor;
  static double priceMonitor;

public:
  // Costruttore, Costruttore di copia e distruttore
  Desktop(string="", string="", string="", string="", bool=false, bool=false, int h=128, int r=4, int nM=0);
  Desktop(const Desktop&);
  virtual ~Desktop();

  // Metodo get e set
  int getNumMonitor() const;
  void setNumMonitor(int);

  // Metodi virtuali
  virtual double getTotalPrice() const;
  virtual string getType() const;

  // Overloading operatori
  bool operator==(const Desktop&) const;
  bool operator!=(const Desktop&) const;

};

#endif // DESKTOP_H

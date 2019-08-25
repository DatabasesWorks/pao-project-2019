#ifndef LAPTOP_H
#define LAPTOP_H

#include "computer.h"

class Laptop: public Computer
{
private:
  string screenSize;
  static double priceBig;   // Prezzo extra se il monitor è di tipo 'Big'

public:
  // Costruttore, Costruttore di copia e distruttore
  Laptop(string="", string="", string="", string="", bool=false, bool=false, int h=128, int r=4, string size="Small");
  Laptop(const Laptop&);
  virtual ~Laptop();

  // Metodo get e set
  string getScreenSize() const;
  void setScreenSize(string);

  // Metodi virtuali
  virtual double getTotalPrice() const;
  virtual string getType() const;

  // Overloading operatori
  bool operator==(const Laptop&) const;
  bool operator!=(const Laptop&) const;
};

#endif // LAPTOP_H

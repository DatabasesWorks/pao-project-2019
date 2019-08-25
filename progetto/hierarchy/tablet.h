#ifndef TABLET_H
#define TABLET_H
#include "computer.h"
class Tablet: public Computer
{
private:
  static double priceTouch;         // Costo tablet touch
  static double pricePen;           // Costo tablet con pennino
  bool touch;
public:
  // Costruttore, Costruttore di copia e Distruttore
  Tablet(string="", string="", string="", string="", bool=false, bool=false, int h=128, int r=4, bool t=true);
  Tablet(const Tablet&);
  virtual ~Tablet();

  // Metodo get e set
  bool isTouch() const;
  void setTouch(bool);

  // Metodi virtuali
  virtual double getTotalPrice() const;
  virtual string getType() const;

  // Overloading operatori
  bool operator==(const Tablet&) const;
  bool operator!=(const Tablet&) const;
};

#endif // TABLET_H

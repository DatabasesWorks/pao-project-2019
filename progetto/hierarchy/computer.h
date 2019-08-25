#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
using std::string;

class Computer
{
private: 
  string operativeSystem;             // Sistema Operativo
  string name;                        // Nome
  string sizeCase;                    // Grandezza case
  string colorCase;                   // Colore case
  bool gaming;                        // Bool che definisce se il pc e' da gaming
  bool peripherals;                   // Bool che dice se l'utente vuole peripherals (mouse + keyboard oppure pennino per tablet)
  int hdd;                            // Dimensione Hard Drive Disk
  int ram;                            // Gb Ram
  static double priceBase;            // Costo base di un computer
  static double priceGaming;          // Costo extra per hardware adatto al gaming
  static double priceRam;             // Costo per 4 gb ram
  static double priceHdd;             // Costo per 128 gb

public:
  // Metodi get
  string getOperativeSystem() const;
  string getName() const;
  string getSizeCase() const;
  string getColorCase() const;
  int getHdd() const;
  int getRam() const;
  bool isForGaming() const;
  bool hasPeripherals() const;

  // Metodi set
  void setOperativeSystem(string);
  void setName(string);
  void setSizeCase(string);
  void setColorCase(string);
  void setHdd(int);
  void setRam(int);
  void setGaming(bool);
  void setPeripherals(bool);

  // Costruttore e distruttore
  Computer(string="", string="", string="", string="", bool=false, bool=false, int h=128, int r=4);
  virtual ~Computer();

  // Metodi virtuali
  virtual string getType() const  =0; // Metodo virtuale puro
  virtual double getTotalPrice() const;

  // Costruttore di copia
  Computer(const Computer&);

  // Overloading operatori
  virtual bool operator==(const Computer&) const;
  virtual bool operator!=(const Computer&) const;
};

#endif // COMPUTER_H















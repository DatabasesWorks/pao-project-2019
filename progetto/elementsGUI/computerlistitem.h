#ifndef COMPUTERLISTITEM_H
#define COMPUTERLISTITEM_H

#include <QListWidgetItem>

#include "hierarchy/computer.h"

/*
  Classe derivata da QComboBox riempita con le possibili grandezze di un case di un desktop
*/

class ComputerListItem: public QListWidgetItem
{
private:
  Computer *ptr;

public:
  ComputerListItem(Computer *);
  virtual ~ComputerListItem();
  Computer *getPtr() const;                          // Metodo get per ottenere il puntatore all'oggetto Computer
  void setInfo();                                    // Funzione per inserire dati di Computer* all'interno di un ComputerListItem
  bool operator<(const QListWidgetItem &item) const; // Ridefinizione dell'operatore < per utilizzare il metodo sortItems() di QListWidget
};


#endif // COMPUTERLISTITEM_H

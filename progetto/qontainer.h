#ifndef QONTAINER_H
#define QONTAINER_H
#include <iostream>

template <class T>
class Qontainer{
private:
  unsigned int capacity;   // Capacita' del Qontainer
  unsigned int elements;   // Numero di oggetti presenti all'interno del Qontainer
  T* ptr;                  // Puntatore all'oggetto all'interno del Qontainer

public:
  // Class iterator
  class iterator{
    friend class Qontainer<T>;
  private:
    T* iPtr;
    iterator(T*);
  public:
    T& operator *();
    T* operator ->();
    bool operator ==(const iterator&) const;
    bool operator !=(const iterator&) const;
    iterator& operator ++();
    iterator& operator --();
    iterator& operator -(unsigned int);
    iterator& operator +(unsigned int);
  };

  // Class constIterator
  class constIterator{
    friend class Qontainer<T>;
  private:
    const T* ciPtr;
    constIterator(T*);
  public:
    const T& operator *();
    const T* operator ->();
    bool operator==(const constIterator&) const;
    bool operator!= (const constIterator&) const;
    constIterator& operator ++();
    constIterator& operator --();
    constIterator& operator -(unsigned int);
    constIterator& operator +(unsigned int);
  };

  // Costruttori
  Qontainer(unsigned int s = 1);
  Qontainer(const T&, unsigned int s = 1);
  Qontainer(const Qontainer<T>&);
  ~Qontainer();

  // Metodi get
  // Ritorna la capacita' del vettore
  unsigned int size() const
  {
      return capacity;
  }

  // Ritorna il numero di elementi nel vettore
  unsigned int count() const
  {
      return elements;
  }

  // Ritorna se il numero di elementi e' 0
  bool isEmpty() const
  {
      if (!elements)
          return true;
  }

  // Metodi erase
  void erase(unsigned int x, unsigned int y=0);     // Cancella tutti gli oggetti dati due limiti
  void clear();                                     // Cancella tutti gli elementi dal Qontainer
  void removeAt(int);
  void erase(T);


  T& at(unsigned int) const;           // Ritorna l'oggetto all'indice x

  iterator begin() const;             // Ritorna iterator iniziale
  iterator end() const;               // Ritorna iterator finale
  constIterator c_begin() const;     // Ritorna iterator const iniziale
  constIterator c_end() const;       // Ritorna iterator const finale


  T& front();                         // Restituisce il primo oggetto di Qontainer
  T& back();                          // Restituisce l'ultimo oggetto di Qontainer
  void push_back(const T&);           // Aggiunge un oggetto alla fine di Qontainer
  void pop_back();                    // Rimuove un oggetto dalla fine di Qontainer

  Qontainer<T>& operator=(const Qontainer<T>&);
  bool operator==(const Qontainer<T>&) const;
  T& operator[](unsigned int);
};


template<typename T>
T& Qontainer<T>::operator[](unsigned int index){
    return ptr[index];
}


// Costruttori
template <typename T>
Qontainer<T>::Qontainer(unsigned int s)
  : capacity(s), elements(0), ptr(new T[s])
{

}

template <typename T>
Qontainer<T>::Qontainer(const T& t, unsigned int s)
  : capacity(s), elements(0), ptr(new T[s])
{
  for (unsigned int i=0; i<elements; ++i)
    ptr[i] = t;
}

template <typename T> // di copia
Qontainer<T>::Qontainer(const Qontainer<T>& container)
  : capacity(container.capacity), elements(container.elements), ptr(container.ptr)
{
  for (unsigned int i=0; i<elements; ++i)
    ptr[i] = container.ptr[i];
}

template <typename T> // distruttore
Qontainer<T>::~Qontainer()
{
  if (ptr) delete[] ptr;
}

// erase
template <typename T>
void Qontainer<T>::erase(T other)
{
    unsigned int index=0;
    for (auto it = begin(); (*it)!= other && it!=end(); index++, ++it);
    return erase(index);
}

template <typename T>
void Qontainer<T>::erase(unsigned int x, unsigned int y)
{
  if (x > capacity || y > capacity)
    throw "One or two indexes chosen are out of bounds.";
  if (y) {
    if (x > y) {
        unsigned int tmp = y;
        y = x;
        x = tmp;
      }
  }
  else y = x;
  unsigned int c = x;
  unsigned int i = y+1;

  while (i < elements) {
      ptr[c] = ptr[i];
      c=i;
      i++;
    }
  elements = elements - (y - x + 1);
}

template <typename T>
void Qontainer<T>::removeAt(int indx)
{
  if (indx > elements-1)
      throw std::out_of_range("The index is out of range!");
  for (unsigned int i = indx; i < elements-1; i++ )
      ptr[i]= ptr[i+1];
  elements--;
}

template <typename T>
void Qontainer<T>::clear()
{
  elements = 0;
  for(unsigned int i = 0; i < elements; i++)
    ptr[i].~T();
}

template <typename T>
T& Qontainer<T>::front()
{
  return ptr[0];
}

template <typename T>
T& Qontainer<T>::back()
{
  return ptr[elements-1];
}

template <typename T>
void Qontainer<T>::push_back(const T& obj)
{
  if (elements == capacity || capacity == 0){ // se il numero di oggetti e' uguale alla capacita' del Qontainer incremento di 5 la capacita'
      unsigned int newSize = capacity + 5;
      T* newPtr = new T[newSize];
      for(unsigned int i = 0; i < elements; ++i){
          newPtr[i] = ptr[i];
        }
      capacity = newSize;
      delete ptr;
      ptr = newPtr;
    }
  ptr[elements++] = obj;
}

template <typename T>
void Qontainer<T>::pop_back()
{
  if(elements > 0)
      elements--;
  else
      elements = 0;
}

template <typename T>
T& Qontainer<T>::at(unsigned int index) const
{
    if(index < 0 || index > elements-1)
        throw std::out_of_range("The index is out of bound");
    return ptr[index];
}

// iterator
template<class T>
Qontainer<T>::iterator::iterator(T* t):iPtr(t)
{

}

template <typename T>
typename Qontainer<T>::iterator Qontainer<T>::begin() const
{
    return iterator(ptr);
}

template <typename T>
typename Qontainer<T>::iterator Qontainer<T>::end() const
{
  return iterator(ptr + elements);
}

// constIterator
template<class T>
Qontainer<T>::constIterator::constIterator(T* t):ciPtr(t)
{

}

template <typename T>
typename Qontainer<T>::constIterator Qontainer<T>::c_begin() const
{
  return constIterator(ptr);
}

template <typename T>
typename Qontainer<T>::constIterator Qontainer<T>::c_end() const
{
  return constIterator(ptr + elements);
}

// operator
template <typename T>
Qontainer<T> &Qontainer<T>::operator=(const Qontainer<T>& container)
{
  if (this != &container) {
      delete[] ptr;
      capacity = container.capacity;
      elements = container.elements;
      for(unsigned int i=0; i<elements; ++i)
        ptr[i] = container.ptr[i];
    }
  return *this;
}

template< typename T>
bool Qontainer<T>::iterator::operator!=(const iterator& ite) const
{
    return iPtr != ite.iPtr;
}
template <typename T>
bool Qontainer<T>::iterator::operator==(const iterator& ite) const
{
    return iPtr == ite.iPtr;
}

template <typename T>
T& Qontainer<T>::iterator::operator*()
{
  return *iPtr;
}

template <typename T>
T* Qontainer<T>::iterator::operator->()
{
  return iPtr;
}

template< typename T>
bool Qontainer<T>::constIterator::operator!=(const constIterator& ite) const
{
    return ciPtr!=ite.ciPtr;
}

template <typename T>
bool Qontainer<T>::constIterator::operator==(const constIterator& ite) const
{
    return ciPtr==ite.ciPtr;
}

template <typename T>
const T& Qontainer<T>::constIterator::operator*()
{
  return *ciPtr;
}

template <typename T>
const T* Qontainer<T>::constIterator::operator->()
{
  return ciPtr;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator --()
{
    if (iPtr)
        iPtr--;
    return *this;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator ++()
{
    if (iPtr)
        iPtr++;
    return *this;
}

template <typename T>
typename Qontainer<T>::constIterator& Qontainer<T>::constIterator::operator --()
{
    if (ciPtr)
        ciPtr--;
    return *this;
}

template <typename T>
typename Qontainer<T>::constIterator& Qontainer<T>::constIterator::operator ++()
{
    if (ciPtr)
        ciPtr++;
    return *this;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator-(unsigned int i)
{
    if (iPtr)
        iPtr = iPtr-i;
    return *this;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator+(unsigned int i)
{
    if (iPtr)
        iPtr = iPtr+i;
    return *this;
}

template <typename T>
typename Qontainer<T>::constIterator& Qontainer<T>::constIterator::operator-(unsigned int i)
{
    if (ciPtr)
        ciPtr = ciPtr-i;
    return *this;
}
template <typename T>
typename Qontainer<T>::constIterator& Qontainer<T>::constIterator::operator+(unsigned int i)
{
    if (ciPtr)
        ciPtr = ciPtr+i;
    return *this;
}

#endif // QONTAINER_H

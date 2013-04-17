#ifndef STRUKTURY_HPP_INCLUDED
#define STRUKTURY_HPP_INCLUDED

#include <iostream>
#include <string>
#include <utility>
#include "datagodz.hpp"

typedef std::pair<DataGodz, std::string> Para;

class Lista {
  protected:

    class Wezel {
      public:
        Para wartosc;
        Wezel *nast;

      public:
        Wezel(Para wart, Wezel *nast = 0);
        Wezel(const Wezel &other);

      public:
        Wezel *wstaw(Para parka, int poz);
        Wezel *usun(int poz);
    };

  protected:
    Wezel *pocz;
    int dlugosc;

  public:
    Lista();
    Lista(const Lista &other);
    ~Lista();
    Lista & operator = (const Lista &lista);

  public:
    int wielkosc() const;
    void wstaw(Para wart, int pozycja);
    void usun(int pozycja);
    Para& operator [](int pozycja);
    friend std::ostream& operator << (std::ostream &out, const Lista &lista);
  friend std::istream& operator >> (std::istream &in, Lista &lista);
};

class Kolejka : protected Lista {
  public:
	Kolejka();
	Kolejka(const Kolejka &other);
	~Kolejka();

  public:
	void dodaj(Para other);
	Para usunPierwszy();

  public:
	Kolejka& operator= (const Kolejka& copy);
	friend std::ostream& operator<< (std::ostream &out, const Kolejka& kolejka);
	friend std::istream& operator>> (std::istream &in, Kolejka &kolejka);
};

#endif // STRUKTURY_HPP_INCLUDED

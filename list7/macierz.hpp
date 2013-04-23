#ifndef MACIERZ_HPP_INCLUDED
#define MACIERZ_HPP_INCLUDED

#include "wyjatek.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class Macierz {
  private:
    int rozmiar;
    double** macierz;

  public:
    Macierz(int wielkosc) throw(rozmiary_nie_pasuja);
    Macierz(const Macierz &other);
    ~Macierz();
    Macierz & operator = (const Macierz &m);

  public:
    friend Macierz operator + (const Macierz &m1, const Macierz &m2) throw(rozmiary_nie_pasuja);
    friend Macierz operator - (const Macierz &m1, const Macierz &m2) throw(rozmiary_nie_pasuja);
    friend Macierz operator * (const Macierz &m1, const Macierz &m2) throw(rozmiary_nie_pasuja);
    friend Macierz operator * (const Macierz &m, const double skalar) throw();
    friend Macierz operator ~ (const Macierz &m) throw();

  public:
    Macierz& operator += (const Macierz &m) throw(rozmiary_nie_pasuja);
    Macierz& operator -= (const Macierz &m) throw(rozmiary_nie_pasuja);
    Macierz& operator *= (const Macierz &m) throw(rozmiary_nie_pasuja);
    Macierz& operator *= (double skalar) throw();
    double pobierzElement(int pierwsza_wspolrzedna, int druga_wspolrzedna) const throw(wspolrzedne_bledne);
    void ustawElement(int pierwsza_wspolrzedna, int druga_wspolrzedna, double wartosc) throw(wspolrzedne_bledne);

  public:
    friend std::istream& operator >> (std::istream &we, Macierz &m);
    friend std::ostream& operator << (std::ostream &wy, const Macierz &m);
};

#endif // MACIERZ_HPP_INCLUDED

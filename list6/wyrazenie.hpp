#ifndef WYRAZENIE_HPP_INCLUDED
#define WYRAZENIE_HPP_INCLUDED

#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <sstream>
#include <cstdlib>

class Wyrazenie {
  public:
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
};

class Liczba : public Wyrazenie {
  private:
    double liczba;

  public:
    Liczba(double wartosc);
    double oblicz();
    std::string opis();
};

class Zmienna : public Wyrazenie {
  private:
    std::string nazwa;
    static std::vector< std::pair<std::string, double> > wartosci;
  public:
    Zmienna(std::string nazwa);
    double oblicz();
    std::string opis();
    static void dodaj(std::string nazwa, double wartosc);
    static double& pobierzWartosc(std::string nazwa);
};

#endif // WYRAZENIE_HPP_INCLUDED

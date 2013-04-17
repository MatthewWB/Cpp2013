#ifndef OPERATOR2ARG_HPP_INCLUDED
#define OPERATOR2ARG_HPP_INCLUDED

#include "operator1arg.hpp"

class Operator2Arg : public Operator1Arg {
  protected:
    Wyrazenie *arg2;
    Operator2Arg(Wyrazenie *wyr1, Wyrazenie *wyr2);
    virtual ~Operator2Arg();
};

class Dodaj : public Operator2Arg {
  private:
    double oblicz();
  public:
    Dodaj(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};


class Odejmij : public Operator2Arg {
  private:
    double oblicz();
  public:
    Odejmij(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};

class Mnozenie : public Operator2Arg {
  private:
    double oblicz();
  public:
    Mnozenie(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};

class Dziel : public Operator2Arg {
  private:
    double oblicz();
  public:
    Dziel(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};

class Logarytm : public Operator2Arg {
  private:
    double oblicz();
  public:
    Logarytm(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};

class Potega : public Operator2Arg {
  private:
    double oblicz();
  public:
    Potega(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};

class Modulo : public Operator2Arg {
  private:
    double oblicz();
  public:
    Modulo(Wyrazenie *wyr1, Wyrazenie *wyr2);
    std::string opis();
};

#endif // OPERATOR2ARG_HPP_INCLUDED

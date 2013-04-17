#ifndef OPERATOR1ARG_HPP_INCLUDED
#define OPERATOR1ARG_HPP_INCLUDED

#include "wyrazenie.hpp"

class Operator1Arg : public Wyrazenie {
  protected:
    Wyrazenie *arg1;
    Operator1Arg(Wyrazenie *wyr);
    virtual ~Operator1Arg();
};

class PrzecZnak : public Operator1Arg {
  private:
    double oblicz();
  public:
    PrzecZnak(Wyrazenie *arg);
    std::string opis();
};

class WartBezw : public Operator1Arg {
  private:
    double oblicz();
  public:
    WartBezw(Wyrazenie *arg);
    std::string opis();
};

class Sin : public Operator1Arg {
  private:
    double oblicz();
  public:
    Sin(Wyrazenie *arg);
    std::string opis();
};


class Cos: public Operator1Arg {
  private:
    double oblicz();
  public:
    Cos(Wyrazenie *arg);
    std::string opis();
};

#endif // OPERATOR1ARG_HPP_INCLUDED

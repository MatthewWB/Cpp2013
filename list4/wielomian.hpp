#ifndef WIELOMIAN_HPP_INCLUDED
#define WIELOMIAN_HPP_INCLUDED

#include <iostream>
#include <string>

class Wielomian {
  private:
    int n;
    double *a;

  public:
    Wielomian(int st, double wsp = 1.0);
    Wielomian(int st, double wsp[]);
    Wielomian(const Wielomian &w);
    Wielomian & operator = (const Wielomian &w);
    ~Wielomian();

  public:
    Wielomian& operator +=(const Wielomian& w);
    Wielomian& operator -=(const Wielomian& w);
    Wielomian& operator *=(const Wielomian& w);
    Wielomian& operator *=(const double x);

  public:
    double operator() (double x) const;
    double& operator[] (int n);
    double operator[] (int n) const;

  public:
    friend std::istream & operator >> (std::istream &we, Wielomian &w);
    friend std::ostream & operator << (std::ostream &wy, const Wielomian &w);
    friend Wielomian operator +(const Wielomian& w1, const Wielomian& w2);
    friend Wielomian operator -(const Wielomian& w1, const Wielomian& w2);
    friend Wielomian operator *(const Wielomian& w1, const Wielomian& w2);
    friend Wielomian operator *(const Wielomian& w, const double stala);
};

#endif // WIELOMIAN_HPP_INCLUDED

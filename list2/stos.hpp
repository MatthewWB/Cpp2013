#ifndef STOS_H_INCLUDED
#define STOS_H_INCLUDED

class Stos {
 private:
    int ile;
    double *x;

 public:
    const int rozmiar;

 public:
    Stos();
    Stos(int wielkosc);
    Stos(const Stos &other);
    ~Stos();
    double sprawdz();
    int zapelnienie();
    double sciagnij();
    void wloz(double a);
};

#endif // STOS_H_INCLUDED

#ifndef KOLO_H_INCLUDED
#define KOLO_H_INCLUDED

class kolo {
  public:
    double r;
    static const double pi = 3.14;
    punkt *srodek;

    void przesun(double a, double b);
    double pole_powierzchni();
    kolo(double s, punkt *center);
};

#endif // KOLO_H_INCLUDED

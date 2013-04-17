#include <string>
#include "punkt.h"
#include "kolo.h"

void kolo::przesun(double a, double b) {
    srodek->przesun(a, b);
}

double kolo::pole_powierzchni() {
    return r * r * pi;
}

kolo::kolo(double promien, punkt *punktor) {
    srodek = punktor;
    r = promien;
    if (r <= 0.0) throw std::string("niedodatni promien kola");
}

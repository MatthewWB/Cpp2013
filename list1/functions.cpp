#include <cmath>

#include "punkt.h"
#include "kolo.h"

bool punkt_wspolny(kolo klasa, punkt pkt) {
    double odleglosc = sqrt((pkt.x - klasa.srodek->x) * (pkt.x - klasa.srodek->x) +
                            (pkt.y - klasa.srodek->y) * (pkt.y - klasa.srodek->y));
    return odleglosc <= klasa.r;
}

bool punkty_wspolne(kolo pierwsze, kolo drugie) {
    double odleglosc = sqrt((drugie.srodek->x - pierwsze.srodek->x) * (drugie.srodek->x - pierwsze.srodek->x) +
                            (drugie.srodek->y - pierwsze.srodek->y) * (drugie.srodek->y - pierwsze.srodek->y));
    return odleglosc <= pierwsze.r + drugie.r;
}

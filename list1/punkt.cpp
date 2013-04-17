#include "punkt.h"

punkt::punkt(double a, double b) {
    x = a;
    y = b;
}

void punkt::przesun(double a, double b) {
    x += a;
    y += b;
}

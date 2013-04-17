#include "wielomian.hpp"

Wielomian::Wielomian(int st, double wsp) {
    if(n < 0)
        throw std::string("Nie mozna utworzyc ujemnego wielomianu");
    n = st;
    a = new double[st + 1];
    a[st + 1] = wsp;
}

Wielomian::Wielomian(int st, double wsp[]) {
    if(n < 0)
        throw std::string("Nie mozna utworzyc ujemnego wielomianu");

    n = st;
    a = new double[st + 1];

    if(st != 0 && wsp[st] == 0)
        throw std::string("Nie mozna ustawic 0 przy najwyzszej potedze.");

    for(int i = 0; i <= st; i++)
        a[i] = wsp[i];
}

Wielomian::~Wielomian() {
    delete[] a;
}

Wielomian::Wielomian(const Wielomian &w) {
    n = w.n;
    a = new double[n + 1];

    for(int i = 0; i <= n; i++)
        a[i] = w.a[i];
}

Wielomian& Wielomian::operator= (const Wielomian &w) {
    if(this == &w)
        return *this;

    if(!a) delete[] a;
    n = w.n;
    a = new double[n + 1];

    for(int i = 0; i <= n; i++)
        a[i] = w.a[i];

    return *this;
}

Wielomian& Wielomian::operator +=(const Wielomian& w) {
    *this = *this + w;
    return *this;
}

Wielomian& Wielomian::operator -=(const Wielomian& w) {
    *this = *this - w;
    return *this;
}

Wielomian& Wielomian::operator *=(const Wielomian& w) {
    *this = *this * w;
    return *this;
}

Wielomian& Wielomian::operator *=(const double x) {
    *this = *this * x;
    return *this;
}

double&  Wielomian::operator[] (int i) {
    if(i < 0 || i > n)
        throw std::string("Wielomian nie ma tylu wspolczynnikow");
    return a[i];
}

double Wielomian::operator[] (int i) const {
    if(i < 0 || i > n)
        throw std::string("Wielomian nie ma tylu wspolczynnikow");

    return a[i];
}

std::istream & operator >> (std::istream &we, Wielomian &w) {
    for(int i = 0; i <= w.n; i++)
        we >> w.a[w.n - i];
    return we;
}

std::ostream& operator << (std::ostream &wy, const Wielomian &w) {
    for(int i = w.n; i >= 0; i--) {
        if(w.a[i] > 0 && i != w.n) wy << "+";
        if(w.a[i] != 0) {
            wy << w.a[i];
            if(i == 1) wy << "x";
            else if(i != 0) wy << "x^" << i;
        }
        if(w.n == 0 && w.a[0] == 0) wy << "0";
    }
    return wy << std::endl;
}

/*
std::ostream & operator << (std::ostream &wy, const Wielomian &w){
    for(int i = 0; i <= w.n; i++) {
        if(w.a[i] != 0 && w.n - i != 0) wy << w.a[i] << "x^" << w.n - i;
        if((i != 0 || w.a[w.n] > 0) && w.n - i != 0 && w.a[w.n + 1] != 0) wy << " + ";
        if(i == w.n) wy << w.a[i];
    }
    wy << std::endl;
    return wy;
}
*/

double Wielomian::operator() (double x) const {
    double value = 0;

    for(int i = n; i >= 0; i--)
        value = value * x + a[i];

    return value;
}

Wielomian operator +(const Wielomian& w1, const Wielomian& w2) {
    int st = (w1.n <= w2.n) ? w2.n : w1.n;

    if(w1.n == w2.n) {
        for(int i = w1.n; i > 0 ; i--) {
            if(w1.a[i] + w2.a[i] != 0)
                break;
            st--;
        }
    }

    double wsp[st + 1];

    for(int i = 0; i <= st; i++)
        wsp[i] = 0;

    for(int i = 0; i <= st; i++) {
        if(i <= w1.n)
            wsp[i] += w1.a[i];
        if(i <= w2.n)
            wsp[i] += w2.a[i];
    }

    /*
    for(int i = st; i >= 0; i--) {
        if(w1.n >= st)
            wsp[i] += w1.a[i];
        if(w2.n >= st)
            wsp[i] += w2.a[i];
    }
    */
    return Wielomian(st, wsp);
}

Wielomian operator -(const Wielomian& w1, const Wielomian& w2) {
    int st = (w1.n <= w2.n) ? w2.n : w1.n;

    if(w1.n == w2.n) {
        for(int i = w1.n; i > 0 ; i--) {
            if(w1.a[i] - w2.a[i] != 0)
                break;
            st--;
        }
    }

    double wsp[st + 1];

    for(int i = 0; i <= st; i++)
        wsp[i] = 0;

    for(int i = 0; i <= st; i++) {
        if(i <= w1.n)
            wsp[i] += w1.a[i];
        if(i <= w2.n)
            wsp[i] -= w2.a[i];
    }

    return Wielomian(st, wsp);
}

Wielomian operator *(const Wielomian& w1, const Wielomian& w2) {
    int st = w1.n + w2.n;
    double *a_new = new double[st + 1];

    for(int i = 0; i <= st; i++)
        a_new[i] = 0;

    for (int i = 0; i <= w1.n; i++)
        for (int j = 0; j <= w2.n; j++)
            a_new[i + j] += w1.a[i] * w2.a[j];

    return Wielomian(st, a_new);
}

Wielomian operator *(const Wielomian& w, const double stala) {
    double *a_new = (stala != 0) ? new double[w.n + 1] : new double[1];

    if(stala == 0) return Wielomian(0, a_new);

    for(int i = 0; i <= w.n; i++)
        a_new[i] = 0;

    for(int i = 0; i <= w.n; i++)
        a_new[i] += w.a[i] * stala;

    return Wielomian(w.n, a_new);
}

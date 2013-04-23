#include "macierz.hpp"

/* konstruktory i destruktory */

Macierz::Macierz(int wielkosc) throw(rozmiary_nie_pasuja): rozmiar(wielkosc) {
    if(rozmiar <= 0)
        throw rozmiary_nie_pasuja("Co to za rozmiar?");

    macierz = new double *[rozmiar];
    for(int i = 0; i < rozmiar; i++)
        macierz[i] = new double[rozmiar];

    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++)
            if(i == j)
                macierz[i][j] = 1;
            else
                macierz[i][j] = 0;
}

Macierz::~Macierz() {
    for(int i = 0; i < rozmiar; i++)
        delete [] macierz[i];
    delete[] macierz;
}

Macierz::Macierz(const Macierz &other) : rozmiar(other.rozmiar) {
    macierz = new double *[rozmiar];

    for(int i = 0; i < rozmiar; i++)
        macierz[i] = new double[rozmiar];

    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++)
            macierz[i][j] = other.macierz[i][j];
}

/* operatory */

Macierz& Macierz::operator= (const Macierz &m) {
    if(this == &m)
        return *this;

    for(int i = 0; i < rozmiar; i++)
        delete [] macierz[i];
    delete[] macierz;

    rozmiar = m.rozmiar;
    macierz = new double * [rozmiar];

    for(int i = 0; i < rozmiar; i++)
        macierz[i] = new double[rozmiar];


    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++)
            macierz[i][j] = m.macierz[i][j];

  return *this;
}

Macierz operator + (const Macierz &m1, const Macierz &m2) throw(rozmiary_nie_pasuja) {
    Macierz suma = Macierz(m1);
    suma += m2;

    return suma;
}

Macierz& Macierz::operator += (const Macierz &m) throw(rozmiary_nie_pasuja){
    if(m.rozmiar != this->rozmiar)
        throw rozmiary_nie_pasuja("nie moge dodac dwoch roznych macierzy");

    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++)
            macierz[i][j] += m.macierz[i][j];

    return *this;
}

Macierz operator - (const Macierz &m1, const Macierz &m2) throw(rozmiary_nie_pasuja){
    Macierz roznica = Macierz(m1);
    roznica -= m2;

    return roznica;
}

Macierz& Macierz::operator -= (const Macierz &m) throw(rozmiary_nie_pasuja){
    if(m.rozmiar != this->rozmiar)
         throw rozmiary_nie_pasuja("nie moge odjac, bo sa rozne rozmiary");

    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++)
            macierz[i][j] -= m.macierz[i][j];

    return *this;
}

Macierz operator * (const Macierz &m, const double skalar) throw(){
    Macierz mnozenie = Macierz(m);
    mnozenie *= skalar;
    return mnozenie;
}

Macierz operator * (const Macierz &m1, const Macierz &m2) throw(rozmiary_nie_pasuja){
    Macierz mnozenie = Macierz(m1);
    mnozenie *= m2;

    return mnozenie;
}

Macierz operator ~ (const Macierz &m) throw() {
    Macierz transpozycja = Macierz(m.rozmiar);

    for(int i = 0; i < m.rozmiar; i++)
        for(int j = 0; j < m.rozmiar; j++)
            transpozycja.macierz[j][i] = m.macierz[i][j];

    return transpozycja;
}

Macierz& Macierz::operator *= (const Macierz &m) throw(rozmiary_nie_pasuja) {
    if(rozmiar != m.rozmiar)
        throw rozmiary_nie_pasuja("rozmiary sie nie zgadzaja, nie pomnoze");

    Macierz mnozenie = Macierz(*this);
    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++) {
            macierz[i][j] = 0;
            for(int k = 0; k < rozmiar; k++)
                macierz[i][j] += mnozenie.macierz[i][k] * m.macierz[k][j];
        }

    return *this;
}

Macierz& Macierz::operator *= (double skalar) throw() {
    for(int i = 0; i < rozmiar; i++)
        for(int j = 0; j < rozmiar; j++)
            macierz[i][j] *= skalar;

    return *this;
}

std::istream& operator >> (std::istream &we, Macierz &m) {
    for(int i = 0; i < m.rozmiar; i++)
        for(int j = 0; j < m.rozmiar; j++)
            we >> m.macierz[i][j];
    return we;
}

std::ostream& operator << (std::ostream &wy, const Macierz &m) {
    for(int i = 0; i < m.rozmiar; i++) {
        for(int j = 0; j < m.rozmiar; j++)
            wy << std::setw(5) << m.macierz[i][j];
        wy << std::endl;
    }
    return wy;
}

double Macierz::pobierzElement(int x, int y) const throw (wspolrzedne_bledne) {
    if(x > rozmiar || y > rozmiar || y <= -1 || x <= -1 )
        throw wspolrzedne_bledne("Brzydkie wspolrzedne");
    return macierz[x][y];
}

void Macierz::ustawElement(int x, int y, double wartosc) throw (wspolrzedne_bledne) {
    if(x > rozmiar || y > rozmiar || y <= -1 || x <= -1 )
        throw wspolrzedne_bledne("Brzydkie wspolrzedne");
    macierz[x][y] = wartosc;
}

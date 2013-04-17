#include "stos.hpp"
#include <iostream>

Stos::Stos(int wielkosc) : rozmiar(wielkosc) {
    if(wielkosc <= 0) throw std::string("niedodatnia wielkosc stosu \n");
    x = new double[rozmiar];
    ile = 0;
}

Stos::~Stos() {
    delete[] x;
}

Stos::Stos() : rozmiar(1) {
    x = new double[rozmiar];
    ile = 0;
}

int Stos::zapelnienie() {
    return ile;
}

Stos::Stos(const Stos &other) : rozmiar(other.rozmiar){
    int i = 0;
    ile = other.ile;
    x = new double[rozmiar];

    for(i = 0; i < rozmiar; i++)
        x[i] = other.x[i];
}

double Stos::sprawdz() {
    if(ile == 0) throw std::string("nic nie ma na stosie \n");
    return x[ile - 1];
}

void Stos::wloz(double a) {
    if(rozmiar <= ile)
        throw std::string("przepelnienie stosu. \n");
    else {
        x[ile] = a;
        ile++;
    }
}

double Stos::sciagnij() {
    if(ile <= 0) throw std::string("nie mozna sciagnac ze stosu pustego elementu \n");
    ile--;
    return x[ile];
}

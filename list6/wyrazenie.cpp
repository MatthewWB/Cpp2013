#include "wyrazenie.hpp"

using namespace std;

vector<pair<string,double> > Zmienna::wartosci;

/* klasa Zmienna */

Zmienna::Zmienna(string nazwa) {
    this->nazwa = nazwa;
}

double Zmienna::oblicz() {
    return pobierzWartosc(nazwa);
}

double& Zmienna::pobierzWartosc(string nazwa) {
    for(unsigned int i = 0; i < wartosci.size(); i++)
        if(wartosci[i].first == nazwa)
            return wartosci[i].second;
    throw string ("brak zmiennej");
}

void Zmienna::dodaj(string nazwa, double wartosc) {
    int rozmiar = wartosci.size();
    for(int i = 0; i < rozmiar; i++)
        if(wartosci[i].first == nazwa) {
            wartosci[i].second = wartosc;
            return;
        }
    pair<string, double> para(nazwa, wartosc);
    wartosci.push_back(para);
}



string Zmienna::opis() {
    return this->nazwa;
}

/* klasa Liczba */

Liczba::Liczba(double wartosc) {
    liczba = wartosc;
}

double Liczba::oblicz() {
    return liczba;
}

string Liczba::opis() {
    ostringstream strs;
  strs << this->liczba;
	return strs.str();
}

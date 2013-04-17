#include "struktury.hpp"

/* klasa Wezel */

Lista::Wezel::Wezel(Para wart, Wezel* nastepny) : wartosc(wart), nast(nastepny) {}

Lista::Wezel::Wezel(const Wezel &other) : wartosc(other.wartosc), nast(other.nast) {}

Lista::Wezel*Lista::Wezel::wstaw(Para parka, int poz) {
    if(poz == 0) return new Wezel(parka);
    nast = nast->wstaw(parka, --poz);
    return this;
}

Lista::Wezel*Lista::Wezel::usun(int poz) {
    if(poz == 0) {
        Wezel *temp = nast;
        delete this;
        return temp;
    }
    nast = nast->usun(--poz);
    return this;
}


/* klasa Lista */

Lista::Lista() {
    pocz = NULL;
    dlugosc = 0;
}

Lista::~Lista() {
    while(pocz != NULL) {
        Wezel *nast = pocz->nast;
        delete pocz;
        pocz = nast;
    }
}

Lista::Lista(const Lista &other) {
    dlugosc = other.dlugosc;
    pocz = new Wezel(other.pocz->wartosc);

    Wezel *obecny = pocz;
    Wezel *obecnyWez = other.pocz->nast;

    for(int i = 0; i < dlugosc - 1; i++) {
        obecny->nast = new Wezel(obecnyWez->wartosc);
        obecny = obecny->nast;
        obecnyWez = obecnyWez->nast;
    }
}

Lista& Lista::operator = (const Lista &lista) {
    if(this == &lista)
        return *this;

    int n = 1;
    dlugosc = lista.dlugosc;

    if(dlugosc == 0) {
        pocz = NULL;
        return *this;
    }

    pocz = new Wezel(*lista.pocz);

    for(Wezel *wez = lista.pocz->nast; wez != NULL; wez = wez->nast)
        pocz->wstaw(wez->wartosc, n++);

    return *this;
}

int Lista::wielkosc() const {
    return dlugosc;
}

void Lista::wstaw(Para wart, int poz) {
    if(poz < 0 || poz > dlugosc)
        throw std::string("niepoprawna pozycja");

    pocz = pocz->wstaw(wart, poz);
    dlugosc++;
}

void Lista::usun(int poz) {
    if(poz < 0 || poz > dlugosc)
        throw std::string("niepoprawna pozycja");

  if(dlugosc == 0)
    throw std::string("lista jest pusta");

    pocz = pocz->usun(poz);
    dlugosc--;
}

Para& Lista::operator[](int poz) {
    if(poz < 0 || poz > dlugosc)
        throw std::string("niepoprawna pozycja");
    Wezel *wez = pocz;

    for(int i = 0; i < poz; i++)
        wez = wez->nast;

    return wez->wartosc;
}

std::istream& operator>> (std::istream &in, Lista &lista) {
    int dzien, miesiac, rok, godzina, minuta, sekunda;
    std::string temp;

  in >> dzien >> miesiac >> rok >> godzina >> minuta >> sekunda >> temp;
	DataGodz *obj = new DataGodz(godzina, minuta, sekunda, dzien, miesiac, rok);
	lista.wstaw(Para(*obj, temp), lista.wielkosc());

    return in;
}


std::ostream& operator << (std::ostream &out, const Lista &lista) {
    if(lista.wielkosc() == 0)
        throw std::string("lista jest pusta");

    Lista::Wezel *wez = lista.pocz;
	while(wez) {
        out << wez->wartosc.first.getHour() << " : " << wez->wartosc.first.getMinute() << " : " << wez->wartosc.first.getSecond() << "  ";
        out << "[" << wez->wartosc.first.day << " - "<< wez->wartosc.first.month << " - " << wez->wartosc.first.year << "]"<< std::endl;
		wez = wez->nast;
	}
	return out << std::endl;
}

/* Kolejka */

Kolejka::Kolejka() {
    pocz = NULL;
    dlugosc = 0;
}

Kolejka::Kolejka(const Kolejka &other) {
    dlugosc = 0;
	Wezel *wezel = other.pocz;
	while (wezel) {
		dodaj(wezel->wartosc);
		wezel = wezel->nast;
	}
}

Kolejka::~Kolejka() {
    while(pocz)
        usunPierwszy();
}

Para Kolejka::usunPierwszy() {
    if (!pocz)
        throw std::string("lista jest pusta.");

	Para cpy = pocz->wartosc;
    Wezel *wez = pocz->nast;
	delete pocz;
	pocz = wez;

	return cpy;
}

void Kolejka::dodaj(Para parka) {
    dlugosc++;
    if(pocz == NULL) {
        pocz = new Wezel(parka, 0);
        return;
    }

    if (pocz == NULL || (pocz->wartosc.first >= parka.first) ) {
       Wezel *wez = new Wezel(parka, pocz);
       pocz = wez;
       return;
    }

    Wezel *wezl = pocz;
    while(wezl->nast != NULL && (wezl->nast->wartosc.first < parka.first) )
        wezl = wezl->nast;
    Wezel *wez = new Wezel(parka, wezl->nast);
    wezl->nast = wez;


}

std::istream& operator>> (std::istream& in, Kolejka &kolejka) {
    int dzien, miesiac, rok, godzina, minuta, sekunda;
    std::string temp;

	in >> dzien >> miesiac >> rok >> godzina >> minuta >> sekunda >> temp;
	DataGodz *obj = new DataGodz(godzina, minuta, sekunda, dzien, miesiac, rok);
	kolejka.dodaj(Para(*obj, temp));

    return in;
}

std::ostream& operator << (std::ostream &out, const Kolejka &kolejka) {
    if(kolejka.wielkosc() == 0)
        throw std::string("kolejka jest pusta");

    Kolejka::Wezel *wez = kolejka.pocz;
	while(wez) {
        out << wez->wartosc.first.getHour() << " : " << wez->wartosc.first.getMinute() << " : " << wez->wartosc.first.getSecond() << "  ";
        out << "[" << wez->wartosc.first.day << " - "<< wez->wartosc.first.month << " - " << wez->wartosc.first.year << "]"<< std::endl;
		wez = wez->nast;
	}
	return out << std::endl;
}

#include "operator2arg.hpp"

/* klasa Operator2Arg */

Operator2Arg::Operator2Arg(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator1Arg(wyr1), arg2(wyr2) { }

Operator2Arg::~Operator2Arg() {
    delete this->arg2;
}

/* klasa Dodaj */

double Dodaj::oblicz() {
    return arg1->oblicz() + arg2->oblicz();
}

Dodaj::Dodaj(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Dodaj::opis() {
    return "(" + arg1->opis() + " + " + arg2->opis() + ")";
}

/* klasa Odejmij */

double Odejmij::oblicz() {
    return arg1->oblicz() - arg2->oblicz();
}

Odejmij::Odejmij(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Odejmij::opis() {
    return "(" + arg1->opis() + " - " + arg2->opis() + ")";
}

/* klasa Mnozenie */

double Mnozenie::oblicz() {
    return arg1->oblicz() * arg2->oblicz();
}

Mnozenie::Mnozenie(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Mnozenie::opis() {
    return "(" + arg1->opis() + " * " + arg2->opis() + ")";
}

/* klasa Dzielenie */

double Dziel::oblicz() {
    double arg2Dziel = arg2->oblicz();
    if(arg2Dziel == 0) throw std::string ("nie dziel przez zero");
    return arg1->oblicz() / arg2Dziel;
}

Dziel::Dziel(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Dziel::opis() {
    return "(" + arg1->opis() + ") / (" + arg2->opis() + ")";
}

/* klasa Potega */

double Potega::oblicz() {
    double arg1Potega = arg1->oblicz();
    double arg2Potega = arg2->oblicz();
    if(arg1Potega == 0 && arg2Potega == 0) throw std::string ("nie poteguj zero zerowa");
    return pow(arg1Potega, arg2Potega);
}

Potega::Potega(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Potega::opis() {
    return "(" + arg1->opis() + ") ^ " + arg2->opis() + "";
}

/* klasa Modulo */

double Modulo::oblicz() {
    double arg2Modulo = arg2->oblicz();
    if(arg2Modulo == 0) throw std::string ("drugi argument nie moze byc 0");
    return fmod(arg1->oblicz(), arg2Modulo);
}

Modulo::Modulo(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Modulo::opis() {
    return "(" + arg1->opis() + ") % (" + arg2->opis() + ")";
}

/* klasa Logarytm */

double Logarytm::oblicz() {
    double arg1Logarytm = arg1->oblicz();
    double arg2Logarytm = arg2->oblicz();
    if(arg1Logarytm <= 0 || arg2Logarytm <= 0 || arg1Logarytm == 1)
        throw std::string ("wartosci musza byc dodatnie");
    return log(arg2Logarytm) / log(arg1Logarytm);
}

Logarytm::Logarytm(Wyrazenie *wyr1, Wyrazenie *wyr2) : Operator2Arg(wyr1, wyr2) {}

std::string Logarytm::opis() {
    return "log_(" + arg1->opis() + ") (" + arg2->opis() + ")";
}

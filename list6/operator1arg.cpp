#include "operator1arg.hpp"

/* klasa Operator1Arg */

Operator1Arg::Operator1Arg(Wyrazenie *wyr) : arg1(wyr) { }

Operator1Arg::~Operator1Arg() {
    delete this->arg1;
}

/* klasa PrzecZnak */

double PrzecZnak::oblicz() {
    return arg1->oblicz() * (-1);
}

PrzecZnak::PrzecZnak(Wyrazenie *arg) : Operator1Arg(arg) {}

std::string PrzecZnak::opis() {
    return "-(" + arg1->opis() + ")";
}

/* klasa WartBezw */

double WartBezw::oblicz() {
    return abs(arg1->oblicz());
}

WartBezw::WartBezw(Wyrazenie *arg) : Operator1Arg(arg) {}

std::string WartBezw::opis() {
    return "|" + arg1->opis() + "|";
}

/* klasa Sin */

double Sin::oblicz() {
    return sin(arg1->oblicz());
}

Sin::Sin(Wyrazenie *arg) : Operator1Arg(arg) {}

std::string Sin::opis() {
    return "sin(" + arg1->opis() + ")";
}

/* klasa Cos */

double Cos::oblicz() {
    return cos(this->arg1->oblicz());
}

Cos::Cos(Wyrazenie *arg) : Operator1Arg(arg) { }

std::string Cos::opis() {
    return "cos(" + arg1->opis() + ")";
}

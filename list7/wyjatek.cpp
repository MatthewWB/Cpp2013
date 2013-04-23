#include "macierz.hpp"
#include "wyjatek.hpp"


/* klasa Wyjatek */

rozmiary_nie_pasuja::rozmiary_nie_pasuja(std::string wyjatek) throw() : komunikat(wyjatek) {}

rozmiary_nie_pasuja::rozmiary_nie_pasuja(const rozmiary_nie_pasuja &other) throw() : komunikat(other.komunikat) {}

rozmiary_nie_pasuja::~rozmiary_nie_pasuja() throw() { }

const char* rozmiary_nie_pasuja::what() const throw() {
    return komunikat.c_str();
};

wspolrzedne_bledne::wspolrzedne_bledne(std::string wyjatek) throw() : komunikatBledne(wyjatek) {}

wspolrzedne_bledne::wspolrzedne_bledne(const wspolrzedne_bledne &other) throw() : komunikatBledne(other.komunikatBledne) {}

wspolrzedne_bledne::~wspolrzedne_bledne() throw() { }

const char* wspolrzedne_bledne::what() const throw() {
    return komunikatBledne.c_str();
};

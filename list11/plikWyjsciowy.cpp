#include "plikWyjsciowy.hpp"

namespace obliczenia {

    plikWyjsciowy::plikWyjsciowy(std::string nazwa) {
        this->exceptions(ios_base::badbit | ios_base::failbit);
        this->open(nazwa.c_str(), std::ofstream::trunc);
        if(!this->is_open()) throw std::string("nie mozna otworzyc pliku");
    }

    plikWyjsciowy::~plikWyjsciowy() {
        this->close();
    }

    void plikWyjsciowy::ustawLinie(std::string zmienna) {
        for(unsigned int i = 0; i < zmienna.length(); i++)
            this->put(zmienna[i]);
    }

    void plikWyjsciowy::ustawInt(int param) {
        std::ostringstream paramS;
        paramS << param;
        this->ustawLinie(paramS.str());
    }

    void plikWyjsciowy::ustawDouble(double param) {
        std::ostringstream paramS;
        paramS << param;
        this->ustawLinie(paramS.str());
    }

    void plikWyjsciowy::ustawEndl() {
        this->put('\n');
    }

    plikWyjsciowy & operator << (plikWyjsciowy &wy, char znak) {
        wy.put(znak);
        return wy;
    }

    plikWyjsciowy & operator << (plikWyjsciowy &wy, int liczba) {
        wy.ustawInt(liczba);
        return wy;
    }

    plikWyjsciowy & operator << (plikWyjsciowy &wy, double przec) {
        wy.ustawDouble(przec);
        return wy;
    }

    plikWyjsciowy & operator << (plikWyjsciowy &wy, std::string znak) {
        wy.ustawLinie(znak);
        return wy;
    }

}

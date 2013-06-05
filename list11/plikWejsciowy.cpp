#include "plikWejsciowy.hpp"
#include "plikWyjsciowy.hpp"
#include <iostream>

namespace obliczenia {

    plikWejsciowy::plikWejsciowy(std::string nazwa) {
        this->exceptions(ios_base::badbit | ios_base::failbit);
        this->open(nazwa.c_str(), std::ifstream::in);
        if(!this->is_open()) throw std::string("nie mozna otworzyc pliku");
    }

    plikWejsciowy::~plikWejsciowy() {
        this->close();
    }

    std::string plikWejsciowy::pobierzLinie() {
        std::string linia = "";
        char znak = this->get();
        while(znak != '\n') {
            linia += znak;
            znak = this->get();
        }
        return linia;
    }

    int plikWejsciowy::pobierzInt() {
        int cast;
        static_cast<std::ifstream&>(*this) >> cast;
        return cast;
    }

    double plikWejsciowy::pobierzDouble() {
        double cast;
        static_cast<std::ifstream&>(*this) >> cast;
        return cast;
    }

    plikWejsciowy & operator >> (plikWejsciowy &we, char &znak) {
        znak = we.get();
        return we;
    }

    plikWejsciowy & operator >> (plikWejsciowy &we, int &liczba) {
        liczba = we.pobierzInt();
        return we;
    }

    plikWejsciowy & operator >> (plikWejsciowy &we, double &przec) {
        przec = we.pobierzDouble();
        return we;
    }

    plikWejsciowy & operator >> (plikWejsciowy &we, std::string &znak) {
        znak = we.pobierzLinie();
        return we;
    }

    void zadanieDrugie() {

        std::vector<double> numbers;
        try {
            plikWejsciowy in("test.txt");

            while(!in.eof()) {
                double liczba;
                in >> liczba;
                numbers.push_back(liczba);
            }
        } catch(std::ios_base::failure e) {
          std::cerr << e.what() << std::endl;
        }

        try {
            plikWyjsciowy out("test.txt");
            for(int i = numbers.size() - 1; i >= 0; i--) {
                out << numbers[i];
                out.ustawEndl();
            }

        } catch(std::ios_base::failure e) {
          std::cerr << e.what() << std::endl;
        }

    }

}

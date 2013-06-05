#include <iostream>
#include <fstream>
#include "manipulatory.hpp"

namespace obliczenia {

    /* funkcja maniupulujace */

    std::istream & clearline(std::istream &wejscie) {
        while(wejscie.get() != '\n' && !wejscie.eof());
        return wejscie;
    }

    std::ostream & comma(std::ostream &wyjscie) {
        return wyjscie << ",";
    }

    std::ostream & colon(std::ostream &wyjscie) {
        return wyjscie << ":";
    }

    /* klasa Ignore */

    ignore::ignore(int param) : parametr(param) {}

    std::istream & operator >> (std::istream &input, const ignore &op) {
        int zmienna = 1;
        while(input.get() != '\n' && !input.eof() && zmienna < op.parametr) zmienna++;
        return input;
    }

    /* klasa Index */

    index::index(int paramX, int paramY) : zmiennaX(paramX), zmiennaY(paramY) {}

    std::ostream & operator << (std::ostream &wyjscie, const index &in) {
        wyjscie << "[" << std::setw(in.zmiennaY) << std::right << in.zmiennaX << "]";
        return wyjscie;
    }

    /* sortowanie babelkowe do pliku testowego */

    void babelekSort(std::vector<std::pair<std::string, int> >& tekst) {
        for(unsigned i = 0; i < tekst.size(); i++)
        for(unsigned j = 0; j < tekst.size() - 1; j++)
            if(tekst[j].first < tekst[j + 1].first)
                std::swap(tekst[j], tekst[j + 1]);
    }

    void zadaniePierwsze() {
      std::vector< std::pair<std::string, int> > tekst;
      std::ifstream is("test2.txt");

      std::string linia;
      for(int i = 0; getline(is, linia); i++) {
        tekst.push_back(std::pair<std::string,int>(linia, i));

      }

      babelekSort(tekst);
      for(std::vector< std::pair<std::string, int> >::iterator it = tekst.begin(); it != tekst.end(); it++)
        std::cout << index((*it).second, 1) << (*it).first << std::endl;
    }

}

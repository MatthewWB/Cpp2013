#include <iostream>
#include <string>
#include "struktury.hpp"

using namespace std;

int main() {

    string txt;

    cout << endl << "Dostepne komendy:" << endl << "[lista] - zostanie wywolana funkcja do testu listy" << endl;
    cout << "[kolejka] - zostanie wywolana funkcja do test kolejki opierajaca sie na liscie" << endl << "[koniec] - konczy program" << endl << endl;

    while(1) {
        try {
            cin >> txt;
            if(txt == "koniec") break;

            if(txt == "lista") {
                Lista lista;
                cout << "Wprowadz teraz trzy daty i godziny o nastepujacej strukturze: " << endl;
                cout << "[dzien | miesiac | rok | godzina | minuta | sekunda | nazwa pary]" << endl << endl;
                cin >> lista >> lista >> lista;
                cout << endl << lista;
                cout << "Lista po usunieciu srodkowego elementu: " << endl << endl;
                lista.usun(1);
                cout << lista;
            }

            if(txt == "kolejka") {
                Kolejka kolejka;
                cout << "Wprowadz teraz trzy daty i godziny o nastepujacej strukturze: " << endl;
                cout << "[dzien | miesiac | rok | godzina | minuta | sekunda | nazwa pary]" << endl << endl;
                cin >> kolejka >> kolejka >> kolejka;
                cout << endl << kolejka;
            }

        } catch (string str) {
            cerr << str;
        }
    }

    return 0;
}

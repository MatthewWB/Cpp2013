#include <iostream>
#include <string>
#include "struktury.hpp"

using namespace std;

int main() {

    string txt;

    //DataGodz p = DataGodz(22, 7, 58, 2, 2, 2013);
    //DataGodz q = DataGodz(22, 8, 57, 3, 3, 2013);

    cout << endl << "Dostepne komendy:" << endl << "[lista] - zostanie wywolana funkcja do testu listy" << endl;
    cout << "[kolejka] - zostanie wywolana funkcja do test kolejki opierajaca sie na liscie" << endl << "[koniec] - konczy program" << endl << endl;

    while(1) {
        try {
            cin >> txt;
            if(txt == "koniec") break;

            if(txt == "lista") {
                /* testowanie listy */

                /*Lista test
                test.wstaw(Para(new DataGodz(10, 10, 59, 18, 18, 2013), "p"), 0);
                test.wstaw(Para(new DataGodz(22, 7, 58, 3, 4, 2013), "q"), 1);
                //test.usun(0);
                cin >> test;
                cout << test << endl;
                */

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

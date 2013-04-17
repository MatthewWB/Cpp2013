#include "stos.hpp"
#include <iostream>
#include <string>

using namespace std;

void menu_main(Stos &stos);

int main() {

    int bufor;

        try {
            cout << "Podaj rozmiar stosu do utworzenia , wpisanie [0] wywoluje konstruktor bezparam." << endl;
            cin >> bufor;

            if(bufor == 0)  {
                Stos stos = Stos();
                menu_main(stos);
            }
            else {
                Stos stos = Stos(bufor);
                menu_main(stos);
            }

        } catch(string str) {
            cout << str;
        }
    return 0;
}

void menu_main(Stos &stos) {
    double number;
    string txt;

    cout << endl << "Dostepne komendy:" << endl << "[wloz | liczba] - wklada na stos podana liczbe, wpierw piszem wloz, potem liczbe" << endl;
    cout << "[sprawdz] - zwraca liczbe lezaca na samej gorze stosu" << endl << "[zapelnienie] - zwraca liczbe elementow na stosie" << endl;
    cout << "[sciagnij] - usuwa element z samej gory stosu" << endl << "[koniec] - konczy program" << endl;
    cout << "[kopiuj] - uruchamia konstruktor kopiujacy i usuwa ostatni element ze stosu skopiowanego" << endl << endl;

    while(1) {
        try {
            cin >> txt;
            if(txt == "wloz") {
                cout << "Wprowadz teraz liczbe wprowadzajaca na stos" << endl;
                    cin >> number;
                    stos.wloz(number);
            }
            if(txt == "sciagnij") cout << stos.sciagnij() << endl;
            if(txt == "zapelnienie") cout << stos.zapelnienie() << endl;
            if(txt == "sprawdz") cout << stos.sprawdz() << endl;
            if(txt == "koniec") break;
            if(txt == "kopiuj") {
                Stos stos_dwa = Stos(stos);
                stos_dwa.sciagnij();
                cout << "ostatni element stosu pierwszego " << stos.sprawdz() << "; ostatni element stosu skopiowanego " << stos_dwa.sprawdz() << endl;
            }
        } catch(string str) {
            cout << str;
        }
    }
}

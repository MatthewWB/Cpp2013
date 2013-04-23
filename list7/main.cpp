#include "macierz.hpp"
#include "wyjatek.hpp"

using namespace std;

int main() {

    int wielkosc;
    string txt;

    try {
        /* Macierz pierwsza */
        cout << "Wprowadz wielkosc pierwszej macierzy: " << endl;
        cin >> wielkosc;
        Macierz pierwsza = Macierz(wielkosc);

        cout << "Wprowadz [" << wielkosc  << " x " << wielkosc << "] wartosci " << endl;
        cin >> pierwsza;
        cout << endl << pierwsza << endl;

        /* Macierz druga */
        cout << "Wprowadz wielkosc drugiej macierzy: " << endl;
        cin >> wielkosc;
        Macierz druga = Macierz(wielkosc);

        cout << "Wprowadz [" << wielkosc  << " x " << wielkosc << "] wartosci " << endl;
        cin >> druga;
        cout << endl << druga << endl << endl;

        /* instrukcja */

        cout << endl << "Dostepne komendy:" << endl << "[+] - zostana dodane do siebie macierze podane wyzej" << endl;
        cout << "[+=] - zostana dodane do siebie macierze podane wyzej" << endl << "[-] - zostana odjete do siebie macierze podane wyzej" << endl;
        cout << "[-=] - zostana odjete do siebie macierze podane wyzej" << endl << "[*] - zostana przemnozone macierze podane wyzej" << endl;
        cout << "[*=] - zostana przemnozone macierze podane wyzej" << endl << "[~] - zostanie przeprowadzona transpozycja macierzy pierwszej" << endl;
        cout << "[*s] - zostanie przemnozona pierwsza macierz przez skalar" << endl << "[*=s] - zostanie przemnozona pierwsza macierz przez skalar" << endl;
        cout << "[koniec] - konczy program" << endl << endl;

        while(1) {
                cin >> txt;
                if(txt == "koniec") break;
                if(txt == "+") {
                    Macierz trzecia = pierwsza + druga;
                    cout << "Wynik dodawania macierzy: " << endl <<  trzecia << endl;
                }
                if(txt == "+=") {
                    pierwsza += druga;
                    cout << "Wynik dodawania macierzy: " << endl <<  pierwsza << endl;
                }
                if(txt == "-") {
                    Macierz trzecia = pierwsza - druga;
                    cout << "Wynik odejmowania macierzy: " << endl << trzecia << endl;
                }
                if(txt == "-=") {
                    pierwsza -= druga;
                    cout << "Wynik odejmowania macierzy: " << endl << pierwsza << endl;
                }
                if(txt == "*") {
                    Macierz trzecia = pierwsza * druga;
                    cout << "Wynik odejmowania macierzy: " << endl << trzecia << endl;
                }
                if(txt == "*=") {
                    pierwsza *= druga;
                    cout << "Wynik odejmowania macierzy: " << endl << pierwsza << endl;
                }
                if(txt == "~") {
                    Macierz trzecia = ~pierwsza;
                    cout << "Wynik transpozycji macierzy: " << endl << trzecia << endl;
                }
                if(txt == "*s") {
                    cout << "Wpisz skalar: ";
                    cin >> wielkosc;
                    Macierz trzecia = pierwsza * wielkosc;
                    cout << endl << "Wynik mnozenia macierzy przez skalar: " << endl << trzecia << endl;
                }
                if(txt == "*=s") {
                    cout << "Wpisz skalar: ";
                    cin >> wielkosc;
                    pierwsza *= wielkosc;
                    cout << endl << "Wynik mnozenia macierzy przez skalar: " << endl << pierwsza << endl;
                }

            }
    }
    catch(rozmiary_nie_pasuja &macierz) {
        cerr << macierz.what() << endl;
    }
    return 0;
}

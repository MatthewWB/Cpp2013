#include <iostream>
#include <string>
#include "wielomian.hpp"

using namespace std;

int main() {

    int a, b;
    double* wsp;
    double x;
    string txt;

    try {
        /* pierwszy wielomian */
        cout << "Wprowadz stopien pierwszego wielomianu: ";
        cin >> a; b = a;
        wsp = new double[a + 1];

        cout << "Wprowadz wspolczyniki pierwszego wielomianu stopnia " << a << " : ";
        for(int i = a; i >= 0; i--)
            cin >> wsp[i];

        Wielomian w1(a, wsp);
        delete[] wsp;

        /* drugi wielomian */
        cout << endl << "Wprowadz stopien pierwszego wielomianu: ";
        cin >> a;
        wsp = new double[a + 1];

        cout << "Wprowadz wspolczyniki drugiego wielomianu stopnia " << a << " : ";
        for(int i = a; i >= 0; i--)
            cin >> wsp[i];

        Wielomian w2(a, wsp);
        delete[] wsp;

        cout << endl << endl << "Dostepne komendy:" << endl << "[wielomian1() | liczba] - zwraca wartosc wielomianu w punkcie" << endl;
        cout << "[wielomian2() | liczba] - zwraca wartosc wielomianu drugiego w punkcie" << endl << "[wielomian1] - wyswietla wielomian pierwszy" << endl;
        cout << "[wielomian2] - zwraca wielomian drugi" << endl << "[dodaj] - dodaje wspolczynniki wielomianu" << endl;
        cout << "[odejmij] - odejmuje wspolczynniki wielomianu" << endl << "[mnoz] - przemnaza wszystkie wspolczynniki wielomianow" << endl;
        cout << "[mnoz_stala | liczba] - wielomian mnozony jest przez liczbe" << endl << "[czytaj | liczba] - czyta wskazany wspolczynnik" << endl;
        cout <<  "[dopisz | liczba] - nadpisuje wskazany wspolczynnik " << endl << "[koniec] - konczy program" << endl << endl;

        while(1) {
            cin >> txt;
            if(txt == "wielomian1()") {
                cout << "Wprowadz liczbe, ktora chcesz abym obliczyl: ";
                cin >> x;
                cout << w1(x) << endl;
            }
            if(txt == "wielomian2()") {
                cout << "Wprowadz liczbe, ktora chcesz abym obliczyl: ";
                cin >> x;
                cout << w2(x) << endl;
            }
            if(txt == "dodaj") cout << w1 + w2;
            if(txt == "odejmij") cout << w1 - w2;
            if(txt == "mnoz") cout << w1 * w2;
            if(txt == "wielomian1") cout << w1;
            if(txt == "wielomian2") cout << w2;
            if(txt == "czytaj") {
                cout << "Wprowadz numer indeksu" << endl;
                cin >> a;
                cout << w1[a] << endl;
            }
            if(txt == "dopisz") {
                cout << "Wprowadz numer indeksu i nowa wartosc" << endl;
                cin >> a >> x;
                if(a == b && x == 0) cout << "Nie mozna przypisac najwiekszej potedze 0" << endl;
                else w1[a] = x;
            }
            if(txt == "mnoz_stala") {
                cout << "Wprowadz liczbe przez jaka mam pomnozyc: ";
                cin >> x;
                cout << w1 * x;
            }
            if(txt == "koniec") break;

        }

    } catch (string err) {
        cout << err;
    }

    return 0;
}

#include <iostream>
#include "operator2arg.hpp"

using namespace std;

int main() {
    try {
        Zmienna::dodaj("x", -3.14);

        /* przyklad: x */
        Wyrazenie *wyr0 = new Zmienna("x");

        /* przyklad: 3 + 5 */
        Wyrazenie *wyr1 = new Dodaj(
            new Liczba(3),
            new Liczba(5)
        );

        /* przyklad: 2 * x + 7 */
        Wyrazenie *wyr2 = new Dodaj(
            new Liczba(2),
            new Mnozenie(
                new Zmienna("x"),
                new Liczba(7)
            )
        );

        /* przyklad: (3 * 11 - 1) / (7 + 5) */

        Wyrazenie *wyr3 = new Dziel(
            new Odejmij(
                new Mnozenie(
                    new Liczba(3),
                    new Liczba(11)
                ),
                new Liczba(1)
            ),
            new Dodaj(
                new Liczba(7),
                new Liczba(5)
            )
        );

        /* przyklad: ((x + 1) * x) / 2 */
        Wyrazenie *wyr4 = new Dziel(
            new Mnozenie (
                new Dodaj (
                    new Zmienna("x"),
                    new Liczba(1)
                ),
                new Zmienna("x")
            ),
            new Liczba(2)
        );

        /* przyklad: sin(2 * x + 1) */
        Wyrazenie *wyr5 = new Sin(
            new Dodaj (
                new Mnozenie (
                    new Liczba(2),
                    new Zmienna("x")
                ),
                new Liczba(1)
            )
        );

        cout << wyr0->opis() << " = " << wyr0->oblicz() << endl;
        cout << wyr1->opis() << " = " << wyr1->oblicz() << endl;
        cout << wyr2->opis() << " = " << wyr2->oblicz() << endl;
        cout << wyr3->opis() << " = " << wyr3->oblicz() << endl;
        cout << wyr4->opis() << " = " << wyr4->oblicz() << endl;
        cout << wyr5->opis() << " = " << wyr5->oblicz() << endl;

        delete wyr0;
        delete wyr1;
        delete wyr2;
        delete wyr3;
        delete wyr4;
        delete wyr5;

    } catch(string str) {
        cerr << str;
    }

    return 0;
}

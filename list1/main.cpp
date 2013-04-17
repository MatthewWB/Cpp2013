#include "punkt.h"
#include "kolo.h"
#include "headers.h"
#include <iostream>

using namespace std;

int main(void) {

    double pkt1, pkt2;
    int promien;

    try {
        cout << "Wprowadz punkty dla kola pierwszego [x y r] " << endl;
        cin >> pkt1 >> pkt2 >> promien;

        punkt srodek = punkt(pkt1, pkt2);
        kolo kolo_pierwsze = kolo(promien, &srodek);

        cout << "Wprowadz punkty dla kola drugiego [x y r]  " << endl;
        cin >> pkt1 >> pkt2 >> promien;

        punkt srodek2 = punkt(pkt1, pkt2);
        kolo kolo_drugie = kolo(promien, &srodek2);

        cout << "Kola maja punkty wspolne:  " << (punkty_wspolne(kolo_pierwsze, kolo_drugie) ? "tak" : "nie") << endl;
        cout << endl << "Pole powierzchni calkowitej kolo pierwszego " << kolo_pierwsze.pole_powierzchni() << endl << endl;
        cout << "Pole powierzchni calkowitej kola drugiego " << kolo_drugie.pole_powierzchni() << endl << endl;

        cout << "Podaj 2 punkty, aby zobaczyc czy naleza do kol [x y]" << endl;
        cin >> pkt1 >> pkt2;

        punkt wsp = punkt(pkt1, pkt2);
        cout << "Kolo pierwsze ma wspolne punkty z punktem: " << (punkt_wspolny(kolo_pierwsze, wsp) ? "tak" : "nie") << endl;
        cout << "Kolo drugie ma wspolne punkty z punktem: " << (punkt_wspolny(kolo_drugie, wsp) ? "tak" : "nie") << endl;

        cout << endl << "Wprowadz 2 punkty, aby przesunac kola [x y] " << endl;
        cin >> pkt1 >> pkt2;

        kolo_pierwsze.przesun(pkt1, pkt2);
        kolo_drugie.przesun(pkt1, pkt2);

        cout << endl << "Kolo pierwsze ma obecnie punkty: " << kolo_pierwsze.srodek->x << " oraz " << kolo_pierwsze.srodek->y << endl;
        cout << "Kolo drugie ma obecnie punkty: " << kolo_drugie.srodek->x << " oraz " << kolo_drugie.srodek->y << endl;

    } catch(string warning_str) {
        cout << warning_str;
    }

    return 0;
}

#include "data.hpp"
#include <string>

using namespace std;

int main() {
    int dzien, miesiac, rok;
    string plName[] = {"piatek", "sobota", "niedziela", "poniedzialek", "wtorek", "sroda", "czwartek"};

    try {
        cout << "Wprowadz date [dd - mm - rrrr]" << endl;
        cin >> dzien >> miesiac >> rok;

        Data data = Data();
        Data data2 = Data(dzien, miesiac, rok);

        cout << "Od wprowadzonej daty uplynelo: " << data.roznicaDni(data, data2) << endl;
        cout << "Byl to dzien tygodnia: " << plName[(data2.dzienTygodnia())];

    } catch( string str ) {
        cerr << str;
    }
    return 0;
}

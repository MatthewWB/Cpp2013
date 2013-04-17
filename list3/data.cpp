#include "data.hpp"
#include <string>

time_t Data::initTime = time(0);

tm* Data::currentDate = localtime(&initTime);

Data::Data() : day(currentDate->tm_mday), month(currentDate->tm_mon + 1), year(currentDate->tm_year + 1900) {}

Data::Data(int d, int m, int y) : day(d), month(m), year(y) {
    if(!poprawnoscDaty(d, m, y)) throw std::string("wprowadzony miesiac nie posiada tylu dni");
}

Data::Data(const Data &other) : day(other.day), month(other.month), year(other.year) {
    if(!poprawnoscDaty(day, month, year)) throw std::string("wprowadzony miesiac nie posiada tylu dni");
}

bool Data::sprawdzRok(int rok) {
    if(rok < 0) throw std::string("rok jest niedodatni");
    return ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0);
}

bool Data::poprawnoscDaty(int d, int m, int r) {
    if(r < 1582 || (r == 1582 && m < 10) || (r == 1582 && m <= 10 && d < 15))
        throw std::string("wprowdzona data nie nalezy do kalendarzu gregorianskiego");
    if(m <= 0 || m >= 13) throw std::string("jest 12 miesiacy");
    if(d <= 0 || d >= 32) throw std::string("miesiac nie ma tylu dni");
    return (dniwmiesiacach[sprawdzRok(r)][m] >= d);
}

int Data::iloscDniOdStalej(const Data& date) const {
    int parzystosc = sprawdzRok(date.year) ? 1 : 0;
    int wynik = date.year * 365 + (date.year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + dniodpoczroku[parzystosc][month - 1] + day - 1;
    return wynik = (wynik > 0) ? wynik + 1 : wynik - 1;
}

int Data::roznicaDni(const Data& date1, const Data& date2) {
    return date1.iloscDniOdStalej(date1) - date2.iloscDniOdStalej(date2);
}

Data::dzienTyg Data::dzienTygodnia() {
    return dzienTyg(roznicaDni(Data(day, month, year), Data(15, 10, 1582)) % 7);
}

int Data::dniwmiesiacach[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int Data::dniodpoczroku[2][13] = {
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
};

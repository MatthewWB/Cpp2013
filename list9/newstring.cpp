#include "newstring.hpp"

/* konstruktory */
namespace obliczenia {

    newstring::newstring() throw() : wartosc("") {}

    newstring::newstring(std::string zmienna) throw() : wartosc(zmienna) {}

    newstring::newstring(const newstring &other) throw() : wartosc(other.wartosc) { }

    newstring::~newstring() throw() {}

    newstring& newstring::operator = (const newstring &nowy) throw() {
        if(this == &nowy)
            return *this;

        wartosc = nowy.wartosc;
        return *this;
    }

    /* typy podstawowe */

    std::string newstring::intZamiana(int calkowita) throw() {
        std::string str, temp;

        if(calkowita < 0) {
            str = "-";
            calkowita = -calkowita;
        }

        do {
            temp += calkowita % 10 + 48;
            calkowita -= calkowita % 10;
        } while(calkowita /= 10);

        for(int i = temp.size() - 1; i >= 0; i--)
            str += temp[i];

        return str;
    }

    newstring::newstring(int calkowita) throw() {
        wartosc = intZamiana(calkowita);
    }

    newstring::newstring(double przecinkowa) throw() {
        wartosc = intZamiana(przecinkowa / 1) + "." + intZamiana(abs((przecinkowa - ((long) przecinkowa)) * 100));
    }

    newstring::newstring(bool logiczna) throw() {
        if(logiczna == 1)
            wartosc = "True";
        else
            wartosc = "False";
    }

    newstring::newstring(char znak) throw() {
        wartosc = znak;
    }

    newstring::newstring(void* rzutowanie) throw() {
        newstring *konwersja = reinterpret_cast<newstring*>(rzutowanie);
        wartosc = konwersja->wartosc;
    }

    /* operator typow podstawowych */

    newstring::operator int() throw(std::bad_cast) {
        int wynik = 0, k = 0, znak = 0;
        if(wartosc[0] == '-') znak++, wynik++;

        for(unsigned i = k; i < wartosc.size(); i++) {
            if(wartosc[i] < 48 || wartosc[i] > 57) throw std::bad_cast();
            wynik = wynik * 10 + wartosc[i] - 48;
        }

        if(znak == 1) return -wynik;
        else return wynik;
    }

    newstring::operator double() throw(std::bad_cast) {
        double wynik;
        if(!(std::stringstream(wartosc) >> wynik)) throw std::bad_cast();
        return wynik;
    }

    newstring::operator bool() throw(std::bad_cast) {
        if(wartosc != "True" && wartosc != "False") throw std::bad_cast();
        if(wartosc == "True")
            return true;
        else
            return false;
    }

    newstring::operator char() throw(std::bad_cast) {
        return wartosc[0];
    }

    newstring::operator void*() throw(std::bad_cast) {
        return reinterpret_cast<void*>(this);
    }

    /* operatory dodawania */

    newstring& newstring::operator += (const newstring &nowy) throw() {
        wartosc += nowy.wartosc;
        return *this;
    }

    newstring operator + (const newstring &nowy, int calk) throw() {
        newstring dodawanie(nowy);
        return dodawanie += calk;
    }

    newstring operator + (const newstring &nowy, double przec) throw() {
        newstring dodawanie(nowy);
        return dodawanie += przec;
    }

    newstring operator + (const newstring &nowy, bool logic) throw() {
        newstring dodawanie(nowy);
        return dodawanie += logic;
    }

    newstring operator + (const newstring &nowy, char znak) throw() {
        newstring dodawanie(nowy);
        return dodawanie += znak;
    }

    newstring operator + (const newstring &nowy, void* rzut) throw() {
        newstring dodawanie(nowy);
        return dodawanie += rzut;
    }

    newstring operator + (int calk, const newstring &nowy) throw() {
        return calk + nowy;
    }

    newstring operator + (double przec, const newstring &nowy) throw() {
        return przec + nowy;
    }

    newstring operator + (bool logic, const newstring &nowy) throw() {
        return logic + nowy;
    }

    newstring operator + (char znak, const newstring &nowy) throw() {
        return znak + nowy;
    }

    newstring operator + (void* rzut, const newstring &nowy) throw() {
        return rzut + nowy;
    }


    /* operatory rownosci */

    bool operator > (const newstring &nowy, const newstring &nowy2) throw() {
        return (nowy.wartosc.compare(nowy2.wartosc) > 0);
    }

    bool operator >= (const newstring &nowy, const newstring &nowy2) throw() {
        return (nowy.wartosc.compare(nowy2.wartosc) >= 0);
    }

    bool operator == (const newstring &nowy, const newstring &nowy2) throw() {
        return (nowy.wartosc.compare(nowy2.wartosc) == 0);
    }

    bool operator != (const newstring &nowy, const newstring &nowy2) throw() {
        return (nowy.wartosc.compare(nowy2.wartosc) != 0);
    }

    bool operator < (const newstring &nowy, const newstring &nowy2) throw() {
        return (nowy.wartosc.compare(nowy2.wartosc) < 0);
    }

    bool operator <= (const newstring &nowy, const newstring &nowy2) throw() {
        return (nowy.wartosc.compare(nowy2.wartosc) <= 0);
    }

    /* funkcje skladowe */

    int newstring::length() throw() {
        return wartosc.length();
    }

    newstring& newstring::append(const newstring &nowy) throw(std::out_of_range) {
        wartosc.append(nowy.wartosc);
        return *this;
    }

    newstring& newstring::insert(const newstring &nowy, size_t pozycja) throw(std::out_of_range) {
        wartosc.insert(pozycja, nowy.wartosc);
        return *this;
    }

    newstring& newstring::erase(size_t dlugosc, size_t pozycja) throw(std::out_of_range) {
        wartosc.erase(pozycja, dlugosc);
        return *this;
    }

    newstring& newstring::substr(size_t dlugosc, size_t pozycja) throw(std::out_of_range) {
        wartosc.substr(pozycja, dlugosc);
        return *this;
    }

    newstring& newstring::replace(size_t dlugosc, size_t pozycja, const newstring &str) throw(std::out_of_range) {
        wartosc.replace(pozycja, dlugosc, str.wartosc);
        return *this;
    }

    /* operatory indeksowania */

    char& newstring::operator [] (size_t pozycja) throw(std::out_of_range) {
        if(pozycja > wartosc.size())
            throw std::out_of_range("Zly indeks");
        return wartosc[pozycja];
    }

    const char& newstring::operator [] (size_t pozycja) const throw(std::out_of_range) {
        if(pozycja > wartosc.size())
            throw std::out_of_range("Zly indeks");
        return wartosc[pozycja];
    }

    std::ostream& operator << (std::ostream &out, const newstring &wy) throw() {
        out << wy.wartosc;
        return out;
    }

}

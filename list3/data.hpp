#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <iostream>
#include <ctime>

class Data {
  public:
    const int day;
    const int month;
    const int year;
    static int dniwmiesiacach[2][13];
    static int dniodpoczroku[2][13];
    enum dzienTyg {piatek, sobota, niedziela, poniedzialek,
                    wtorek, sroda, czwartek};

  private:
    static time_t initTime;
    static struct tm* currentDate;

  public:
    Data();
    Data(int d, int m, int year);
    Data(const Data &other);
    dzienTyg dzienTygodnia();
    int roznicaDni(const Data &date1, const Data &date2);

  protected:
    static bool sprawdzRok(int rok);

  private:
    int iloscDniOdStalej(const Data &date) const;
    static bool poprawnoscDaty(int d, int m, int r);
};

#endif // DATA_HPP_INCLUDED

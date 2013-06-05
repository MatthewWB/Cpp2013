#ifndef MANIPULATORY_H_INCLUDED
#define MANIPULATORY_H_INCLUDED

#include <ostream>
#include <iomanip>
#include <vector>
#include <string>

namespace obliczenia {

  /* funkcje */

  void babelekSort(std::vector<std::pair<std::string, int> >& tekst);
  std::istream & clearline(std::istream &wejscie) ;
  std::ostream & comma(std::ostream &wyjscie);
  void zadaniePierwsze();

  /* klasy */

  class ignore {
    private:
      int parametr;

    public:
      ignore(int param);

    public:
      friend std::istream & operator >> (std::istream &input, const ignore &op);

    };

  class index {
    private:
      int zmiennaX, zmiennaY;

    public:
      index(int paramX, int paramY);

    public:
      friend std::ostream & operator << (std::ostream &wyjscie, const index &in);
  };

}

#endif // MANIPULATORY_H_INCLUDED


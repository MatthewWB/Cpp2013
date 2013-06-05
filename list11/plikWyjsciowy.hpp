#ifndef PLIKWYJSCIOWY_HPP_INCLUDED
#define PLIKWYJSCIOWY_HPP_INCLUDED

#include <string>
#include <fstream>
#include <sstream>

namespace obliczenia {

  class plikWyjsciowy : public std::ofstream {

    public:
      plikWyjsciowy(std::string nazwa);
      ~plikWyjsciowy();

    public:
      void ustawLinie(std::string zmienna);
      void ustawInt(int param);
      void ustawDouble(double param);
      void ustawEndl();

    public:
      friend plikWyjsciowy& operator << (plikWyjsciowy &wy, char znak);
      friend plikWyjsciowy& operator << (plikWyjsciowy &wy, int liczba);
      friend plikWyjsciowy& operator << (plikWyjsciowy &wy, double przec);
      friend plikWyjsciowy& operator << (plikWyjsciowy &wy, std::string znak);
  };

}

#endif // PLIKWYJSCIOWY_HPP_INCLUDED

#ifndef PLIKWEJSCIOWY_HPP_INCLUDED
#define PLIKWEJSCIOWY_HPP_INCLUDED

#include <string>
#include <fstream>
#include <vector>

namespace obliczenia {

  void zadanieDrugie();

  class plikWejsciowy : public std::ifstream {

    public:
      plikWejsciowy(std::string nazwa);
      ~plikWejsciowy();

    public:
      std::string pobierzLinie();
      int pobierzInt();
      double pobierzDouble();

    public:
      friend plikWejsciowy& operator >> (plikWejsciowy &we, char &znak);
      friend plikWejsciowy& operator >> (plikWejsciowy &we, int &liczba);
      friend plikWejsciowy& operator >> (plikWejsciowy &we, double &przec);
      friend plikWejsciowy& operator >> (plikWejsciowy &we, std::string &znak);
  };

}

#endif // PLIKWEJSCIOWY_HPP_INCLUDED

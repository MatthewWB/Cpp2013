#ifndef WYJATEK_HPP_INCLUDED
#define WYJATEK_HPP_INCLUDED

#include <iostream>
#include <string>
#include <exception>

class rozmiary_nie_pasuja : public std::exception {
  private:
    std::string komunikat;

  public:
    rozmiary_nie_pasuja(std::string wyjatek) throw();
    rozmiary_nie_pasuja(const rozmiary_nie_pasuja &other) throw();
    virtual ~rozmiary_nie_pasuja() throw();
    const char *what() const throw();
};

class wspolrzedne_bledne : public std::exception {
  private:
    std::string komunikatBledne;

  public:
    wspolrzedne_bledne(std::string wyjatek) throw();
    wspolrzedne_bledne(const wspolrzedne_bledne &other) throw();
    virtual ~wspolrzedne_bledne() throw();
    const char *what() const throw();
};

#endif // WYJATEK_HPP_INCLUDED

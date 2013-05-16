#ifndef NEWSTRING_HPP_INCLUDED
#define NEWSTRING_HPP_INCLUDED

#include <cstdlib>
#include <string>
#include <typeinfo>
#include <stdexcept>
#include <sstream>

namespace obliczenia {

    class newstring {
      private:
        std::string wartosc;

      public:
        newstring() throw();
        newstring(std::string zmienna) throw();
        newstring(const newstring &other) throw();
        virtual ~newstring() throw();
        newstring & operator = (const newstring &nowy) throw();

      public:
        std::string intZamiana(int liczba) throw();
        newstring(int calkowita) throw();
        newstring(double przecinkowa) throw();
        newstring(bool logiczna) throw();
        newstring(char znak) throw();
        newstring(void* rzutowanie) throw();

      public:
        operator int() throw(std::bad_cast);
        operator double() throw(std::bad_cast);
        operator bool() throw(std::bad_cast);
        operator char() throw(std::bad_cast);
        operator void*() throw(std::bad_cast);
        newstring& operator += (const newstring &nowy) throw();

      public:
        friend newstring operator + (const newstring &nowy, int calk) throw();
        friend newstring operator + (const newstring &nowy, double przec) throw();
        friend newstring operator + (const newstring &nowy, char znak) throw();
        friend newstring operator + (const newstring &nowy, bool logic) throw();
        friend newstring operator + (const newstring &nowy, void* rzut) throw();

      public:
        friend newstring operator + (int calk, const newstring &nowy) throw();
        friend newstring operator + (double przec, const newstring &nowy) throw();
        friend newstring operator + (char znak, const newstring &nowy) throw();
        friend newstring operator + (bool logic, const newstring &nowy) throw();
        friend newstring operator + (void* rzut, const newstring &nowy) throw();


      public:
        friend bool operator < (const newstring &nowy, const newstring &nowy2) throw();
        friend bool operator <= (const newstring &nowy, const newstring &nowy2) throw();
        friend bool operator > (const newstring &nowy, const newstring &nowy2) throw();
        friend bool operator >= (const newstring &nowy, const newstring &nowy2) throw();
        friend bool operator == (const newstring &nowy, const newstring &nowy2) throw();
        friend bool operator != (const newstring &nowy, const newstring &nowy2) throw();

      public:
        int length() throw();
        newstring& append(const newstring &nowy) throw(std::out_of_range);
        newstring& insert(const newstring &nowy, size_t pozycja) throw(std::out_of_range);
        newstring& erase(size_t dlugosc, size_t pozycja) throw(std::out_of_range);
        newstring& substr(size_t dlugosc, size_t pozycja) throw(std::out_of_range);
        newstring& replace(size_t dlugosc, size_t pozycja, const newstring &str) throw(std::out_of_range);

      public:
        char& operator [] (size_t index) throw(std::out_of_range);
        const char& operator [] (size_t index) const throw(std::out_of_range);
        friend std::ostream& operator << (std::ostream &out, const newstring &wy) throw();
    };

};
#endif // NEWSTRING_HPP_INCLUDED

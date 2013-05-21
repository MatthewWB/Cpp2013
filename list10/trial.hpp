#ifndef TRIAL_HPP_INCLUDED
#define TRIAL_HPP_INCLUDED

#include<cstdlib>

void intTest(int n) {
    int tab[n];
    for(int i = 0; i < n; i++)
        tab[i] = i;
    obliczenia::permutacje(n, tab);
    std::cout << "Liczby po permutacji: ";
    obliczenia::wyswietlTablice(n, tab);
    obliczenia::quickSort<int>(0, n - 1, tab, obliczenia::porownajMalejaco);
    //babelkowe(n, tab, porownajNierosnaco);
    std::cout << std::endl << "Liczby po Quick Sorcie: ";
    obliczenia::wyswietlTablice(n, tab);
}

void doubleTest(int n) {
    double *tab[n], wartosc[n];
    for(int i = 0; i < n; i++) {
        wartosc[i] = (double)i + 0.1;
        tab[i] = &wartosc[i];
    }
    obliczenia::permutacje(n, tab);
    std::cout << "Liczby po permutacji: ";
    obliczenia::wyswietlTablice(n, *tab);
    obliczenia::quickSort<double *>(0, n - 1, tab, obliczenia::porownajMalejaco);
    std::cout << std::endl << "Liczby po Quick Sorcie: ";
    obliczenia::wyswietlTablice(n, tab);
}

void charTest(int n, char **tab) {
    obliczenia::permutacje(n, tab);
    std::cout << "Znaki po permutacji: ";
    obliczenia::wyswietlTablice(n, tab);
    obliczenia::babelkowe<char *>(n, tab, obliczenia::porownajRosnaco);
    std::cout << std::endl << "Znaki po sortowaniu babelkowym: ";
    obliczenia::wyswietlTablice(n, tab);
}

void stringTest(int n, std::string tab[]) {
    obliczenia::permutacje(n, tab);
    std::cout << "Slowa po permutacji: ";
    obliczenia::wyswietlTablice(n, tab);
    obliczenia::babelkowe<std::string>(n, tab, obliczenia::porownajRosnaco);
    std::cout << std::endl << "Slowa po Quick Sorcie: ";
    obliczenia::wyswietlTablice(n, tab);
}

#endif // TRIAL_HPP_INCLUDED

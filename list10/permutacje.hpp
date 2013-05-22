#ifndef PERMUTACJE_HPP_INCLUDED
#define PERMUTACJE_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cstring>

namespace obliczenia {

    template<typename T>
    void permutacje(int n, T tab[]) {
        std::random_shuffle(tab, tab + n);
    }

    template<typename T>
    void wyswietlTablice(int n, T tab[]) {
        for(int i = 0; i < n; i++)
            std::cout << tab[i] << ' ';
    }

    template<typename T>
    bool porownajMalejaco(const T arg1, const T arg2) {
        if(arg1 < arg2) return 1;
        return 0;
    }

    template<typename T>
    bool porownajRosnaco(const T arg1, const T arg2) {
        if(arg1 > arg2) return 1;
        return 0;
    }

    template<typename T>
    bool porownaj(T arg1, T arg2) {
        return (arg1 < arg2);
    }

    template<typename T>
    bool porownajRosnaco(const T* arg1, const T* arg2) {
        return ((*arg1) > (*arg2));
    }

    template<typename T>
    bool porownajMalejaco(const T* arg1, const T* arg2) {
        return ((*arg1) < (*arg2));
    }

    template<typename T>
    int podziel(int pocz, int kon, T tab[], bool porownaj(T, T)) {
        int left = pocz, right = kon;
        T pomocnik = tab[pocz];
        while(1) {
            while(porownaj(tab[left], pomocnik)) left++;
            while(porownaj(pomocnik, tab[right])) right--;
            if(left >= right) break;
            std::swap(tab[left], tab[right]);
        }
        return right;
    }

    template<typename T>
    void quickSort(int pocz, int kon, T tab[], bool porownaj(T, T)) {
        if(pocz < kon) {
            int wartownik = podziel(pocz, kon, tab, porownaj);
            quickSort(pocz, wartownik, tab, porownaj);
            quickSort(wartownik + 1, kon, tab, porownaj);
        }
    }


    template<typename T>
    void babelkowe(int n, T tab[], bool porownaj(T, T)) {
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            if(porownaj(tab[j], tab[j + 1]))
                std::swap(tab[j], tab[j + 1]);
    }

    void generujChar(int n, char *tab) {
        tab[0] = (char)(rand() % 26 + 65);
    }

    /* old version permutation *
    template<typename T>
    void permutacje(int n, T tab[]) {
        srand(time(0));
        for(int i = n - 1; i > 0; i--) {
            int j = rand() % i;
            T temp = tab[j];
            tab[j] = tab[i];
            tab[i] = temp;
        }
    }

    template<typename T>
    void permutacje(int n, T tab[]) {
        srand(time(NULL));
        for(int i = n - 1; i > 0; i--)
            std::swap(tab[rand() % i], tab[i]);
    }

    template<typename T>
    void quickSort(int pocz, int kon, T tab[], bool porownaj(T, T)) {
        if(pocz < kon) {
            T wartosc = tab[pocz];
            int i = pocz, j;
            for(j = pocz + 1; j <= kon;j++)
                if(porownaj(wartosc, tab[j])) {
                    tab[i] = tab[j];
                    tab[j] = tab[i + 1];
                    tab[i + 1] = wartosc;
                    i = i + 1;
                }
            quickSort(pocz, i - 1, tab, porownaj);
            quickSort(i + 1, kon, tab, porownaj);
        }
    }

    */
}

#endif // PERMUTACJE_HPP_INCLUDED

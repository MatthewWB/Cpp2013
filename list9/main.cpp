#include <iostream>
#include "newstring.hpp"
#include <climits>
#include <float.h>

using namespace obliczenia;

double funkcjaPrzecinkowa(double przecinkowa) {
    std::cout << przecinkowa << std::endl;
    return przecinkowa;
}

int main() {
    try {
        newstring n1(16.30);
        newstring n6(16.02);
  	void* n2 = n1;
		std::cout << newstring(n2) << std::endl;
		newstring n3(false);
        newstring n4('a');
        newstring n5(123456789);
        funkcjaPrzecinkowa(n1);

        std::cout << n3 << std::endl;
        std::cout << n4 << std::endl;
        std::cout << n5 << std::endl;
        std::cout << (n1 > n6) << std::endl;
        int o = n5;
        std::cout << o << std::endl;

    }
    catch(std::out_of_range& zakres) {
        std::cerr << zakres.what() << std::endl;
    }
    catch(std::bad_cast& error) {
        std::cerr << error.what() << std::endl;
    }
    return 0;
}

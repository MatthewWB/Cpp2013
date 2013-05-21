#include "permutacje.hpp"
#include "trial.hpp"

int main() {
    int n = 5;
    char* tabChar[] = {(char *) "aaa", (char *) "abc", (char *) "bhg", (char *) "cde", (char *) "def"};
    std::string tabString[] = {"do", "re", "mi", "fa", "so"};

    /* int */
    std::cout << "Testowanie (int)" << std::endl;
    intTest(n);

    /* double* */
    std::cout << std::endl << std::endl << "Testowanie (double*)" << std::endl;
    doubleTest(n);

    /* char* */
    std::cout << std::endl << std::endl << "Testowanie (char*)" << std::endl;
    charTest(n, tabChar);

    /* string */
    std::cout << std::endl << std::endl << "Testowanie (string)" << std::endl;
    stringTest(n, tabString);

    return 0;
}

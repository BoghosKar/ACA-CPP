#include <iostream>
#include "../operatorplus/matrix.h"

int main() {
    Matrix mat(3, 3);

    std::cout << "[MATRIX]" << std::endl;
    mat.print();
    std::cout << std::endl;

    std::cout << "[PREFIX]" << std::endl;
    ++mat;
    mat.print();
    std::cout << std::endl;

    std::cout << "[POSTFIX]" << std::endl;
    Matrix mat2 = mat++;
    mat.print();
    std::cout << std::endl;

 

    std::cout << "Press Enter to Close" << std::endl;
    std::cin.get();
    return 0;
}

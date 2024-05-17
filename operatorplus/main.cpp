#include <iostream>
#include "../operatorplus/matrix.h"

int main() {
    Matrix mat(3, 3);

    std::cout << "[MATRIX]" << std::endl;
    mat.print();
    std::cout << std::endl;

    // prefix
    std::cout << "[PREFIX]" << std::endl;
    ++mat;
    mat.print();
    std::cout << std::endl;

    // postfix 
    std::cout << "[POSTFIX]" << std::endl;
    Matrix mat2 = mat++;
    mat.print();
    std::cout << std::endl;

    // copy
    std::cout << "[COPY CONSTRUCTOR]" << std::endl;
    Matrix mat3 = mat;
    mat3.print();
    std::cout << std::endl;

    // copy assignment
    std::cout << "[COPY ASSIGNMENT]" << std::endl;
    Matrix mat4(3, 3);
    mat4 = mat;
    mat4.print();
    std::cout << std::endl;

    // move constructor
    std::cout << "[MOVE CONSTRUCTOR]" << std::endl;
    Matrix mat5 = std::move(mat);
    mat5.print();
    std::cout << std::endl;

    // move assignment 
    std::cout << "[MOVE ASSIGNMENT]" << std::endl;
    Matrix mat6(3, 3);
    mat6 = std::move(mat2);
    mat6.print();
    std::cout << std::endl;

    std::cout << "Press Enter to Close" << std::endl;
    std::cin.get();
    return 0;
}

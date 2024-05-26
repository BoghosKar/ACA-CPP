#include "../MatrixMultiplication/matrix.h"

int main()
{
    Matrix<int> matrix1(3,3);
    matrix1.fillRandom();
    matrix1.print();
    matrix1.writeToTextFile("matrix1.txt");

    Matrix<int> matrix2(3,3);
    matrix2.fillRandom();
    matrix2.print();
    matrix2.writeToTextFile("matrix2.txt");

    Matrix<int> matrix1FromFile = Matrix<int>::readFromTextFile("matrix1.txt");
    Matrix<int> matrix2FromFile = Matrix<int>::readFromTextFile("matrix2.txt");

    Matrix<int> matrix3 = matrix1FromFile + matrix2FromFile;
    matrix3.print();
    matrix3.writeToTextFile("matrix3.txt");

    std::cout << "Press Enter to Close" << std::endl;
    std::cin.get();

    return 0;
}
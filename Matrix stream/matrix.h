#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix
{
public:
    Matrix(int rows, int cols);
    ~Matrix();

    void fillRandom();
    void print() const;
    void writeToTextFile(const std::string& filename) const;
    static Matrix<T> readFromTextFile(const std::string& filename);
    Matrix<T> operator + (const Matrix<T>& other) const;

    int getRows() const;
    int getCols() const;

private:
    int rows;
    int cols;
    T** data;

    void allocateMemory();
    void deallocateMemory();
};

#endif // MATRIX_H
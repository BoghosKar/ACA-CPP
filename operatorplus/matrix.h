#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols);

    ~Matrix();

    Matrix& operator++();

    Matrix operator++(int);

    void print() const;
};

#endif // MATRIX_H

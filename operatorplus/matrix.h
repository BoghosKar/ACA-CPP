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

    Matrix(const Matrix& other); //copy const
    Matrix& operator = (const Matrix& other); //copy assignment 

    Matrix(Matrix&& other); //move const
    Matrix& operator = (Matrix&& other); //move assignment 


    Matrix& operator++();

    Matrix operator++(int);

    void print() const;
};

#endif // MATRIX_H

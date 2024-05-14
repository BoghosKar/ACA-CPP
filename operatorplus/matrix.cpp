#include "../operatorplus/matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    std::cout << __func__ << std::endl;
    data = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        data[i] = new int[cols]();
    }
}

Matrix::~Matrix()
{
    std::cout << __func__ << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

//prefix
Matrix& Matrix::operator++()
{
    std::cout << __func__ << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] += 3;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    std::cout << __func__ << std::endl;

    Matrix temp(*this);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            data[i][j] += 3;
        }
    }

    return temp;
}

void Matrix::print() const
{
    std::cout << __func__ << std::endl;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << " " << data[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

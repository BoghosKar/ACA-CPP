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


Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
{
    std::cout << __func__ << std::endl;
    
    data = new int*[rows];

    for(int i = 0; i < rows; ++i)
    {
        data[i] = new int[cols];
        for(int j = 0; j < cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    } 
}



Matrix& Matrix::operator = (const Matrix& other)
{
    if(this != &other)
    {
        for(int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for(int i = 0; i < rows; ++i)
        {
            data[i] = new int[cols];
            for(int j = 0; j < cols; ++j)
            {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }
    return *this;
}



Matrix::Matrix(Matrix&& other) : data(nullptr), rows(0), cols(0)
{
    std::cout << __func__ << std::endl;

    data = other.data;
    rows = other.rows;
    cols = other.cols;

    other.data = nullptr;
    other.rows = 0;
    other.cols = 0;
}


Matrix& Matrix::operator = (Matrix&& other)
{
    std::cout << __func__ << std::endl;

    if(this != &other)
    {
        for(int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;



        data = other.data;
        rows = other.rows;
        cols = other.cols;


        other.data = nullptr;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
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

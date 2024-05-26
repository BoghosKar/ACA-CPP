#include "../MatrixMultiplication/matrix.h"
#include <cstdlib>
#include <ctime> 

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    allocateMemory();
}

template <typename T>
int Matrix<T>::getRows() const
{
    return rows;
}

template <typename T>
int Matrix<T>::getCols() const
{
    return cols;
}

template <typename T>
Matrix<T>::~Matrix() 
{
    deallocateMemory();
}

template <typename T>
void Matrix<T>::allocateMemory()
{
    data = new T*[rows];
    for(int i = 0; i < rows; ++i)
    {
        data[i] = new T[cols];
    }
}

template <typename T>
void Matrix<T>::deallocateMemory()
{
    for(int i = 0; i < rows; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

template<typename T>
void Matrix<T>::fillRandom()
{
    srand(time(nullptr));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            data[i][j] = (rand() % 90) + 10;
        } 
    }
}

template <typename T>
void Matrix<T>::print() const
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
        std::cout << data[i][j] << " ";
        }
    std::cout << std::endl;
    }
}

template <typename T>
void Matrix<T>::writeToTextFile(const std::string& filename) const
{
    std::ofstream outfile(filename);
    if(!outfile.is_open())
    {
        std::cerr << "Could not open file" << std::endl;
        return;
    }

    outfile << rows << " " << cols << std::endl;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            outfile << data[i][j] << " ";
        }
        outfile << std::endl;
    }
    outfile.close();
}

template <typename T>
Matrix<T> Matrix<T>::readFromTextFile(const std::string& filename)
{
    std::ifstream infile(filename);
    if(!infile.is_open())
    {
        std::cerr << "Could not open file" << std::endl;
        return Matrix<T>(0,0);
    }

    int rows, cols;
    infile >> rows >> cols;

    Matrix<T> matrix(rows, cols);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            infile >> matrix.data[i][j];
        }
    }

    infile.close();
    return matrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& other) const
{
    if(rows != other.rows || cols != other.cols)
    {
        std::cerr << "Matrix dimensions do not match" << std::endl;
        return Matrix<T>(0,0);
    }

    Matrix<T> result(rows,cols);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

template class Matrix<int>;
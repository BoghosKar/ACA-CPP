#include <iostream>
#include <exception>

class myException : public std::exception
{
private:
    std::string message;

public:
    myException(const std::string& msg) : message(msg) {}

    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class Matrix
{
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        data = new T*[rows];
        for(int i = 0; i < rows; ++i)
        {
            data[i] = new T[cols]();
        }
    }

    ~Matrix()
    {
        for(int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }


    T& at(int row, int col)
    {
        if(row < 0 || row >= rows || col < 0 || col >= cols)
        {
            throw myException("Index out of range");
        }
        return data[row][col];
    }


    T& operator () (int row, int col)
    {
        return data[row][col];
    }

    int getRows() const
    {
        return rows;
    }

    int getCols() const
    {
        return cols;
    }
};

int main()
{

    Matrix<int> mat(3, 3);

    mat(0, 0) = 0;
    mat(1, 1) = 1;
    mat(2, 2) = 2;


    try
    {
        std::cout << "Element at (1,1): " << mat.at(1,1) << std::endl;
        std::cout << "Element at (2,2): " << mat.at(2,2) << std::endl;
        std::cout << "Element at (3,3): " << mat.at(3,3) << std::endl;
    }catch(const myException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
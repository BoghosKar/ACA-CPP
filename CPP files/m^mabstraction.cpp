#include <iostream>
#include <cmath>

class Matrix
{
private:
    int** matrix = nullptr;
    int size;

public:
    Matrix()
    {
        std::cout << "Call constructor" << std::endl;
    }

    void AllocateMatrix( int m)
    {
        size = m * m;
        matrix = new int*[size];
        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
        }
    }

    ~Matrix()
    {
        std::cout << "Call destructor" << std::endl;
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
        }
        matrix = nullptr;
        delete[] matrix;
        size = 0;
    }

    Matrix(const Matrix& copy)
    {
        std::cout << "Copy constructor" << std::endl;
        size = copy.size;
        matrix = new int*[size];

        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = copy.matrix[i][j];
            }
        }
    }

    Matrix& operator = (const Matrix& copy)
    {
        std::cout << "Assignment Operator" << std::endl;
        if (this != &copy)
        {
            if(size != copy.size)
            {
                size = copy.size;
                delete[] matrix;
                for(int i = 0; i < copy.size; i++)
                {
                    delete[] matrix[i];
                }
                matrix = new int*[copy.size];
            }
            for (int i = 0; i < copy.size; i++)
            {
                for (int j = 0; j < copy.size; j++)
                {
                    matrix[i][j] = copy.matrix[i][j];
                }
            }
        }
        return *this;
    }

    Matrix operator + (const Matrix& copy) 
    {
        // std::cout << "Plus Operator" << std::endl;
        if (size != copy.size)
        {
            std::cout << "Error - Matrixes have different sizes" << std::endl;
            return Matrix();
        }

    
        Matrix result;
        result.AllocateMatrix(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = matrix[i][j] + copy.matrix[i][j];
            }
        }
        
        return result;
    }

    void Randomize()
    {
        srand(time(nullptr));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = (rand() % 90) + 10;
            }
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << "  " << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void Rotate()
    {
        for (int i = 0; i < size; i++) 
        {
            for (int j = i + 1; j < size; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size / 2; j++)
            {
                std::swap(matrix[i][j], matrix[i][size - 1 - j]);
            }
        }
    }
};

int main()
{
    int m = 2;

    Matrix matrix;
    matrix.AllocateMatrix(m);
    matrix.Randomize();
    matrix.Print();
        
    matrix.Rotate();
    matrix.Print();

    Matrix copiedMatrix(matrix);
    copiedMatrix.Print();

    Matrix result = matrix + copiedMatrix;
    std::cout << "Result matrix:" << std::endl;
    result.Print();


    return 0;
}

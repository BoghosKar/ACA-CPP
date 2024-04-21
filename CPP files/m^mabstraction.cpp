#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

class Matrix
{
private:
    int** matrix;
    int size;

public:
    Matrix() {}

    void AllocateMatrix(int m)
    {
        size = pow(m, m);
        matrix = (int**)malloc(size * sizeof(int*));

        for (int i = 0; i < size; i++)
        {
            matrix[i] = (int*)malloc(size * sizeof(int));
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < size; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }

    void Randomize()
    {
        srand(time(nullptr));
        for (int i = 0; i < size; i++)
        {
            for (int n = 0; n < size; n++)
            {
                matrix[i][n] = (rand() % 90) + 10;
            }
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int n = 0; n < size; n++)
            {
                std::cout << "  " << matrix[i][n] << " ";
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

    return 0;
}

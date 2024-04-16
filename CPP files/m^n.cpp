#include <iostream>
#include <cmath>


void Randomizer(int** matrix, const int& size)
{
    srand(time(nullptr));
    for (int i = 0; i < size; i++)
    {
        for (int n = 0; n < size; n++)
        {
            matrix[i][n] = (rand() %  90) + 10;
        }
    }
}

void Print(int** matrix, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int n = 0; n < size; n++)
        {
            std::cout << "    " << matrix[i][n] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printOpposite(int** matrix, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int n = 0; n < size; n++)
        {
            std::cout << "    " << matrix[n][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int main()
{
    int m = 3;
    int n = 2;

    int size = pow(m, n);


    int** matrix = (int**) malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int*)malloc(size * sizeof(int));
        if (matrix[i] == nullptr)
        {
            return 1;
        }
    }

    Randomizer(matrix, size);
    Print(matrix, size);
    printOpposite(matrix, size);



    free(matrix);

    return 0;
}

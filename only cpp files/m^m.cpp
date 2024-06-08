#include <iostream>
#include <cmath>

void Randomizer(int** matrix, const int& size)
{
    srand(time(nullptr));
    for(int i = 0; i < size; i++)
    {
        for(int n = 0; n < size; n++)
        {
            matrix[i][n] = (rand() % 90) + 10;
        } 
    }
}


void Print(int** matrix, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        for(int n = 0; n < size; n++)
        {
            std::cout << "  " << matrix[i][n] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void Rotate(int** matrix, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size/2; j++)
        {
            std::swap(matrix[i][j], matrix[i][size - 1 - j]);
        }
    }


}


int main()
{
    int m = 2;
    int size = pow(m, m);

    int** matrix = (int**) malloc(size * sizeof(int*));

    for(int i = 0; i < size; i++)
    {
        matrix[i] = (int*) malloc(size * sizeof(int));
    }


    Randomizer(matrix, size);
    Print(matrix, size);
    Rotate(matrix, size);
    Print(matrix, size);
    
   
   

    free(matrix);
    return 0;
}
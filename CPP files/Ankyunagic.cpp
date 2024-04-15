#include <iostream>


void Print(int** matrix, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        for(int n = 0; n < size; n++)
        {
            std::cout << "    " << matrix[i][n] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

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

void DiagonalPrint(int** matrix, const int& size)
{
    for(int rowIndex = 0; rowIndex < size; rowIndex++) 
    {
        for(int columnIndex = 0; columnIndex < size; columnIndex++)
        {
            if(rowIndex > columnIndex)
            {
                std::cout << "    " << matrix[rowIndex][columnIndex] << " ";
            }else
            {
                std::cout << "    " << " " << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int size;

    while (true)
    {
        std::cout << "Please enter a size for the matrix (between 5 and 10): " << std::endl;
        std::cin >> size;

        if (size >= 5 && size <= 10)
        {
            break;
        } 
        else
        {
            std::cout << "Size must be between 5 and 10" << std::endl;
        }
    }

    int** matrix = (int**) malloc(size * sizeof(int*));

    for(int i = 0; i < size; i++)
    {
        matrix[i] = (int*) malloc(size * sizeof(int));
    }

    Randomizer(matrix, size);
    Print(matrix, size);
    DiagonalPrint(matrix, size);

    for(int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    
    free(matrix);

    return 0;
}

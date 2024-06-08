#include <iostream>

class Array
{
private:
    int* arr = nullptr;
    int size = 0;    

public:

   Array(int size) : size(size), arr(new int[size]) {}

   ~Array()
   {
    delete[] arr;
   }

    int& operator[] (int index)
    {
        if(index < 0 || index >= size)
        {
            std::cout << "ERROR" << std::endl;
        }

        return arr[index];
    }

    friend std::ostream& operator << (std::ostream& os, const Array& arrobj);
};

std::ostream& operator << (std::ostream& os, const Array& arrobj)
{
    os << "[";
    
    for (int i = 0; i < arrobj.size; i++)
    {
        os << arrobj.arr[i];

        if (i < arrobj.size - 1)
        {
            os << ", ";
        }
    }

    os << "]";

    return os; 
}


int main()
{
    Array array(5);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    std::cout << "array: " << array << std::endl;

    return 0;
}
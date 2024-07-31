#include <iostream>
#include "my_vector.h"

int main()
{
    MyVector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Vector elements: ";

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
    
    vec.pop_back();
    std::cout << "Vector elements after pop: ";
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

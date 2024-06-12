#include <iostream>
#include <list>
#include "deleteBelowAverage.h"

int main()
{
    std::list<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    deleteBelowAverage(numbers);
    
    std::cout << "[ ";
    for(const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
#include <iostream>
#include <vector>
#include "deletePrimes.h"

int main()
{
    std::vector<int> numbers = {10, 11, 11, 12, 13, 13, 13, 14, 15, 16, 17, 18, 19, 20};

    deletePrimes(numbers);

    for(const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    return 0;
}
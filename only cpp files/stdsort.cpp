#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    // VECTOR SORT
    std::vector<int> vec = {30, 10, 50, 20, 60, 40};
    
    std::cout << std::endl;
    
    std::cout << "Vector: ";
    for (int val : vec)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted vector: ";
    for (int val : vec)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // LIST SORT
    std::list<int> list = {30, 10, 50, 20, 60, 40};

    std::cout << "List: ";    
    for (int val : list)
    {
        std::cout << val << " ";
    }


    list.sort();

    std::cout << std::endl << "Sorted list: ";
    for (int val : list)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}

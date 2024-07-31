#include <iostream>
#include "my_unordered_set.h"

int main()
{
    MyUnorderedSet my_unordered_set;
    my_unordered_set.insert(3);
    my_unordered_set.insert(1);
    my_unordered_set.insert(2);
    std::cout << "Set contains 1: " << my_unordered_set.contains(1) << std::endl;
    std::cout << "Set contains 4: " << my_unordered_set.contains(4) << std::endl;
    my_unordered_set.erase(1);
    std::cout << "Set contains 1 after erase: " << my_unordered_set.contains(1) << std::endl;
    std::cout << "Set size: " << my_unordered_set.size() << std::endl;
    return 0;
}

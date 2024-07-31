#include <iostream>
#include "my_set.h"

int main()
{
    MySet my_set;
    my_set.insert(3);
    my_set.insert(1);
    my_set.insert(2);
    std::cout << "Set with 1: " << my_set.contains(1) << std::endl;
    std::cout << "Set with 4: " << my_set.contains(4) << std::endl;
    my_set.erase(1);
    std::cout << "Set with 1 after erase: " << my_set.contains(1) << std::endl;
    std::cout << "Set size: " << my_set.size() << std::endl;
    return 0;
}

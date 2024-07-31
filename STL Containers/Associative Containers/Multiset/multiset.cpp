#include <iostream>
#include "my_multiset.h"

int main()
{
    MyMultiset my_multiset;
    my_multiset.insert(3);
    my_multiset.insert(1);
    my_multiset.insert(2);
    my_multiset.insert(1);
    std::cout << "Multiset with 1: " << my_multiset.count(1) << std::endl;
    std::cout << "Multiset with 4: " << my_multiset.count(4) << std::endl;
    my_multiset.erase(1);
    std::cout << "Multiset with 1 after erase: " << my_multiset.count(1) << std::endl;
    std::cout << "Multiset size: " << my_multiset.size() << std::endl;
    return 0;
}

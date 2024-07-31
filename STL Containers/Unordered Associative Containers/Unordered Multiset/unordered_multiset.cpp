#include <iostream>
#include "my_unordered_multiset.h"

int main()
{
    MyUnorderedMultiset my_unordered_multiset;
    my_unordered_multiset.insert(3);
    my_unordered_multiset.insert(1);
    my_unordered_multiset.insert(2);
    my_unordered_multiset.insert(1);
    std::cout << "Multiset count of 1: " << my_unordered_multiset.count(1) << std::endl;
    std::cout << "Multiset count of 4: " << my_unordered_multiset.count(4) << std::endl;
    my_unordered_multiset.erase(1);
    std::cout << "Multiset count of 1 after erase: " << my_unordered_multiset.count(1) << std::endl;
    std::cout << "Multiset size: " << my_unordered_multiset.size() << std::endl;
    return 0;
}

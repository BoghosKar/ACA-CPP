#include <iostream>
#include "my_multimap.h"

int main()
{
    MyMultimap my_multimap;
    my_multimap.insert("one", 1);
    my_multimap.insert("one", 11);
    my_multimap.insert("two", 2);
    my_multimap.insert("three", 3);
    std::vector<int> values = my_multimap.find("one");

    std::cout << "Values for 'one': ";
    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    my_multimap.erase("one");
    values = my_multimap.find("one");
    std::cout << "Values for 'one' after erase: ";
    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Multimap size: " << my_multimap.size() << std::endl;
    return 0;
}

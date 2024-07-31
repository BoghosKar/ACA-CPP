#include <iostream>
#include "my_unordered_multimap.h"

int main()
{
    MyUnorderedMultimap my_unordered_multimap;
    my_unordered_multimap.insert("one", 1);
    my_unordered_multimap.insert("one", 11);
    my_unordered_multimap.insert("two", 2);
    my_unordered_multimap.insert("three", 3);
    std::vector<int> values = my_unordered_multimap.find("one");
    std::cout << "Values for 'one': ";
    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    my_unordered_multimap.erase("one");
    values = my_unordered_multimap.find("one");
    std::cout << "Values for 'one' after erase: ";
    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    std::cout << "Multimap size: " << my_unordered_multimap.size() << std::endl;
    return 0;
}

#include <iostream>
#include "my_unordered_map.h"

int main()
{
    MyUnorderedMap my_unordered_map;
    my_unordered_map.insert("one", 1);
    my_unordered_map.insert("two", 2);
    my_unordered_map.insert("three", 3);
    std::cout << "Value for 'one': " << my_unordered_map["one"] << std::endl;
    std::cout << "Value for 'two': " << my_unordered_map["two"] << std::endl;
    std::cout << "Value for 'four' (default): " << my_unordered_map["four"] << std::endl;
    my_unordered_map["four"] = 4;
    std::cout << "Value for 'four' (after setting): " << my_unordered_map["four"] << std::endl;
    my_unordered_map.erase("two");
    std::cout << "Map size after erase: " << my_unordered_map.size() << std::endl;
    return 0;
}

#include <iostream>
#include "my_map.h"

int main()
{
    MyMap my_map;
    my_map.insert("one", 1);
    my_map.insert("two", 2);
    my_map.insert("three", 3);

    std::cout << "Value for 'one': " << my_map["one"] << std::endl;
    std::cout << "Value for 'two': " << my_map["two"] << std::endl;
    std::cout << "Value for 'four' (default): " << my_map["four"] << std::endl;

    my_map["four"] = 4;
    std::cout << "Value for 'four' (after setting): " << my_map["four"] << std::endl;
    my_map.erase("two");
    std::cout << "Size after erase: " << my_map.size() << std::endl;
    return 0;
}

#include <iostream>
#include "my_list.h"

int main()
{
    MyList lst;
    lst.push_back(1);
    lst.push_front(2);
    lst.push_back(3);
    
    std::cout << "List elements: ";
    while (!lst.empty())
    {
        std::cout << lst.front() << " ";
        lst.pop_front();
    }

    std::cout << std::endl;
    return 0;
}

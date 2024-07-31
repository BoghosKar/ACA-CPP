#include <iostream>
#include "my_stack.h"

int main()
{
    MyStack my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    std::cout << "Top element: " << my_stack.top() << std::endl;
    my_stack.pop();
    std::cout << "Top element after pop: " << my_stack.top() << std::endl;
    std::cout << "Stack size: " << my_stack.size() << std::endl;
    return 0;
}

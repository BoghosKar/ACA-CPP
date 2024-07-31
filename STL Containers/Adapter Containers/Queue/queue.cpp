#include <iostream>
#include "my_queue.h"

int main()
{
    MyQueue my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);
    std::cout << "Front element: " << my_queue.front() << std::endl;
    std::cout << "Back element: " << my_queue.back() << std::endl;
    my_queue.pop();
    std::cout << "Front element after pop: " << my_queue.front() << std::endl;
    std::cout << "Queue size: " << my_queue.size() << std::endl;
    return 0;
}

#include <iostream>
#include "my_deque.h"

int main()
{
    MyDeque deq;
    deq.push_back(1);
    deq.push_front(2);
    deq.push_back(3);

    std::cout << "Deque elements: ";
    for (std::size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i] << " ";
    }
    
    std::cout << std::endl;
    
    deq.pop_front();
    std::cout << "Deque elements after pop: ";
    for (std::size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}

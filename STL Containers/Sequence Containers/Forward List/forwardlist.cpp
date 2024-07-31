#include <iostream>
#include "my_forward_list.h"

int main() {
    MyForwardList fwd_lst;
    fwd_lst.push_front(1);
    fwd_lst.push_front(2);
    fwd_lst.push_front(3);
    std::cout << "Forward list elements: ";
    
    while (!fwd_lst.empty())
    {
        std::cout << fwd_lst.front() << " ";
        fwd_lst.pop_front();
    }
    
    std::cout << std::endl;
    return 0;
}

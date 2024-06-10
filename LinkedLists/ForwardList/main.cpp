#include "../ForwardList/forward_list.h"
#include <iostream>

void Print(ForwardList::Iterator begin, ForwardList::Iterator end)
{
    for (ForwardList::Iterator it = begin; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    ForwardList list;
    
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    Print(list.begin(), list.end());

    std::cout << std::endl << "Press Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
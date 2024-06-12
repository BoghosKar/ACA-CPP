#include <iostream>
#include "StackUsingList.h"
#include "StackUsingVector.h"

int main()
{
    // Stack using ForwardList
    StackUsingList stackList;
    stackList.push_front(10);
    stackList.push_front(20);
    stackList.push_front(30);
    
    std::cout << "Stack using ForwardList:" << std::endl;
    while (!stackList.empty())
    {
        std::cout << stackList.front() << " ";
        stackList.pop_front();
    }
    std::cout << std::endl;

    // Stack using std::vector
    StackUsingVector stackVector;
    stackVector.push_back(40);
    stackVector.push_back(50);
    stackVector.push_back(60);
    
    std::cout << "Stack using std::vector:" << std::endl;
    while (!stackVector.empty())
    {
        std::cout << stackVector.back() << " ";
        stackVector.pop_back();
    }
    std::cout << std::endl;

    return 0;
}
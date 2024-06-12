#include <iostream>
#include "StackUsingList.h"
#include "StackUsingVector.h"

int main()
{

    // Stack using ForwardList
    StackUsingList stackList;
    stackList.push(10);
    stackList.push(20);
    stackList.push(30);
    
    std::cout << "Stack using ForwardList:" << std::endl;
    while (!stackList.empty())
    {
        std::cout << stackList.top() << " ";
        stackList.pop();
    }
    std::cout << std::endl;

    // Stack using std::vector
    StackUsingVector stackVector;
    stackVector.push(40);
    stackVector.push(50);
    stackVector.push(60);
    
    std::cout << "Stack using std::vector:" << std::endl;
    while (!stackVector.empty())
    {
        std::cout << stackVector.top() << " ";
        stackVector.pop();
    }
    std::cout << std::endl;

    return 0;
}

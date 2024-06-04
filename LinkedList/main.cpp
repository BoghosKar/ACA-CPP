#include "../LinkedList/list.h"
#include <iostream>


int main() {
    List myList;

    // push_front
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    // traverse after push front
    std::cout << "List after push front: ";
    myList.traverse();

    // insert
    myList.insert(1, 25);
    std::cout << "List after insert: ";
    myList.traverse();

    // pop_front
    myList.pop_front();
    std::cout << "List after pop front: ";
    myList.traverse();
    
    std::cout << std::endl;

    // reverse list
    myList.reverse();
    std::cout << "List after reverse: ";
    myList.traverse();
    
    std::cout << std::endl;

    // findfromend
    int n = 2;
    int result = myList.findNthFromEnd(n);
    if (result != -1)
    {
        std::cout << "The " << n << "nd element from the end is: " << result << std::endl;
    } else
    {
        std::cout << "invalid position" << std::endl;
    }

    std::cout << std::endl;

    // cycle for test
    Node* firstNode = myList.getHead();
    Node* lastNode = myList.getHead();
    
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = firstNode; // cycle

    if (myList.hasCycle()) 
    {
        std::cout << "[YES]" << std::endl;
    } else
    {
        std::cout << "[NO]" << std::endl;
    }

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}
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
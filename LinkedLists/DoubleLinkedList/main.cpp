#include "../DoubleLinkedList/list.h"
#include <iostream>

int main()
{
    List myList;

    // push_front
    myList.push_front(10);
    myList.push_front(30);
    myList.push_front(20);

    // traverse after push front
    std::cout << "List after push front: ";
    myList.traverse();

    // insert
    myList.insert(1, 25);
    myList.insert(3, 15);
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
    } 
    else
    {
        std::cout << "invalid position" << std::endl;
    }

    std::cout << std::endl;

    // bubble sort
    std::cout << "List after Bubble Sort: ";
    myList.bubble();
    myList.traverse();

    myList.insert(1, 45);
    myList.insert(1, 65);

    // quick sort
    std::cout << "List after Quick Sort: ";
    myList.quick();
    myList.traverse();

    myList.insert(1, 11);
    myList.insert(1, 9);
    myList.insert(1, 6);

    // merge sort
    std::cout << "List after Merge Sort: ";
    myList.mergeSort();
    myList.traverse();

    std::cout << std::endl;

    // cycle for test
    // Node* firstNode = myList.getHead();
    // Node* lastNode = myList.getHead();

    // while (lastNode->next != nullptr)
    // {
    //     lastNode = lastNode->next;
    // }
    // lastNode->next = firstNode; // cycle

    // if (myList.hasCycle()) 
    // {
    //     std::cout << "[YES]" << std::endl;
    // } 
    // else
    // {
    //     std::cout << "[NO]" << std::endl;
    // }

    std::cout << "Click Enter to close" << std::endl;
    std::cin.get();
    return 0;
}

#ifndef LIST_H
#define LIST_H

#include "../DoubleLinkedList/node.h"

class List
{
private:
    Node* head;
    Node* tail;

public:
    List();
    ~List();

    void reverse();
    int findNthFromEnd(int n);

    void push_front(int val);
    void pop_front();
    void insert(int position, int val);
    
    void traverse() const;
    bool hasCycle() const;

    Node* getHead() const;

    //bubble sort
    void bubble();
    
    //quicksort
    void quick();
    Node* partition(Node* low, Node* high);
    void quickSortUtil(Node* low, Node* high);
    
    // merge sort
    Node* mergeSortUtil(Node* head);
    Node* merge(Node* first, Node* second);
    void mergeSort(); 
};

#endif //LIST_H
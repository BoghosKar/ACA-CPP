#ifndef LIST_H
#define LIST_H

#include "../SingleLinkedList\node.h"

class List
{
private:
    Node* head;

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
};

#endif //LIST_H
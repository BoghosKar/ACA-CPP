#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {};
};

#endif //NODE_H
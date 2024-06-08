#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {};
};

#endif //NODE_H
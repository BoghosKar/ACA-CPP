#ifndef MY_FORWARD_LIST_H
#define MY_FORWARD_LIST_H

#include <cstddef>
#include <stdexcept>

class MyForwardList
{
public:
    MyForwardList();
    ~MyForwardList();
    void push_front(int value);
    void pop_front();
    std::size_t size() const;
    bool empty() const;

    int front() const;

private:
    struct Node
    {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;
    std::size_t currentSize;
};

#endif // MY_FORWARD_LIST_H

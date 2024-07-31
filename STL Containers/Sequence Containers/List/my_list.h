#ifndef MY_LIST_H
#define MY_LIST_H

#include <cstddef>
#include <stdexcept>

class MyList
{
public:
    MyList();
    ~MyList();
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    std::size_t size() const;
    bool empty() const;

    int front() const;
    int back() const;

private:
    struct Node
    {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    std::size_t currentSize;
};

#endif // MY_LIST_H

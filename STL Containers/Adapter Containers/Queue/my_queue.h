#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <deque>

class MyQueue
{
public:
    MyQueue();
    ~MyQueue();
    void push(int value);
    void pop();
    int front() const;
    int back() const;
    bool empty() const;
    std::size_t size() const;

private:
    std::deque<int> container;
};

#endif // MY_QUEUE_H

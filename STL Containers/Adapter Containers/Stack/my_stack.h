#ifndef MY_STACK_H
#define MY_STACK_H

#include <deque>

class MyStack
{
public:
    MyStack();
    ~MyStack();
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    std::size_t size() const;

private:
    std::deque<int> container;
};

#endif // MY_STACK_H

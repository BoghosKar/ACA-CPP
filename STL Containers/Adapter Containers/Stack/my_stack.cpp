#include "my_stack.h"

MyStack::MyStack() {}

MyStack::~MyStack() {}

void MyStack::push(int value)
{
    container.push_back(value);
}

void MyStack::pop()
{
    if (!container.empty())
    {
        container.pop_back();
    }
}

int MyStack::top() const
{
    return container.back();
}

bool MyStack::empty() const
{
    return container.empty();
}

std::size_t MyStack::size() const
{
    return container.size();
}

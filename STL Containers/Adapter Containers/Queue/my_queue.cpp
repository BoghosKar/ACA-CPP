#include "my_queue.h"

MyQueue::MyQueue() {}

MyQueue::~MyQueue() {}

void MyQueue::push(int value)
{
    container.push_back(value);
}

void MyQueue::pop()
{
    if (!container.empty())
    {
        container.pop_front();
    }
}

int MyQueue::front() const
{
    return container.front();
}

int MyQueue::back() const
{
    return container.back();
}

bool MyQueue::empty() const
{
    return container.empty();
}

std::size_t MyQueue::size() const
{
    return container.size();
}

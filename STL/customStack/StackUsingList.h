#ifndef STACKUSINGLIST_H
#define STACKUSINGLIST_H

#include "CustomForwardList.h"

class StackUsingList
{
private:
    ForwardList list;

public:
    void push(int val)
    {
        list.push_front(val);
    }

    void pop()
    {
        if(list.empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        list.pop_front();
    }

    int top() const
    {
        if(list.empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return list.front();
    }

    bool empty() const
    {
        return list.empty();
    }
};

#endif // STACKUSINGLIST_H
#ifndef STACKUSINGVECTOR_H
#define STACKUSINGVECTOR_H

#include <vector>
#include <stdexcept>

class StackUsingVector
{
private:
    std::vector<int> vec;

public:
    void push(int val)
    {
        vec.push_back(val);
    }
    
    void pop()
    {
        if (vec.empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        vec.pop_back();
    }

    int top() const
    {
        if (vec.empty())
        {
            throw std::out_of_range("Stack is empty");
        }

        return vec.back();
    }

    bool empty() const
    {
        return vec.empty();
    }
};

#endif // STACKUSINGVECTOR_H

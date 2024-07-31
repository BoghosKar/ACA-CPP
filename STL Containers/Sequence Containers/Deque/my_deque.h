#ifndef MY_DEQUE_H
#define MY_DEQUE_H

#include <cstddef>
#include <stdexcept>

class MyDeque
{
public:
    MyDeque();
    ~MyDeque();
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    std::size_t size() const;
    bool empty() const;

private:
    void resize();
    
    int* data;
    std::size_t capacity;
    std::size_t currentSize;
    std::size_t frontIndex;
};

#endif // MY_DEQUE_H

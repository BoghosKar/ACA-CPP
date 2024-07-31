#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <stdexcept>

class MyVector
{
public:
    MyVector();
    ~MyVector();
    void push_back(int value);
    void pop_back();
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    std::size_t size() const;
    bool empty() const;
    
private:
    void resize();
    
    int* data;
    std::size_t capacity;
    std::size_t currentSize;
};

#endif // MY_VECTOR_H

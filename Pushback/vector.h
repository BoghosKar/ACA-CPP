#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    ~Vector();

    void push_back(const T& value);
    T& operator [] (int index);
    int size() const;
    int capacity() const;

private:
    T* data;
    int vecSize;
    int vecCapacity;
    void resize();
};

#endif // VECTOR_H
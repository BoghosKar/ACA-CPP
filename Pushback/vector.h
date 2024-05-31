#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
public:
    Vector(std::initializer_list<T> initList);
    Vector();
    ~Vector();

    void push_back(const T& value);
    void push_front(const T& value);

    void insert(const int position, const T& value);

    void pop_back();
    void pop_front();

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
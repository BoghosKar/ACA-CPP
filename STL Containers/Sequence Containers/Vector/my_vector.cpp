#include "my_vector.h"
#include <algorithm>

MyVector::MyVector() : data(nullptr), capacity(0), currentSize(0) {}

MyVector::~MyVector()
{
    delete[] data;
}

void MyVector::push_back(int value)
{
    if (currentSize == capacity)
    {
        resize();
    }
    data[currentSize++] = value;
}

void MyVector::pop_back()
{
    if (empty())
    {
        throw std::out_of_range("vector empty");
    }
    --currentSize;
}

int& MyVector::operator[](std::size_t index)
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int& MyVector::operator[](std::size_t index) const
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

std::size_t MyVector::size() const
{
    return currentSize;
}

bool MyVector::empty() const
{
    return currentSize == 0;
}

void MyVector::resize()
{
    std::size_t newCapacity;
    if (capacity == 0)
    {
        newCapacity = 1;
    } else
    {
        newCapacity = 2 * capacity;
    }
    
    int* newData = new int[newCapacity];
    if (data)
    {
        std::copy(data, data + currentSize, newData);
        delete[] data;
    }
    data = newData;
    capacity = newCapacity;
}

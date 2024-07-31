#include "my_deque.h"
#include <algorithm>

MyDeque::MyDeque() : data(nullptr), capacity(0), currentSize(0), frontIndex(0) {}

MyDeque::~MyDeque()
{
    delete[] data;
}

void MyDeque::push_back(int value)
{
    if (currentSize == capacity)
    {
        resize();
    }
    data[(frontIndex + currentSize) % capacity] = value;
    ++currentSize;
}

void MyDeque::push_front(int value)
{
    if (currentSize == capacity)
    {
        resize();
    }
    if (frontIndex == 0)
    {
        frontIndex = capacity - 1;
    } else
    {
        --frontIndex;
    }
    data[frontIndex] = value;
    ++currentSize;
}

void MyDeque::pop_back()
{
    if (empty())
    {
        throw std::out_of_range("deque empty");
    }
    --currentSize;
}

void MyDeque::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("deque empty");
    }
    frontIndex = (frontIndex + 1) % capacity;
    --currentSize;
}

int& MyDeque::operator[](std::size_t index)
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[(frontIndex + index) % capacity];
}

const int& MyDeque::operator[](std::size_t index) const
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[(frontIndex + index) % capacity];
}

std::size_t MyDeque::size() const
{
    return currentSize;
}

bool MyDeque::empty() const
{
    return currentSize == 0;
}

void MyDeque::resize()
{
    std::size_t newCapacity;
    if (capacity == 0) {
        newCapacity = 1;
    } else {
        newCapacity = 2 * capacity;
    }

    int* newData = new int[newCapacity];
    for (std::size_t i = 0; i < currentSize; ++i)
    {
        newData[i] = data[(frontIndex + i) % capacity];
    }
    delete[] data;
    data = newData;
    frontIndex = 0;
    capacity = newCapacity;
}

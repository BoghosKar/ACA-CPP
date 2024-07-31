#ifndef MY_UNORDERED_SET_H
#define MY_UNORDERED_SET_H

#include <vector>
#include <list>
#include <cstddef>

class MyUnorderedSet
{
public:
    MyUnorderedSet();
    ~MyUnorderedSet();
    void insert(int value);
    void erase(int value);
    bool contains(int value) const;
    std::size_t size() const;
    bool empty() const;

private:
    std::vector<std::list<int>> table;
    std::size_t currentSize;
    std::size_t hash(int value) const;
    void rehash();
};

#endif // MY_UNORDERED_SET_H

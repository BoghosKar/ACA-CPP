#ifndef MY_UNORDERED_MULTISET_H
#define MY_UNORDERED_MULTISET_H

#include <vector>
#include <list>
#include <cstddef>

class MyUnorderedMultiset
{
public:
    MyUnorderedMultiset();
    ~MyUnorderedMultiset();
    void insert(int value);
    void erase(int value);
    std::size_t count(int value) const;
    std::size_t size() const;
    bool empty() const;

private:
    std::vector<std::list<int>> table;
    std::size_t currentSize;
    std::size_t hash(int value) const;
    void rehash();
};

#endif // MY_UNORDERED_MULTISET_H

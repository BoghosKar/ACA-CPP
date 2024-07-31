#include "my_unordered_multiset.h"
#include <algorithm>

MyUnorderedMultiset::MyUnorderedMultiset() : table(8), currentSize(0) {}

MyUnorderedMultiset::~MyUnorderedMultiset() {}

void MyUnorderedMultiset::insert(int value)
{
    if (currentSize == table.size())
    {
        rehash();
    }

    std::size_t index = hash(value);
    table[index].push_back(value);
    ++currentSize;
}

void MyUnorderedMultiset::erase(int value)
{
    std::size_t index = hash(value);
    auto& chain = table[index];
    auto it = std::find(chain.begin(), chain.end(), value);
    if (it != chain.end())
    {
        chain.erase(it);
        --currentSize;
    }
}

std::size_t MyUnorderedMultiset::count(int value) const
{
    std::size_t index = hash(value);
    const auto& chain = table[index];
    return std::count(chain.begin(), chain.end(), value);
}

std::size_t MyUnorderedMultiset::size() const
{
    return currentSize;
}

bool MyUnorderedMultiset::empty() const
{
    return currentSize == 0;
}

std::size_t MyUnorderedMultiset::hash(int value) const
{
    return std::hash<int>{}(value) % table.size();
}

void MyUnorderedMultiset::rehash()
{
    std::vector<std::list<int>> newTable(table.size() * 2);

    for (const auto& chain : table)
    {
        for (int value : chain)
        {
            std::size_t index = std::hash<int>{}(value) % newTable.size();
            newTable[index].push_back(value);
        }
    }

    table.swap(newTable);
}

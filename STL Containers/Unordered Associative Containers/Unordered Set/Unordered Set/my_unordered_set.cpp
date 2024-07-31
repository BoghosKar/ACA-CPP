#include "my_unordered_set.h"
#include <algorithm>

MyUnorderedSet::MyUnorderedSet() : table(8), currentSize(0) {}

MyUnorderedSet::~MyUnorderedSet() {}

void MyUnorderedSet::insert(int value)
{
    if (contains(value))
    {
        return;
    }

    if (currentSize == table.size())
    {
        rehash();
    }

    std::size_t index = hash(value);
    table[index].push_back(value);
    ++currentSize;
}

void MyUnorderedSet::erase(int value)
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

bool MyUnorderedSet::contains(int value) const
{
    std::size_t index = hash(value);
    const auto& chain = table[index];
    return std::find(chain.begin(), chain.end(), value) != chain.end();
}

std::size_t MyUnorderedSet::size() const
{
    return currentSize;
}

bool MyUnorderedSet::empty() const
{
    return currentSize == 0;
}

std::size_t MyUnorderedSet::hash(int value) const
{
    return std::hash<int>{}(value) % table.size();
}

void MyUnorderedSet::rehash()
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

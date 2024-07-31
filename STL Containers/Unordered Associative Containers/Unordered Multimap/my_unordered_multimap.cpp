#include "my_unordered_multimap.h"
#include <algorithm>

MyUnorderedMultimap::MyUnorderedMultimap() : table(8), currentSize(0) {}

MyUnorderedMultimap::~MyUnorderedMultimap() {}

void MyUnorderedMultimap::insert(const std::string& key, int value)
{
    if (currentSize == table.size())
    {
        rehash();
    }

    std::size_t index = hash(key);
    table[index].emplace_back(key, value);
    ++currentSize;
}

void MyUnorderedMultimap::erase(const std::string& key)
{
    std::size_t index = hash(key);
    auto& chain = table[index];
    auto it = std::remove_if(chain.begin(), chain.end(), [&key](const std::pair<std::string, int>& pair)
    {
        return pair.first == key;
    });

    if (it != chain.end())
    {
        chain.erase(it, chain.end());
        --currentSize;
    }
}

std::vector<int> MyUnorderedMultimap::find(const std::string& key) const
{
    std::vector<int> values;
    std::size_t index = hash(key);
    const auto& chain = table[index];

    for (const auto& pair : chain)
    {
        if (pair.first == key)
        {
            values.push_back(pair.second);
        }
    }

    return values;
}

std::size_t MyUnorderedMultimap::size() const
{
    return currentSize;
}

bool MyUnorderedMultimap::empty() const
{
    return currentSize == 0;
}

std::size_t MyUnorderedMultimap::hash(const std::string& key) const
{
    return std::hash<std::string>{}(key) % table.size();
}

void MyUnorderedMultimap::rehash()
{
    std::vector<std::list<std::pair<std::string, int>>> newTable(table.size() * 2);

    for (const auto& chain : table)
    {
        for (const auto& pair : chain)
        {
            std::size_t index = std::hash<std::string>{}(pair.first) % newTable.size();
            newTable[index].push_back(pair);
        }
    }

    table.swap(newTable);
}

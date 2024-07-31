#include "my_unordered_map.h"
#include <algorithm>

MyUnorderedMap::MyUnorderedMap() : table(8), currentSize(0) {}

MyUnorderedMap::~MyUnorderedMap() {}

void MyUnorderedMap::insert(const std::string& key, int value)
{
    std::size_t index = hash(key);
    auto& chain = table[index];
    for (auto& pair : chain)
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    chain.emplace_back(key, value);
    ++currentSize;

    if (currentSize == table.size())
    {
        rehash();
    }
}

void MyUnorderedMap::erase(const std::string& key)
{
    std::size_t index = hash(key);
    auto& chain = table[index];
    auto it = std::find_if(chain.begin(), chain.end(), [&key](const std::pair<std::string, int>& pair)
    {
        return pair.first == key;
    });

    if (it != chain.end())
    {
        chain.erase(it);
        --currentSize;
    }
}

int& MyUnorderedMap::operator[](const std::string& key)
{
    std::size_t index = hash(key);
    auto& chain = table[index];
    for (auto& pair : chain)
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }

    chain.emplace_back(key, 0);
    ++currentSize;

    if (currentSize == table.size())
    {
        rehash();
    }

    return chain.back().second;
}

std::size_t MyUnorderedMap::size() const
{
    return currentSize;
}

bool MyUnorderedMap::empty() const
{
    return currentSize == 0;
}

std::size_t MyUnorderedMap::hash(const std::string& key) const
{
    return std::hash<std::string>{}(key) % table.size();
}

void MyUnorderedMap::rehash()
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

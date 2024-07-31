#ifndef MY_UNORDERED_MAP_H
#define MY_UNORDERED_MAP_H

#include <vector>
#include <list>
#include <string>
#include <cstddef>
#include <utility>

class MyUnorderedMap
{
public:
    MyUnorderedMap();
    ~MyUnorderedMap();
    void insert(const std::string& key, int value);
    void erase(const std::string& key);
    int& operator[](const std::string& key);
    std::size_t size() const;
    bool empty() const;

private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    std::size_t currentSize;
    std::size_t hash(const std::string& key) const;
    void rehash();
};

#endif // MY_UNORDERED_MAP_H

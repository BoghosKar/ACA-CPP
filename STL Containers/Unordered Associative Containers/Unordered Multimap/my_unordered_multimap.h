#ifndef MY_UNORDERED_MULTIMAP_H
#define MY_UNORDERED_MULTIMAP_H

#include <vector>
#include <list>
#include <string>
#include <cstddef>
#include <utility>

class MyUnorderedMultimap
{
public:
    MyUnorderedMultimap();
    ~MyUnorderedMultimap();
    void insert(const std::string& key, int value);
    void erase(const std::string& key);
    std::vector<int> find(const std::string& key) const;
    std::size_t size() const;
    bool empty() const;

private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    std::size_t currentSize;
    std::size_t hash(const std::string& key) const;
    void rehash();
};

#endif // MY_UNORDERED_MULTIMAP_H

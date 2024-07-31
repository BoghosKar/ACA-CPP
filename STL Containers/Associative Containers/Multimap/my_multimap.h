#ifndef MY_MULTIMAP_H
#define MY_MULTIMAP_H

#include <string>
#include <vector>
#include <cstddef>
#include <stdexcept>

class MyMultimap
{
public:
    MyMultimap();
    ~MyMultimap();
    void insert(const std::string& key, int value);
    void erase(const std::string& key);
    std::vector<int> find(const std::string& key) const;
    std::size_t size() const;
    bool empty() const;

private:
    struct Node
    {
        std::string key;
        std::vector<int> values;
        Node* left;
        Node* right;
        Node(const std::string& k, int v) : key(k), left(nullptr), right(nullptr) { values.push_back(v); }
    };

    Node* root;
    std::size_t currentSize;

    void insert(Node*& node, const std::string& key, int value);
    void erase(Node*& node, const std::string& key);
    Node* find(Node* node, const std::string& key) const;
    void destroy(Node* node);
};

#endif // MY_MULTIMAP_H

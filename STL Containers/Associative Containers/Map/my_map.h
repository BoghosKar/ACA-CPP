#ifndef MY_MAP_H
#define MY_MAP_H

#include <string>
#include <cstddef>
#include <stdexcept>

class MyMap
{
public:
    MyMap();
    ~MyMap();
    void insert(const std::string& key, int value);
    void erase(const std::string& key);
    int& operator[](const std::string& key);
    std::size_t size() const;
    bool empty() const;

private:
    struct Node
    {
        std::string key;
        int value;
        Node* left;
        Node* right;
        Node(const std::string& k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;
    std::size_t currentSize;

    void insert(Node*& node, const std::string& key, int value);
    void erase(Node*& node, const std::string& key);
    Node* find(Node* node, const std::string& key) const;
    void destroy(Node* node);
};

#endif // MY_MAP_H

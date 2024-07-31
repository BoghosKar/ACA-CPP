#ifndef MY_MULTISET_H
#define MY_MULTISET_H

#include <cstddef>
#include <stdexcept>

class MyMultiset
{
public:
    MyMultiset();
    ~MyMultiset();
    void insert(int value);
    void erase(int value);
    std::size_t count(int value) const;
    std::size_t size() const;
    bool empty() const;

private:
    struct Node
    {
        int data;
        int count;
        Node* left;
        Node* right;
        Node(int value) : data(value), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;
    std::size_t currentSize;

    void insert(Node*& node, int value);
    void erase(Node*& node, int value);
    Node* find_min(Node* node) const;
    void destroy(Node* node);
};

#endif // MY_MULTISET_H

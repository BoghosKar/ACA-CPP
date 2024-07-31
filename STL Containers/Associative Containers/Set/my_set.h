#ifndef MY_SET_H
#define MY_SET_H

#include <cstddef>
#include <stdexcept>

class MySet
{
public:
    MySet();
    ~MySet();
    void insert(int value);
    void erase(int value);
    bool contains(int value) const;
    std::size_t size() const;
    bool empty() const;

private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    std::size_t currentSize;

    void insert(Node*& node, int value);
    void erase(Node*& node, int value);
    bool contains(Node* node, int value) const;
    void destroy(Node* node);
};

#endif // MY_SET_H

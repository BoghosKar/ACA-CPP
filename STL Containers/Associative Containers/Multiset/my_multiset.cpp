#include "my_multiset.h"

MyMultiset::MyMultiset() : root(nullptr), currentSize(0) {}

MyMultiset::~MyMultiset()
{
    destroy(root);
}

void MyMultiset::insert(int value)
{
    insert(root, value);
    ++currentSize;
}

void MyMultiset::erase(int value)
{
    if (count(value) > 0)
    {
        erase(root, value);
        --currentSize;
    }
}

std::size_t MyMultiset::count(int value) const
{
    Node* node = root;
    while (node != nullptr)
    {
        if (value < node->data)
        {
            node = node->left;
        } else if (value > node->data) {
            node = node->right;
        } else {
            return node->count;
        }
    }
    return 0;
}

std::size_t MyMultiset::size() const
{
    return currentSize;
}

bool MyMultiset::empty() const
{
    return currentSize == 0;
}

void MyMultiset::insert(Node*& node, int value)
{
    if (node == nullptr)
    {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    } else {
        ++node->count;
    }
}

void MyMultiset::erase(Node*& node, int value)
{
    if (node == nullptr) return;

    if (value < node->data)
    {
        erase(node->left, value);
    } else if (value > node->data) {
        erase(node->right, value);
    } else
    {
        if (node->count > 1)
        {
            --node->count;
        } else {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* oldNode = node;
                node = node->right;
                delete oldNode;
            } else if (node->right == nullptr) {
                Node* oldNode = node;
                node = node->left;
                delete oldNode;
            } else {
                Node* successor = find_min(node->right);
                node->data = successor->data;
                node->count = successor->count;
                erase(node->right, successor->data);
                successor->count = 1;
            }
        }
    }
}

MyMultiset::Node* MyMultiset::find_min(Node* node) const
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

void MyMultiset::destroy(Node* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

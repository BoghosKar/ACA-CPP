#include "my_set.h"

MySet::MySet() : root(nullptr), currentSize(0) {}

MySet::~MySet()
{
    destroy(root);
}

void MySet::insert(int value)
{
    if (!contains(value))
    {
        insert(root, value);
        ++currentSize;
    }
}

void MySet::erase(int value)
{
    if (contains(value))
    {
        erase(root, value);
        --currentSize;
    }
}

bool MySet::contains(int value) const
{
    return contains(root, value);
}

std::size_t MySet::size() const
{
    return currentSize;
}

bool MySet::empty() const
{
    return currentSize == 0;
}

void MySet::insert(Node*& node, int value)
{
    if (node == nullptr)
    {
        node = new Node(value);
    } else if (value < node->data)
    {
        insert(node->left, value);
    } else
    {
        insert(node->right, value);
    }
}

void MySet::erase(Node*& node, int value) 
{
    if (node == nullptr) return;

    if (value < node->data)
    {
        erase(node->left, value);
    } else if (value > node->data) {
        erase(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr)
        {
            Node* oldNode = node;
            node = node->right;
            delete oldNode;
        } else if (node->right == nullptr)
        {
            Node* oldNode = node;
            node = node->left;
            delete oldNode;
        } else
        {
            Node* successor = node->right;
            while (successor->left != nullptr)
            {
                successor = successor->left;
            }
            node->data = successor->data;
            erase(node->right, successor->data);
        }
    }
}

bool MySet::contains(Node* node, int value) const
{
    if (node == nullptr) return false;
    if (value < node->data)
    {
        return contains(node->left, value);
    } else if (value > node->data)
    {
        return contains(node->right, value);
    } else {
        return true;
    }
}

void MySet::destroy(Node* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

#include "my_map.h"

MyMap::MyMap() : root(nullptr), currentSize(0) {}

MyMap::~MyMap()
{
    destroy(root);
}

void MyMap::insert(const std::string& key, int value)
{
    insert(root, key, value);
    ++currentSize;
}

void MyMap::erase(const std::string& key)
{
    erase(root, key);
    --currentSize;
}

int& MyMap::operator [] (const std::string& key)
{
    Node* node = find(root, key);
    if (node == nullptr)
    {
        insert(root, key, 0);
        node = find(root, key);
    }
    return node->value;
}

std::size_t MyMap::size() const
{
    return currentSize;
}

bool MyMap::empty() const
{
    return currentSize == 0;
}

void MyMap::insert(Node*& node, const std::string& key, int value)
{
    if (node == nullptr)
    {
        node = new Node(key, value);
    } else if (key < node->key)
    {
        insert(node->left, key, value);
    } else if (key > node->key)
    {
        insert(node->right, key, value);
    } else
    {
        node->value = value;
    }
}

void MyMap::erase(Node*& node, const std::string& key)
{
    if (node == nullptr)
    {
        return;
    }

    if (key < node->key)
    {
        erase(node->left, key);
    } else if (key > node->key)
    {
        erase(node->right, key);
    } else
    {
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

            node->key = successor->key;
            node->value = successor->value;
            erase(node->right, successor->key);
        }
    }
}

MyMap::Node* MyMap::find(Node* node, const std::string& key) const
{
    if (node == nullptr) return nullptr;
    if (key < node->key)
    {
        return find(node->left, key);
    } else if (key > node->key)
    {
        return find(node->right, key);
    } else
    {
        return node;
    }
}

void MyMap::destroy(Node* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

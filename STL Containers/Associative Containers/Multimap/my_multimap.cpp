#include "my_multimap.h"

MyMultimap::MyMultimap() : root(nullptr), currentSize(0) {}

MyMultimap::~MyMultimap()
{
    destroy(root);
}

void MyMultimap::insert(const std::string& key, int value)
{
    insert(root, key, value);
    ++currentSize;
}

void MyMultimap::erase(const std::string& key)
{
    erase(root, key);
    --currentSize;
}

std::vector<int> MyMultimap::find(const std::string& key) const
{
    Node* node = find(root, key);
    if (node != nullptr)
    {
        return node->values;
    }
    return std::vector<int>();
}

std::size_t MyMultimap::size() const
{
    return currentSize;
}

bool MyMultimap::empty() const
{
    return currentSize == 0;
}

void MyMultimap::insert(Node*& node, const std::string& key, int value)
{
    if (node == nullptr) {
        node = new Node(key, value);
    } else if (key < node->key) {
        insert(node->left, key, value);
    } else if (key > node->key) {
        insert(node->right, key, value);
    } else {
        node->values.push_back(value);
    }
}

void MyMultimap::erase(Node*& node, const std::string& key)
{
    if (node == nullptr) return;

    if (key < node->key) {
        erase(node->left, key);
    } else if (key > node->key) {
        erase(node->right, key);
    } else
    {
        if (node->left == nullptr && node->right == nullptr) {
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
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->key = successor->key;
            node->values = successor->values;
            erase(node->right, successor->key);
        }
    }
}

MyMultimap::Node* MyMultimap::find(Node* node, const std::string& key) const
{
    if (node == nullptr) return nullptr;
    if (key < node->key) {
        return find(node->left, key);
    } else if (key > node->key) {
        return find(node->right, key);
    } else {
        return node;
    }
}

void MyMultimap::destroy(Node* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

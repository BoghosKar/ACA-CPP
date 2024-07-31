#include "my_list.h"

MyList::MyList() : head(nullptr), tail(nullptr), currentSize(0) {}

MyList::~MyList()
{
    while (!empty())
    {
        pop_front();
    }
}

void MyList::push_back(int value)
{
    Node* newNode = new Node(value);
    if (tail)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        head = tail = newNode;
    }
    ++currentSize;
}

void MyList::push_front(int value)
{
    Node* newNode = new Node(value);
    if (head)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    } else{
        head = tail = newNode;
    }
    ++currentSize;
}

void MyList::pop_back()
{
    if (empty())
    {
        throw std::out_of_range("list empty");
    }

    Node* oldTail = tail;
    tail = tail->prev;
    if (tail)
    {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete oldTail;
    --currentSize;
}

void MyList::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("list empty");
    }
    Node* oldHead = head;
    head = head->next;

    if (head)
    {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete oldHead;
    --currentSize;
}

std::size_t MyList::size() const
{
    return currentSize;
}

bool MyList::empty() const
{
    return currentSize == 0;
}

int MyList::front() const
{
    if (empty())
    {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

int MyList::back() const
{
    if (empty())
    {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}
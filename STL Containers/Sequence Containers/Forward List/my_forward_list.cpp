#include "my_forward_list.h"

MyForwardList::MyForwardList() : head(nullptr), currentSize(0) {}

MyForwardList::~MyForwardList()
{
    while (!empty())
    {
        pop_front();
    }
}

void MyForwardList::push_front(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    ++currentSize;
}

void MyForwardList::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("list empty");
    }
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    --currentSize;
}

std::size_t MyForwardList::size() const
{
    return currentSize;
}

bool MyForwardList::empty() const
{
    return currentSize == 0;
}

int MyForwardList::front() const
{
    if (empty())
    {
        throw std::out_of_range("List is empty.");
    }
    return head->data;
}
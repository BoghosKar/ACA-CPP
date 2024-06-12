#ifndef CUSTOMFORWARDLIST_H
#define CUSTOMFORWARDLIST_H

#include <stdexcept>

class Node
{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class ForwardList
{
private:
    Node* head;

public:
    ForwardList() : head(nullptr) {}
    ~ForwardList();
    void push_front(int val);
    void pop_front();
    int front() const;
    bool empty() const;

    class Iterator
    {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        Iterator& operator++()
        {
            if (current) current = current->next;
            return *this;
        }
        
        int& operator * ()
        {
            return current->data;
        }
        
        bool operator != (const Iterator& other) const
        {
            return current != other.current;
        }
    };

    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }
};

ForwardList::~ForwardList()
{
    while(head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void ForwardList::push_front(int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void ForwardList::pop_front()
{
    if(head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int ForwardList::front() const
{
    if(head)
    {
        return head->data;
    }

    throw std::out_of_range("List is empty");
}

bool ForwardList::empty() const
{
    return head == nullptr;
}

#endif // CUSTOMFORWARDLIST_H

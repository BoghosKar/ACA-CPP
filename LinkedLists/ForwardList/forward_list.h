#ifndef FORWARD_LIST
#define FORWARD_LIST

#include "../ForwardList/node.h"
#include <iostream>

class ForwardList
{
private:
    Node* head;

public:
    ForwardList() : head(nullptr) {}
    
    ~ForwardList()
    {
        Node* current = head;
        while(current !=nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    Node* getHead() const
    {
        return head;
    }


    void push_front(int data) 
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }


    class Iterator // <- nested class inside ForwardList class 
    {
    private:
        Node* current;
    
    public:
        Iterator(Node* node) : current(node) {}

        int operator * () const
        {
            return current->data;
        }

        Iterator& operator ++ ()
        {
            current = current->next;
            return *this;
        }

        bool operator == (const Iterator& other) const
        {
            return current == other.current;
        }

        bool operator != (const Iterator& other) const
        {
            return current != other.current;
        }
    };


    Iterator begin() const
    {
        return Iterator(head);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }
};


#endif // FORWARD_LIST_H
#include "../LinkedList/list.h"
#include <iostream>

List::List() : head(nullptr) {};

List::~List()
{
    while(head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::reverse()
{
    if (head == nullptr || head->next == nullptr) 
    {
        return;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int List::findNthFromEnd(int n)
{
    if (head == nullptr || n <= 0)
    {
        return 1; 
    }

    Node* first = head;
    Node* second = head;

   for (int i = 0; i < n; ++i)
    {
        if (first == nullptr)
        {
            return -1;
        }
        first = first->next;
    }

    while (first != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    return second->data;
}


void List::push_front(int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void List::pop_front()
{
    if(head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::insert(int position, int val)
{
    if(position <= 0 || head == nullptr)
    {
        push_front(val);
        return;
    }

    Node* current = head;
    for(int i = 1; current != nullptr && i < position; i++)
    {
        current = current -> next;
    }

    if(current == nullptr)
    {
        push_front(val);
    }else
    {
        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
    }
}


void List::traverse() const
{
    Node* current = head;
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool List::hasCycle() const
{
    if(head == nullptr)
    {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

Node* List::getHead() const
{
    return head;
}
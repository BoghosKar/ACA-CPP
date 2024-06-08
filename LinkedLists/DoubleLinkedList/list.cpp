#include "../DoubleLinkedList/list.h"
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



//SORTING

void List::bubble()
{
    if(!head)
    {
        return;
    }

    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        Node* current = head;

        while(current->next != nullptr) //checks if there is a node in the next slot
        {
            if(current->data > current->next->data) //checks if currents data is bigger than the next ones data
            {
                std::swap(current->data, current->next->data); // swaps the current data with the next ones data
                swapped = true;
            }
            current = current->next;
        }
    }
}


// QUICKSORT
void List::quick()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node* high = head;
    while (high->next != nullptr)
    {
        high = high->next;
    }

    quickSortUtil(head, high);
}

Node* List::partition(Node* low, Node* high)
{
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next)
    {
        if (j->data <= pivot)
        {
            i = (i == nullptr) ? low : i->next;
            std::swap(i->data, j->data);
        }
    }

    if (i == nullptr)
    {
        i = low;
    }else
    {
        i = i->next;
    }

    std::swap(i->data, high->data);
    return i;
}

void List::quickSortUtil(Node* low, Node* high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        Node* p = partition(low, high);
        quickSortUtil(low, p->prev);
        quickSortUtil(p->next, high);
    }
}
// QUICKSORT




// merge sort
Node* List::mergeSortUtil(Node* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    // Splitting the list into two halves
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = nullptr;
    if (second != nullptr)
    {
        second->prev = nullptr;
    }

    head = mergeSortUtil(head);
    second = mergeSortUtil(second);

    return merge(head, second);
}

Node* List::merge(Node* first, Node* second)
{
    if (!first)
    {
        return second;
    }
    if (!second)
    {
        return first;
    }

    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = nullptr;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = nullptr;
        return second;
    }
}

void List::mergeSort()
{
    head = mergeSortUtil(head);

    Node* temp = head;
    while (temp && temp->next)
    {
        temp = temp->next;
    }

    tail = temp;
}

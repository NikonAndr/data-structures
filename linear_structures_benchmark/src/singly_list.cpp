#include "singly_list.h"
#include <iostream>

//constructor
SinglyList::SinglyList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//copy constructor
SinglyList::SinglyList(const SinglyList& other)
{
    head = nullptr;
    tail = nullptr;
    size = 0;

    S_Node* temp = other.head;

    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->next;
    }
}

//assign operator
SinglyList& SinglyList::operator=(const SinglyList& other)
{
    SinglyList temp(other);

    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    std::swap(size, temp.size);

    return *this;
}

//destructor, free memory
SinglyList::~SinglyList() {
    S_Node* current = head;

    while (current != nullptr)
    {
        S_Node* temp = current;
        current = current->next;
        delete temp;   
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

//push_back method
void SinglyList::push_back(int val)
{
    S_Node* n = new S_Node;
    n->data = val;
    n->next = nullptr;

    //list is empty
    if (head == nullptr)
    {
        head = tail = n; 
        size++;
        return;
    }

    //if list is not empty
    tail->next = n;
    tail = n;

    size++;
}

//push_front method
void SinglyList::push_front(int val)
{
    S_Node* n = new S_Node;
    n->data = val;
    n->next = nullptr;
    
    //if list is empty 
    if (head == nullptr)
    {
        head = tail = n;
    }
    //if list is not empty 
    else 
    {
        n->next = head;
        head = n;
    }

    size++;
}

void SinglyList::pop_back()
{
    //check if list is empty 
    if (head == nullptr)
    {
        std::cout << "you can't pop from an empty list" << std::endl;
        return;
    }
    //if list is one element
    else if (head == tail)
    {
        S_Node* temp = head;
        head = tail = nullptr;
        delete temp;
    }
    //if list has 2 or more elements
    else
    {
        S_Node* temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    size--;
}

void SinglyList::pop_front()
{
    //check if list is empty 
    if (head == nullptr)
    {
        std::cout << "you can't pop from an empty list" << std::endl;
        return;
    }
    //if list is one element
    else if (head==tail)
    {
        S_Node* temp = head;
        head = tail = nullptr;
        delete temp;
    }
    //if list has 2 or more elements
    else
    {
        S_Node* temp = head;
        head = head->next;
        delete temp;
    }

    size--;
}

//insert method at given index
void SinglyList::insert(int val, int index)
{
    //validate index 
    if (index < 0) {
        std::cout << "index out of range" << std::endl;
        return;
    }
    //check if list is not empty
    if (head == nullptr)
    {
        if (index == 0)
            push_front(val);
        else
            std::cout << "list is empty" << std::endl;
        return;
    }
    //insert at the index 0
    if (index == 0)
    {
        push_front(val);
        return;
    }

    S_Node* temp = head;
    int count = 0;

    while (temp != nullptr && count < index - 1)
    {
        temp = temp->next;
        count++;
    }
    
    if (temp == nullptr)
    {
        std::cout << "index out of range" << std::endl;
        return;
    }

    //insert at the back of the list
    if (temp == tail)
    {
        push_back(val);
        return;
    }

    //insert at given index (not 0 or last)
    S_Node * n = new S_Node;
    n->data = val;

    n->next = temp->next;
    temp->next = n;

    size++;
}

void SinglyList::remove(int index)
{
    //validate index 
    if (index < 0) {
        std::cout << "index out of range" << std::endl;
        return;
    }

    //remove at the index 0
    if (index == 0)
    {
        pop_front();
        return;
    }

    S_Node* temp = head;
    int count = 0;

    while(temp != nullptr && count < index - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        std::cout << "index out of range" << std::endl;
        return;
    }

    S_Node* to_delete = temp->next;
    //remove at the back of the list
    if (to_delete == tail)
    {
        pop_back();
        return;
    }

    //remove at given index (not 0 or last)
    temp->next = to_delete->next;
    delete to_delete;

    size--;
}

//returns index of given value in the list -> if value not in the list return -1
int SinglyList::find(int val)
{
    S_Node * temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        if (temp->data == val)
            return count;
        else 
        {
            temp = temp->next;
            count++;
        }
    }

    //index out of range, empty list, value not found 
    return -1;
}

int SinglyList::size_of() const
{
    return size;
}

//print list method
void SinglyList::print() const
{
    S_Node* temp = head;

    if (head == nullptr)
    {
        std::cout << "list is empty" << std::endl;
        return;
    }

    //print list
    while (temp != nullptr)
    {
        if (temp != tail)
        {
            std::cout << temp->data << " → ";
        }
        else
        {
            std::cout << temp->data << " → nullptr" << std::endl;
        }
        temp = temp->next;
    }
}
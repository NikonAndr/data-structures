#include "LinkedList.h"

#include <iostream>

LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::insert(int key, int value)
{
    Node* n = new Node;
    n->key = key;
    n->value = value;

    if (head == nullptr)
    {
        n->next = nullptr;
        head = n;
    }
    else 
    {
        n->next = head;
        head = n;
    }

    size++;
}

bool LinkedList::remove(int key)
{
    if (head == nullptr)
        return false;

    if (head->key == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        size--;
        return true;
    }

    Node* current = head->next;
    Node* prev = head;

    while (current != nullptr)
    {
        if (current->key == key)
        {
            prev->next = current->next;
            delete current;

            size--;

            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;
}

LinkedList::Node* LinkedList::find(int key)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

int LinkedList::get_size()
{
    return size;
}

LinkedList::Node* LinkedList::get_head()
{
    return head;
}

void LinkedList::print() const
{
    Node* temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->key << " : "  << temp->value;
        if (temp->next != nullptr)
        {
            std::cout << " -> ";
        }

        temp = temp->next;
    } 
}
#include "HashMapList.h"

#include <iostream>

double const LOAD_FACTOR = 0.99;

HashMapList::HashMapList()
{
    size = 0;
    capacity = 10;

    arr = new LinkedList[capacity];
}

HashMapList::~HashMapList()
{
    delete[] arr;
}

int HashMapList::hash(int key, int mod)
{
    return (key % mod + mod) % mod;
}

void HashMapList::resize()
{
    int new_capacity = capacity * 2;
    LinkedList* new_arr = new LinkedList[new_capacity];

    for (int i = 0; i < capacity; i++)
    {
        LinkedList::Node* temp = arr[i].get_head();

        while (temp != nullptr)
        {
            int new_index = hash(temp->key, new_capacity);
            new_arr[new_index].insert(temp->key, temp->value);

            temp = temp->next;
        }
    }

    delete[] arr;

    arr = new_arr;
    capacity = new_capacity;
}

void HashMapList::insert(int key, int value)
{
    if ((double)(size + 1) / capacity > LOAD_FACTOR)
        resize();

    int index = hash(key, capacity);

    LinkedList::Node* exists = arr[index].find(key);

    if (exists != nullptr)
    {
        exists->value = value;
        return;
    }

    arr[index].insert(key, value);

    size++;
}

void HashMapList::remove(int key)
{
    int index = hash(key, capacity);

    if (arr[index].remove(key))
    {
        size--;
    }
}

void HashMapList::print() const
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << "[";
        arr[i].print();
        std::cout << "] , ";
    }
}



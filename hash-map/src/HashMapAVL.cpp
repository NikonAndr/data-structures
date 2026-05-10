#include "HashMapAVL.h"

#include <iostream>

double const LOAD_FACTOR = 0.99;

HashMapAVL::HashMapAVL() 
{
    size = 0;
    capacity = 10;

    arr = new AVL[capacity];
}

HashMapAVL::~HashMapAVL()
{
    delete[] arr;
}

int HashMapAVL::hash(int key, int mod)
{
    return (key % mod + mod) % mod;
}

void HashMapAVL::resize()
{
    int new_capacity = capacity * 2;
    AVL* new_arr = new AVL[new_capacity];

    for (int i = 0; i < capacity; i++)
    {
        arr[i].traverse([&](int key, int value)
        {
            int index = hash(key, new_capacity);
            new_arr[index].insert(key, value);
        });
    }

    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

void HashMapAVL::insert(int key, int value)
{
    if ((double)(size + 1) / capacity > LOAD_FACTOR)
        resize();
    
    int index = hash(key, capacity);

    if(arr[index].insert(key, value))
        size++;
}

void HashMapAVL::remove(int key)
{
    int index = hash(key, capacity);

    if(arr[index].remove(key))
        size--;
}

void HashMapAVL::print() const
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << "[" << std::endl;
        arr[i].print();
        std::cout << "\n]" << std::endl;
    }
}
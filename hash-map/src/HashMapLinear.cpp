#include "HashMapLinear.h"

#include <iostream>

double const LOAD_FACTOR = 0.75;

HashMapLinear::HashMapLinear()
{
    size = 0;
    capacity = 10;

    arr = new Entry[capacity];
}

HashMapLinear::~HashMapLinear()
{
    delete[] arr;
}

int HashMapLinear::hash(int key, int mod)
{
    return (key % mod + mod) % mod;
}

void HashMapLinear::resize()
{
    int old_capacity = capacity;
    capacity *= 2;

    Entry* old_arr = arr;
    arr= new Entry[capacity];

    for (int i = 0; i < old_capacity; i++)
    {
        if (old_arr[i].occupied && !old_arr[i].deleted)
        {
            internal_insert(old_arr[i].key, old_arr[i].value);
        }
    }

    delete[] old_arr;
}

void HashMapLinear::internal_insert(int key, int value)
{
    int index = hash(key, capacity);

    for (int i = 0; i < capacity; i++)
    {
        int iterator = (index + i) % capacity;

        //first free slot
        if (!arr[iterator].occupied)
        {
            arr[iterator].key = key;
            arr[iterator].value = value;
            arr[iterator].occupied = true;
            arr[iterator].deleted = false;

            return;
        }
    }
}

void HashMapLinear::insert(int key, int value)
{
    if ((double)(size + 1) / capacity > LOAD_FACTOR)
        resize();

    int index = hash(key, capacity);
    int first_tombstone = -1;

    for (int i = 0; i < capacity; i++)
    {
        int iterator = (index + i) % capacity;

        //update value 
        if (arr[iterator].occupied && !arr[iterator].deleted)
        {
            if (arr[iterator].key == key)
            {
                arr[iterator].value = value;
                return;
            }
        }
        //first tombstone
        else if (arr[iterator].occupied && arr[iterator].deleted)
        {
            if (first_tombstone == -1)
                first_tombstone = iterator;
        }
        //empty slot
        else 
        {
            int target = (first_tombstone != -1) ? first_tombstone : iterator;

            arr[target].key = key;
            arr[target].value = value;
            arr[target].occupied = true;
            arr[target].deleted = false;

            size++;
            return;
        }
    }

    if (first_tombstone != -1)
    {
        arr[first_tombstone].key = key;
        arr[first_tombstone].value = value;
        arr[first_tombstone].occupied = true;
        arr[first_tombstone].deleted = false;
        size++;
        return;
    }

    resize();
    insert(key, value);
}

void HashMapLinear::remove(int key)
{
    if (size == 0)
        return;

    int index = hash(key, capacity);
    
    for (int i = 0; i < capacity; i++)
    {
        int iterator = (index + i) % capacity;

        if (!arr[iterator].occupied)
            return;

        if (arr[iterator].occupied &&
            !arr[iterator].deleted &&
            arr[iterator].key == key)
        {
            arr[iterator].deleted = true;
            size--;
            return;
        }
    }
}

void HashMapLinear::print() const
{
    for (int i = 0; i < capacity; i++)
    {
        std::cout << "[";
        if (!arr[i].deleted && arr[i].occupied)
        {
            std::cout << arr[i].key << " : " << arr[i].value;
        }
        else if (arr[i].deleted)
        {
            std::cout << "*";
        }
        std::cout << "] ";
    }
}
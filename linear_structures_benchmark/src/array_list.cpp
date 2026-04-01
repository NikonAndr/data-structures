#include "array_list.h"
#include <iostream>

ArrayList::ArrayList()
{
    const int initial_size = 10;
    size = 0;
    capacity = initial_size;
    data = new int[initial_size];
}

//copy constructor
ArrayList::ArrayList(const ArrayList& other)
{
    size = other.size;
    capacity = other.capacity;

    data = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

//assign operator
ArrayList& ArrayList::operator=(const ArrayList& other)
{
    ArrayList temp(other);

    std::swap(data, temp.data);
    std::swap(size, temp.size);
    std::swap(capacity, temp.capacity);

    return *this;
}

//destructor, free memory
ArrayList::~ArrayList()
{
    delete[] data;
}

void ArrayList::double_capacity()
{
    int new_capacity = capacity * 2;
    int* new_data = new int[new_capacity];

    //copy old data
    for (int i = 0; i < size; i++)
    {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void ArrayList::push_back(int val)
{
    //check if list has enough space 
    if (size == capacity)
    {
        double_capacity();
    }

    data[size] = val;
    size++;  
}

void ArrayList::push_front(int val)
{
    //check if list has enough space 
    if (size == capacity)
    {
        double_capacity();
    }

    //shift elements to the righ without overwriting
    for (int i = size - 1; i >= 0; i--)
    {
        data[i+1] = data[i];
    }

    data[0] = val;
    size++;
}

void ArrayList::pop_back()
{
    //check if list is not empty
    if (size == 0)
    {
        return;
    }

    size--;
}

void ArrayList::pop_front()
{
    //check if list is not empty
    if (size == 0)
    {
        return;
    }

    //shift list to the left
    for (int i = 0; i < size - 1; i++)
    {
        data[i] = data[i+1];
    }

    size--;
}

void ArrayList::insert(int val, int index)
{
    //validate index
    if (index < 0 || index > size)
    {
        return;
    }

    //check if list has enough space
    if (size == capacity)
    {
        double_capacity();
    }

    //insert at the end
    if (index == size)
    {
        push_back(val);
        return;
    }

    //shift right without overwriting
    for (int i = size - 1; i >= index; i--)
    {
        data[i+1] = data[i];
    }

    data[index] = val;
    size++;
}

void ArrayList::remove(int index)
{
    //validate index
    if (index < 0 || index >= size)
    {
        return;
    }

    //shift to the left 
    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i+1];
    }

    size--;
}

int ArrayList::find(int val)
{

    for (int i = 0; i < size; i++)
    {
        if (data[i] == val)
        {
            return i;
        }
    }

    return -1;
}

int ArrayList::size_of() const 
{
    return size;
}

void ArrayList::print() const
{
    std::cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i];
        if (i != size - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}
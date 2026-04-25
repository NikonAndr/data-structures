#include "ArrayPQ.h"

#include <iostream>

ArrayPQ::ArrayPQ() : capacity(1), size(0) {
        unsortedArray = new Node[capacity];
}

ArrayPQ::ArrayPQ(const ArrayPQ& other)
{
    size = other.size;
    capacity = other.capacity;

    unsortedArray = new Node[capacity];

    for (int i = 0; i < size; i++)
    {
        unsortedArray[i] = other.unsortedArray[i];
    }
}

ArrayPQ::~ArrayPQ() {
    delete[] unsortedArray;
}

PQ* ArrayPQ::clone() const
{
    return new ArrayPQ(*this);
}

void ArrayPQ::ensure_capacity()
{
    if (size == capacity)
    {
        //check if capacity != 0
        capacity = (capacity == 0) ? 1 : capacity;

        int new_capacity = capacity * 2;
        Node* new_array = new Node[new_capacity];

        for (int i = 0; i < size; i++)
        {
            new_array[i] = unsortedArray[i];
        } 

        delete[] unsortedArray;
        capacity = new_capacity;
        unsortedArray = new_array;
    }
}

void ArrayPQ::insert(int value, int priority) 
{
    ensure_capacity();

    unsortedArray[size] = Node(value, priority);
    size++;
}

Node ArrayPQ::extract_max()
{
    if (size == 0)
        throw std::runtime_error("Array is empty");

    int max_index = 0;
    Node max = unsortedArray[0];
    
    for (int i = 0; i < size; i++)
    {
        if (unsortedArray[i].priority > max.priority)
        {
            max = unsortedArray[i];
            max_index = i;
        }
    }

    unsortedArray[max_index] = unsortedArray[size - 1];
    size--;

    return max;
}

Node ArrayPQ::peek() const
{
    if (size == 0)
        throw std::runtime_error("Array is empty");

    Node max = unsortedArray[0];

    for (int i = 0; i < size; i++)
    {
        if (unsortedArray[i].priority > max.priority)
        {
            max = unsortedArray[i];
        }
    }

    return max;
}

void ArrayPQ::modify_key(int value, int new_priority)
{
    if (size == 0)
        throw std::runtime_error("Array is empty");

    for (int i = 0; i < size; i++)
    {
        if (unsortedArray[i].value == value)
        {
            unsortedArray[i].priority = new_priority;
            return;
        }
    }

    throw std::runtime_error("Element not found");
}

int ArrayPQ::size_of() const
{
    return size;
}

std::string ArrayPQ::name() const 
{
    return "ArrayPQ";
}

void ArrayPQ::print() const
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << unsortedArray[i].value;
        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void ArrayPQ::print_priority() const
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << unsortedArray[i].priority;
        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


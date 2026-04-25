#include "HeapPQ.h"

#include <iostream>
#include <cmath>

//default constructor
HeapPQ::HeapPQ() : capacity(1), size(0) {
    heapArray = new Node[capacity];
}

HeapPQ::HeapPQ(const HeapPQ& other)
{
    size = other.size;
    capacity = other.capacity;

    heapArray = new Node[capacity];

    for (int i = 0; i < size; i++)
    {
        heapArray[i] = other.heapArray[i];
    }
}

//destructor
HeapPQ::~HeapPQ() {
    delete[] heapArray;
}

PQ* HeapPQ::clone() const
{
    return new HeapPQ(*this);
}

void HeapPQ::ensure_capacity()
{
    if (size == capacity)
    {
        //check if capacity != 0
        capacity = (capacity == 0) ? 1 : capacity;

        int new_capacity = capacity * 2;
        Node* new_array = new Node[new_capacity];

        for (int i = 0; i < size; i++)
        {
            new_array[i] = heapArray[i];
        } 

        delete[] heapArray;
        capacity = new_capacity;
        heapArray = new_array;
    }
}

int HeapPQ::get_parent(int i) {
    return (i - 1) / 2;
}
int HeapPQ::get_left_child(int i) {
    return i * 2 + 1;
}

int HeapPQ::get_right_child(int i) {
    return i * 2 + 2;
}

void HeapPQ::swap(Node& x, Node& y) {
    std::swap(x, y);
}

void HeapPQ::heapify_up(int i)
{
    while (i > 0 && heapArray[i].priority > heapArray[get_parent(i)].priority)
    {
        swap(heapArray[i], heapArray[get_parent(i)]);
        i = get_parent(i);
    }
}

void HeapPQ::heapify_down(int i)
{
    //ensure in range, has at least one child
    while (true)
    {
        int largest = i;
        int left = get_left_child(i);
        int right = get_right_child(i);

        if (left < size && heapArray[left].priority > heapArray[largest].priority)
        {
            largest = left;
        }

        if (right < size && heapArray[right].priority > heapArray[largest].priority)
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        swap (heapArray[i], heapArray[largest]);
        i = largest;
    }
}

void HeapPQ::insert(int value, int priority)
{
    ensure_capacity();

    //if heap is empty
    heapArray[size] = Node(value, priority);
    size++; 
    heapify_up(size - 1);
}

Node HeapPQ::extract_max()
{
    //check if heap is not empty
    if (size == 0)
        throw std::runtime_error("Heap is empty");

    Node max;

    max = heapArray[0];

    size--;
    heapArray[0] = heapArray[size];
    heapify_down(0);

    return max;
}

Node HeapPQ::peek() const 
{
    if (size == 0)
        throw std::runtime_error("Heap is empty");
    
    return heapArray[0];
}

void HeapPQ::modify_key(int value, int new_priority)
{
    if (size == 0)
        throw std::runtime_error("Heap is empty");

    int old_priority = 0;

    //find key, change value 
    for (int i = 0; i < size; i++)
    {
        if (heapArray[i].value == value)
        {
            old_priority = heapArray[i].priority;

            heapArray[i].priority = new_priority;
            if (old_priority > new_priority)
            {
                heapify_down(i);
            } 
            else if (old_priority < new_priority)
            {
                heapify_up(i);
            }
            return;
        }
    }

    throw std::runtime_error("Element not found");
    return;
}

int HeapPQ::size_of() const
{
    return size;
}

std::string HeapPQ::name() const 
{
    return "HeapPQ";
}

void HeapPQ::print() const
{
    int level = 0;
    int index = 0;

    int h = log2(size) + 1;

    while (index < size)
    {
        int count = pow(2, level);

        int spaces = pow(2, h - level);

        for (int i = 0; i < spaces; i++) std::cout << " ";

        for (int i = 0; i < count && index < size; i++)
        {
            std::cout << heapArray[index].value;

            for (int j = 0; j < spaces * 2; j++) std::cout << " ";

            index++;
        }

        std::cout << std::endl;
        level++;
    }
}

void HeapPQ::print_priority() const
{
    int level = 0;
    int index = 0;

    int h = log2(size) + 1;

    while (index < size)
    {
        int count = pow(2, level);

        int spaces = pow(2, h - level);

        for (int i = 0; i < spaces; i++) std::cout << " ";

        for (int i = 0; i < count && index < size; i++)
        {
            std::cout << heapArray[index].priority;

            for (int j = 0; j < spaces * 2; j++) std::cout << " ";

            index++;
        }

        std::cout << std::endl;
        level++;
    }
}
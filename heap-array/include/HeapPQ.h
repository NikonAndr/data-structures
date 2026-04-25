#pragma once

#include "PQ.h"
#include <string>

class HeapPQ : public PQ {
private:
    Node* heapArray;
    int size;
    int capacity;

    void ensure_capacity();

    int get_parent(int i);
    int get_left_child(int i);
    int get_right_child(int i);
    void swap(Node& x, Node& y);

    void heapify_up(int i);
    void heapify_down(int i);
    
public:
    //default constructor
    HeapPQ();

    HeapPQ(const HeapPQ& other);

    //destructor
    ~HeapPQ();

    PQ* clone() const override;

    void insert(int value, int priority) override;
    Node extract_max() override;
    Node peek() const override;
    void modify_key(int value, int new_priority) override;
    int size_of() const override;
    std::string name() const override;

    void print() const override;
    void print_priority() const override;
};
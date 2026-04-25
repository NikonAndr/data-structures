#pragma once

#include "PQ.h"
#include <string>

class ArrayPQ : public PQ {
private:
    Node* unsortedArray;
    int size;
    int capacity;

    void ensure_capacity();

public:
    //default constructor
    ArrayPQ();

    //deep copy 
    ArrayPQ(const ArrayPQ& other);

    //destructor
    ~ArrayPQ();

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
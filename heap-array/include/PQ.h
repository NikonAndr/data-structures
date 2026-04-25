#pragma once

#include "Node.h"
#include <string>

class PQ {
public:
    virtual ~PQ() = default;
    
    virtual PQ* clone() const = 0;

    virtual void insert(int value, int priority) = 0;
    virtual Node extract_max() = 0;
    virtual Node peek() const = 0;
    virtual void modify_key(int value, int new_priority) = 0;
    virtual int size_of() const = 0;

    virtual std::string name() const = 0;

    virtual void print() const = 0;
    virtual void print_priority() const = 0;
    
};
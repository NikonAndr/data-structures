#pragma once

#include "AVL.h"

class HashMapAVL 
{
private:
    AVL* arr;

    int size;
    int capacity;

    int hash(int key, int mod);

    void resize();
public:
    HashMapAVL();
    ~HashMapAVL();

    void insert(int key, int value);
    void remove(int key);

    void print() const;
};
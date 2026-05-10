#pragma once

#include "LinkedList.h"

class HashMapList
{
private:
    LinkedList* arr;

    int size;
    int capacity;

    int hash(int key, int mod);

    void resize();
public:
    HashMapList();
    ~HashMapList();

    void insert(int key, int value);
    void remove(int key);

    //debug 
    void print() const;
};
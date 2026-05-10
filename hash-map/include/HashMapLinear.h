#pragma once 

struct Entry
{
    int key;
    int value;

    bool occupied = false;
    bool deleted = false;
};

class HashMapLinear
{
private:
    Entry* arr;

    int size;
    int capacity;

    /*
    returns index of a key based on mod (by default mod == capacity)
    */
    int hash(int key, int mod);

    /*
    doubles the size of a hashmap
    */
    void resize();

    /*
    method used by resize to insert only valid elements (without tombstones)
    to the resized array
    */
    void internal_insert(int key, int value);
public:
    HashMapLinear();
    ~HashMapLinear();

    /*
    inserts value at certain index of a hashmap using hash method
    */
    void insert(int key, int value);

    /*
    removes key from hashmap if it exists
    */
    void remove(int key);

    void print() const;
};
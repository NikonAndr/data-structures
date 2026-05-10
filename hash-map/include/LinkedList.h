#pragma once 

class LinkedList
{
public:
    struct Node
    {
        int key;
        int value;
        Node* next;
    };
    
private:
    Node* head = nullptr;
    int size = 0;

public:
    ~LinkedList();

    void insert(int key, int value);
    bool remove(int key);
    Node* find(int key);
    int get_size();
    Node* get_head();

    //debug
    void print() const;
};
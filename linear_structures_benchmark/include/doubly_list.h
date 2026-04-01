#pragma once

struct D_Node 
{
    int data;
    D_Node* next;
    D_Node* prev;
};
class DoublyList
{
private:
    D_Node* head = nullptr;
    D_Node* tail = nullptr;
    int size = 0;

public:

    DoublyList();
    DoublyList(const DoublyList& other);
    DoublyList& operator=(const DoublyList& other);
    ~DoublyList();
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();
    void insert(int val, int index);
    void remove(int index);
    int find(int val);
    int size_of() const;
    void print() const;
};
#pragma once

struct S_Node {
    int data;
    S_Node* next;
};

class SinglyList
{
private:
    S_Node* head;
    S_Node* tail;
    int size = 0;

public:
    SinglyList();
    SinglyList(const SinglyList& other);
    SinglyList& operator=(const SinglyList& other);
    ~SinglyList();
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
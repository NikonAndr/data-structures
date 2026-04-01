#pragma once

class ArrayList
{
private:
    int* data;
    int size = 0;
    int capacity;
public:
    ArrayList();
    ArrayList(const ArrayList& other);
    ArrayList& operator=(const ArrayList& other);
    ~ArrayList();
    void double_capacity();
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
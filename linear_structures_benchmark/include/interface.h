#pragma once 
#include "array_list.h"
#include "singly_list.h"
#include "doubly_list.h"
#include "benchmark.h"

class Interface
{
private:
    ArrayList ArrayList;
    SinglyList SinglyList;
    DoublyList DoublyList;
public:
    ~Interface();
    void array_list_if();
    void singly_list_if();
    void doubly_list_if();
    void benchmark_if();
    void show_if();
};
#include "HeapPQ.h"
#include "ArrayPQ.h"
#include <iostream>

int main()
{
    ArrayPQ* array_pq = new ArrayPQ;
    HeapPQ* heap_pq = new HeapPQ;

    PQ* pq = heap_pq;
    
    pq = array_pq;

    for (int i = 0; i < 10; i++)
    { 
        pq->insert(i, i+10);
        pq->print();
        pq->print_priority();
        std::cout << "-----" << std::endl;
    }

    pq->extract_max();

    pq->print();
    pq->print_priority();

    pq->modify_key(8, 1);

    pq->print();
    pq->print_priority();
}
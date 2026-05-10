#include "HashMapAVL.h"

#include <iostream>

int main()
{
    HashMapAVL map;

    for (int i = 0; i < 7; i++)
    {
        map.insert(i * 10, i + 1);
    }

    map.insert(45, 20);

    map.print();
}
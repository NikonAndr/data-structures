#include "interface.h"

Interface::~Interface() 
{
    delete pq;
}
void Interface::main_if()
{
    int choice = -1;

    while (choice != 4)
    {
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std:: cout << "1: HeapPQ\n2: ArrayPQ\n3: Benchmark\n4: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                heap_if();
                break;
            case 2:
                array_if();
                break;
            case 3: 
                benchmark_if();
                break;
            case 4:
                std::cout << "bye :)" << std::endl;
                break;
                return;
        }
    }
}

void Interface::heap_if()
{
    pq = new HeapPQ;

    int choice = -1;

    while (choice != 7)
    {
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std:: cout << "1: insert(int, int)\n2: extract_max()\n3: peek()\n4: modify_key(int, int)\n5: print()\n6: print_priority()\n7: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
            {
                int value, priority;
                std::cout << "value, priority: ";
                std::cin >> value >> priority;
                pq->insert(value, priority);
                break;
            }
            case 2:
            {
                Node max(0,0);
                max = pq->extract_max();
                std::cout << "max: (" << max.value << ", " << max.priority << ")\n";
                break;
            }
            case 3: 
            {
                Node n(0,0);
                n = pq->peek();
                std::cout << "Node (peek): (" << n.value << ", " << n.priority << ")\n";
                break;
            }
            case 4:
            {
                int value, priority;
                std::cout << "value, priority: ";
                std::cin >> value >> priority;
                pq->modify_key(value, priority);
                break;
            }
            case 5:
            {
                pq->print();
                break;
            }
            case 6:
            {
                pq->print_priority();
                break;
            }
            case 7:
                return;
        }
    }
}

void Interface::array_if()
{
    pq = new ArrayPQ;

    int choice = -1;

    while (choice != 7)
    {
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std:: cout << "1: insert(int, int)\n2: extract_max()\n3: peek()\n4: modify_key(int, int)\n5: print()\n6: print_priority()\n7: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
            {
                int value, priority;
                std::cout << "value, priority: ";
                std::cin >> value >> priority;
                pq->insert(value, priority);
                break;
            }
            case 2:
            {
                Node max(0,0);
                max = pq->extract_max();
                std::cout << "max: (" << max.value << ", " << max.priority << ")\n";
                break;
            }
            case 3: 
            {
                Node n(0,0);
                n = pq->peek();
                std::cout << "Node (peek): (" << n.value << ", " << n.priority << ")\n";
                break;
            }
            case 4:
            {
                int value, priority;
                std::cout << "value, priority: ";
                std::cin >> value >> priority;
                pq->modify_key(value, priority);
                break;
            }
            case 5:
            {
                pq->print();
                break;
            }
            case 6:
            {
                pq->print_priority();
                break;
            }
            case 7:
                return;
        }
    }
}

void Interface::benchmark_if()
{
    int choice = -1;

    while (choice != 2)
    {
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std:: cout << "1: run_all_benchmarks\n2: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                run_all_benchmarks();
                std::cout << "\n\n**benchmark done!**\n\n";
                break;
            case 2:
                return;
        }
    }
}

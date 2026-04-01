#include "interface.h"

void Interface::array_list_if()
{
    int choice = -1;
    int val, index;
    
    while (choice != 9)
    {
        std::cout << "Menu: " << std::endl;
        std::cout << "1: push_back(int val)\n2: push_front(int val)\n3: pop_back()\n4: pop_front()\n5: insert(int val, int index)\n6: remove(int index)\n7: find(int val)\n8: print()\n9: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                ArrayList.push_back(val);
                break;
            case 2:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                ArrayList.push_front(val);
                break;
            case 3:
                ArrayList.pop_back();
                break;
            case 4:
                ArrayList.pop_front();
                break;
            case 5: 
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                ArrayList.insert(val, index);
                break;
            case 6:
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                ArrayList.remove(index);
                break;
            case 7:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                ArrayList.find(val);
                break;
            case 8:
                ArrayList.print();
                break;
            case 9:
                return;
                break;
            default:
                std::cout << "wrong choice!" << std::endl;
                break;
        }
    }
}

void Interface::singly_list_if()
{
    int choice = -1;
    int val, index;
    
    while (choice != 9)
    {
        std::cout << "Menu: " << std::endl;
        std::cout << "1: push_back(int val)\n2: push_front(int val)\n3: pop_back()\n4: pop_front()\n5: insert(int val, int index)\n6: remove(int index)\n7: find(int val)\n8: print()\n9: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                SinglyList.push_back(val);
                break;
            case 2:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                SinglyList.push_front(val);
                break;
            case 3:
                SinglyList.pop_back();
                break;
            case 4:
                SinglyList.pop_front();
                break;
            case 5: 
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                SinglyList.insert(val, index);
                break;
            case 6:
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                SinglyList.remove(index);
                break;
            case 7:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                SinglyList.find(val);
                break;
            case 8:
                SinglyList.print();
                break;
            case 9:
                return;
                break;  
            default:
                std::cout << "wrong choice!" << std::endl;
                break;
        }
    }
}

void Interface::doubly_list_if()
{
    int choice = -1;
    int val, index;
    
    while (choice != 9)
    {
        std::cout << "Menu: " << std::endl;
        std::cout << "1: push_back(int val)\n2: push_front(int val)\n3: pop_back()\n4: pop_front()\n5: insert(int val, int index)\n6: remove(int index)\n7: find(int val)\n8: print()\n9: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
            case 1:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                DoublyList.push_back(val);
                break;
            case 2:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                DoublyList.push_front(val);
                break;
            case 3:
                DoublyList.pop_back();
                break;
            case 4:
                DoublyList.pop_front();
                break;
            case 5: 
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                DoublyList.insert(val, index);
                break;
            case 6:
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                DoublyList.remove(index);
                break;
            case 7:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                DoublyList.find(val);
                break;
            case 8:
                DoublyList.print();
                break;
            case 9:
                return;
                break;  
            default:
                std::cout << "wrong choice!" << std::endl;
                break;
        }
    }
}

void Interface::benchmark_if()
{
    int choice = -1;

    while (choice != 9)
    {
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std:: cout << "1: push_back benchmark\n2: push_front benchmark\n3: pop_back benchmark\n4: pop_front benchmark\n5: insert benchmark\n6: remove benchmark\n7: find benchmark\n8: run all benchmarks\n9: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                benchmark_push_back();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 2:
                benchmark_push_front();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 3:
                benchmark_pop_back();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 4:
                benchmark_pop_front();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 5: 
                benchmark_insert();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 6:
                benchmark_remove();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 7:
                benchmark_find();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 8:
                run_all_benchmarks();
                std::cout << "benchmark done -> to view chart run the visualisation/charts.py script" << std::endl;
                break;
            case 9:
                return;
                break;
            default:
                std::cout << "wrong choice!" << std::endl;
                break;
        }
    }
}

void Interface::show_if()
{
    int choice = -1;

    while (choice != 5)
    {
        std::cout << std::endl;
        std::cout << "Menu: " << std::endl;
        std:: cout << "1: ArrayList\n2: SinglyList\n3: DoublyList\n4: Benchmarks\n5: exit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice)
        {
            case 1:
                array_list_if();
                break;
            case 2:
                singly_list_if();
                break;
            case 3: 
                doubly_list_if();
                break;
            case 4:
                benchmark_if();
                break;
            case 5: 
                std::cout << "bye :)" << std::endl;
                break;
                return;
        }
    }

    
};

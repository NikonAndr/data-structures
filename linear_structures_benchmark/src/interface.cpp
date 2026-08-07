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
                arrayList.push_back(val);
                break;
            case 2:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                arrayList.push_front(val);
                break;
            case 3:
                arrayList.pop_back();
                break;
            case 4:
                arrayList.pop_front();
                break;
            case 5: 
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                arrayList.insert(val, index);
                break;
            case 6:
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                arrayList.remove(index);
                break;
            case 7:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << arrayList.find(val) << std::endl;
                break;
            case 8:
                arrayList.print();
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
                singlyList.push_back(val);
                break;
            case 2:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                singlyList.push_front(val);
                break;
            case 3:
                singlyList.pop_back();
                break;
            case 4:
                singlyList.pop_front();
                break;
            case 5: 
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                singlyList.insert(val, index);
                break;
            case 6:
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                singlyList.remove(index);
                break;
            case 7:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << singlyList.find(val) << std::endl;
                break;
            case 8:
                singlyList.print();
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
                doublyList.push_back(val);
                break;
            case 2:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                doublyList.push_front(val);
                break;
            case 3:
                doublyList.pop_back();
                break;
            case 4:
                doublyList.pop_front();
                break;
            case 5: 
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                doublyList.insert(val, index);
                break;
            case 6:
                std::cout << "enter index: ";
                std::cin >> index; 
                std::cout << std::endl;
                doublyList.remove(index);
                break;
            case 7:
                std::cout << "enter val: ";
                std::cin >> val; 
                std::cout << std::endl;
                std::cout << doublyList.find(val) << std::endl;
                break;
            case 8:
                doublyList.print();
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

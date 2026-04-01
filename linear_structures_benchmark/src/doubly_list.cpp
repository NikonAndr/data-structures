#include <doubly_list.h>
#include <iostream>

//constructor
DoublyList::DoublyList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//copy constructor
DoublyList::DoublyList(const DoublyList& other)
{
    head = nullptr;
    tail = nullptr;
    size = 0;

    D_Node* temp = other.head;

    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->next;
    }
}

//assign operator 
DoublyList& DoublyList::operator=(const DoublyList& other)
{
    DoublyList temp(other);

    std::swap(head, temp.head);
    std::swap(tail, temp.tail);
    std::swap(size, temp.size);

    return *this;
}

//destructor, free memory
DoublyList::~DoublyList()
{
    D_Node* current = head;

    while (current != nullptr)
    {
        D_Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyList::push_back(int val)
{
    D_Node* n = new D_Node;
    n->data = val;
    n->next = nullptr;

    //if list is empty
    if (head == nullptr)
    {
        n->prev = nullptr;
        head = tail = n;
        size++;
        return;
    }

    //if list is not empty
    n->prev = tail;
    tail->next = n;
    tail = n;

    size++;
}

void DoublyList::push_front(int val)
{
    D_Node* n = new D_Node;
    n->data = val;
    n->prev = nullptr;

    //if list is empty
    if (head == nullptr)
    {
        n->next = nullptr;
        head = tail = n;
        size++;
        return;
    }

    //if list is not empty
    n->next = head;
    head->prev = n;
    head = n;

    size++;
}

void DoublyList::pop_back()
{
    //if list is empty
    if (head == nullptr)
    {
        return;
    }

    //if list has one element 
    if (head == tail)
    {
        D_Node* temp = head;
        delete temp;
        head = tail = nullptr;
        size--;
        return;
    }

    //if list has more than 1 element
    D_Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;

    size--;
}

void DoublyList::pop_front()
{
    //if list is empty
    if (head == nullptr)
    {
        return;
    }

    //if list has one element 
    if (head == tail)
    {
        D_Node* temp = head;
        delete temp;
        head = tail = nullptr;
        size--;
        return;
    }

    //if list has more than 1 element
    D_Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    
    size--;
}

void DoublyList::insert(int val, int index)
{
    //validate index
    if (index < 0) return;

    //if list is empty or index is 0
    if (index == 0)
    {
        push_front(val);
        return;
    }

    //else
    D_Node* temp = head;
    int count = 0;
    
    //get element that is before the index
    while (temp != nullptr && count < index - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        std::cout << "index out of range" << std::endl;
        return;
    }

    //insert at the back 
    if (temp == tail)
    {
        push_back(val);
        return;
    }

    //insert at the given index 
    D_Node* n = new D_Node;
    n->data = val;

    n->next = temp->next;   
    n->prev = temp;

    temp->next->prev = n;
    temp->next = n;

    size++;
}

void DoublyList::remove(int index)
{
    //validate index
    if (index < 0) return;

    //if list is empty
    if (head == nullptr) return;

    if (index == 0)
    {
        pop_front();
        return;
    }

    D_Node* temp = head;
    int count = 0;

    //get element that is before the index
    while (temp != nullptr && count < index - 1)
    {
        temp = temp->next;
        count ++;
    }

    if (temp == nullptr || temp->next == nullptr) 
    {
        std::cout << "index out of range" << std::endl;
        return;
    }

    if (temp->next == tail)
    {
        pop_back();
        return;
    }

    //remove at given index
    D_Node* to_delete = temp->next;

    temp->next = to_delete->next;
    to_delete->next->prev = temp;
    
    delete to_delete;

    size--;
}

int DoublyList::find(int val)
{
    D_Node* temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        if (temp->data == val)
            return count;
        else 
        {
            temp = temp->next;
            count++;
        }
    }


    //index out of range, empty list, value not found 
    return -1;
}

int DoublyList::size_of() const
{
    return size;
}

void DoublyList::print() const
{
    D_Node* temp = head;

    if (head == nullptr)
    {
        std::cout << "list is empty" << std::endl;
        return;
    }

    //print list
    std::cout << "nullptr ← ";
    while (temp != nullptr)
    {
        if (temp != tail)
        {
            std::cout << temp->data << " ↔ ";
        }
        else
        {
            std::cout << temp->data << " → nullptr" << std::endl;
        }
        temp = temp->next;
    }
}
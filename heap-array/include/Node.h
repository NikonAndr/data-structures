#pragma once 
struct Node
{
    int value;
    int priority;

    Node() = default;
    Node(int value, int priority) : value(value), priority(priority) {}
};

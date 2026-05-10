#pragma once

#include <functional>

class AVL
{
private:
    struct Node
    {
        int key;
        int value;

        int height = 1;

        Node* left = nullptr;
        Node* right = nullptr;
    };
    
    Node* root;

    /*
    returns height of the Node
    */
    int getHeight(Node* n) const;
    /*
    calculates Node balance based on the height of the subtrees 
    */
    int getBalance(Node* n) const;

    /*
    updates height of the node
    */
    void updateHeight(Node* n);

    /*
    rotates Nodes around parent Node to the left
    */
    Node* rotateLeft(Node* parent);
    /*
    rotates Nodes around parent Node to the right
    */
    Node* rotateRight(Node* parent);

    /*
    destroys tree based on the root
    */
    void destroy(Node* n);

    /*
    recursive function used to insert/update a Node inside the tree
    returns pointer to the new Node
    */
    Node* insert(Node* current, int key, int value, bool& inserted);
    /*
    recursive function used to remove a Node from the tree
    returns pointer to the location of deleted node
    */
    Node* remove(Node* current, int key, bool& removed);

    void traverse(Node* current, std::function<void(int,int)> visit) const;

    void print(Node* current, int depth);

public:
    AVL();
    ~AVL();

    bool insert(int key, int value);
    bool remove(int key);

    void traverse(std::function<void(int, int)> visit) const;
    
    void print();
};

#include "AVL.h"

#include <iostream>
#include <algorithm>
#include <cmath>

AVL::AVL() : root(nullptr) {}

void AVL::destroy(Node* n)
{   
    if (n == nullptr)
    {
        return;
    }

    destroy(n->left);
    destroy(n->right);

    delete n;
}

AVL::~AVL() 
{
    destroy(root);
}

int AVL::getHeight(Node* n) const
{
    return (n == nullptr) ? 0 : n->height;
}

int AVL::getBalance(Node* n) const
{
    if (n == nullptr)
    {
        return 0;
    }

    return getHeight(n->left) - getHeight(n->right);
}

void AVL::updateHeight(Node* n)
{
    if (n == nullptr)
    {
        return;
    }

    n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
}

AVL::Node* AVL::rotateLeft(Node* parent)
{
    if (parent == nullptr)
    {
        return parent;
    }

    Node* right = parent->right;
    if (right == nullptr)
    {
        return parent;
    }

    Node* sub_tree = right->left;

    right->left = parent;
    parent->right = sub_tree;

    updateHeight(parent);
    updateHeight(right);

    return right;
}

AVL::Node* AVL::rotateRight(Node* parent)
{
    if (parent == nullptr)
    {
        return parent;
    }

    Node* left = parent->left;
    if (left == nullptr)
    {
        return parent;
    }

    Node* sub_tree = left->right;

    left->right = parent;
    parent->left = sub_tree;

    updateHeight(parent);
    updateHeight(left);

    return left;
}

AVL::Node* AVL::insert(Node* current, int key, int value, bool& inserted)
{
    //base case
    if (current == nullptr)
    {
        Node* n = new Node;
        n->key = key;
        n->value = value;
        
        inserted = true;
        return n;
    }

    //BST insert
    if (key < current->key)
    {
        current->left = insert(current->left, key, value, inserted);
    }
    else if (key > current->key)
    {
        current->right = insert(current->right, key, value, inserted);
    }
    //update existing
    else 
    {
        current->value = value;
        return current;
    }
    
    updateHeight(current);

    //rotations
    //LL
    if (getBalance(current) > 1 && getBalance(current->left) > 0)
    {
        return rotateRight(current);
    }
    //LR
    if (getBalance(current) > 1 && getBalance(current->left) < 0)
    {
        current-> left = rotateLeft(current->left);
        return rotateRight(current);
    }
    //RR
    if (getBalance(current) < -1 && getBalance(current->right) < 0)
    {
        return rotateLeft(current);
    }
    //RL
    if (getBalance(current) < -1 && getBalance(current->right) > 0)
    {
        current->right = rotateRight(current->right);
        return rotateLeft(current);
    }


    return current;
}

bool AVL::insert(int key, int value)
{
    bool inserted = false;
    root = insert(root, key, value, inserted);
    return inserted;
}

//remove 
AVL::Node* AVL::remove(Node* current, int key, bool& removed)
{
    if (current == nullptr)
    {
        return nullptr;
    }
    
    //BST search
    if (key < current->key)
    {
        current->left = remove(current->left, key, removed);
    }
    else if (key > current->key)
    {
        current->right = remove(current->right, key, removed);
    }
    //key found
    else
    {
        //0 children
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            removed = true;
            return nullptr;
        }

        //1 child
        if (current->left == nullptr)
        {
            Node* temp = current->right;
            delete current;
            removed = true;
            return temp;
        }
        else if (current->right == nullptr)
        {
            Node* temp = current->left;
            delete current;
            removed = true;
            return temp;
        }

        //2 children
        Node* succesor = current->right;

        //determine succesor
        while (succesor->left != nullptr)
        {
            succesor = succesor->left;
        }

        //copy succesor key & value to current node
        current->key = succesor->key;
        current->value = succesor->value;

        //get rid of the duplicate
        bool dummy = false;
        current->right = remove(current->right, succesor->key, dummy);

        removed = true;
    }

    updateHeight(current);

    //rotations
    //LL
    if (getBalance(current) > 1 && getBalance(current->left) >= 0)
    {
        return rotateRight(current);
    }
    //LR
    if (getBalance(current) > 1 && getBalance(current->left) < 0)
    {
        current-> left = rotateLeft(current->left);
        return rotateRight(current);
    }
    //RR
    if (getBalance(current) < -1 && getBalance(current->right) <= 0)
    {
        return rotateLeft(current);
    }
    //RL
    if (getBalance(current) < -1 && getBalance(current->right) > 0)
    {
        current->right = rotateRight(current->right);
        return rotateLeft(current);
    }
    return current;    
}

bool AVL::remove(int key)
{
    bool removed = false;
    root = remove(root, key, removed);
    return removed;
}

void AVL::print(Node* current, int depth)
{
    if (current == nullptr)
    {
        return;
    }
    for (int i = 0; i < depth; i++)
    {
        std::cout << " ";
    }

    std::cout << current->key << " : " << current->value << std::endl;

    print(current->left, depth + 1);
    print(current->right, depth + 1);
}

void AVL::traverse(Node* current, std::function<void(int,int)> visit) const
{
    if (current == nullptr)
        return;

    traverse(current->left, visit);
    visit(current->key, current->value);
    traverse(current->right, visit);
}

void AVL::traverse(std::function<void(int, int)> visit) const
{
    traverse(root, visit);
}

void AVL::print()
{
    if (root == nullptr)
    {
        std::cout << "tree is empty";
        return;
    }
    print(root, 0);
}

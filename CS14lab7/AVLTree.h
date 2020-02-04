//
// Created by Leslie De Jesus on 11/13/19.
//

#ifndef LAB7_AVLTREE_H
#define LAB7_AVLTREE_H

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;
#include<fstream>

class AVLTree {


public:
    AVLTree() : root(0){}
    void insert(const string &); //Insert an item to the binary search tree and perform rotation if necessary.
    int balanceFactor(Node*); //Return the balance factor of a given node.
    void printBalanceFactors(); //Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.

private:
    Node *root;
    Node* insert(Node*, const string &);
    Node* rotate(Node*, const string &); //Implement four possible imbalance cases and update the parent of the given node.
    Node* rotateLeft(Node* ); //Rotate the subtree to left at the given node and returns the new subroot.
    Node* rotateRight(Node*); //Rotate the subtree to right at the given node and returns the new subroot.
    int getMax(int number1, int number2);
    int getHeight(Node* );
    void printBalanceFactors(Node *);\


};


#endif //LAB7_AVLTREE_H

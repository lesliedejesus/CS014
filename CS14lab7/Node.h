//
// Created by Leslie De Jesus on 11/13/19.
//

#ifndef LAB7_NODE_H
#define LAB7_NODE_H


using namespace std;
#include <iostream>
#include <string>


class Node {


public:
    Node *left;
    Node *right;
    string data;
    int height;
    //Node();
    Node(const string &s);
    friend class AVLTree;
};

#endif //LAB7_NODE_H

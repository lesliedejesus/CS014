#include <iostream>
#include "AVLTree.h"
#include <string>
using namespace std;
#include "Node.h"
#include<fstream>
#include <cstdlib>


void AVLTree::insert(const string &word){
    insert(root, word);
}

//Return the balance factor of a given node.
int AVLTree::balanceFactor(Node*print){
    if(print == 0) //this is if the tree is empty
        return 0;
    // this is for if the tree goes to the left and right and the balance factor is 0
    if(print -> left == 0 && print -> right == 0)
        return 0;
        // this is considering if the tree will
        // have a balance factor other than 0 for the right
    else if(print -> left == 0 && print -> right != 0)
        return (-1 - getHeight(print -> right));
        // this is considering if the tree will
        // have a balance factor other than 0 for the left
    else if(print -> left != 0 && print -> right == 0)
        return (getHeight(print -> left) - (-1));

    else
        return getHeight(print -> left) - getHeight(print -> right);

}



void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
}


//Insert an item to the binary search tree and perform rotation if necessary.
Node* AVLTree::insert( Node* temp, const string &val) {

// check for valid input
    if (val == "\n") {
        return temp;
    }

    if (root == 0) {
        Node *newNode = new Node(val);
        root = newNode;
        return root;
    }

    if (temp == 0) {
        Node *newNode = new Node(val);
        return newNode;
    }

    // recursively traverse tree to insert new node
    if (val < temp->data) {
        temp->left = insert(temp->left, val);
    }
    else if (val > temp->data) {
        temp->right = insert(temp->right,val);
    }
    else {
        return temp; // do not allow equal node
    }
    temp -> height = getMax(getHeight(temp->left), getHeight(temp->right)) + 1;

    return rotate(temp,val);

}

// Implement four possible imbalance cases
// and update the parent of the given node.
Node* AVLTree::rotate(Node*curr, const string &key) {

    int balance = balanceFactor(curr);

    if(balance > 1 && curr -> left -> data > key) {  //left left rotation
        return rotateRight(curr);
    }
    if(balance < -1 && curr -> right -> data < key  ) {  //right right
        return rotateLeft(curr);
    }

    if (balance > 1 &&  curr -> left -> data < key) {   // Left Right Case

        curr -> left  =  rotateLeft(curr->left);
        return rotateRight(curr);
    }

    if (balance < -1 &&  curr -> right -> data > key ) {

        curr -> right = rotateRight(curr -> right);
        return rotateLeft(curr);

    }
    /* return the (unchanged) node pointer */
    return curr;
}

// Rotate the subtree to left
// at the given node and returns the new subroot.
Node* AVLTree::rotateLeft(Node*parent) {
    Node* temp = parent -> right;
    Node* curr = temp -> left;
    // performing the transform
    temp -> left = parent;
    parent -> right = curr;
    //update the height
    parent ->height = getMax(getHeight(parent -> left), getHeight(parent->right)) + 1;
    temp ->height = getMax(getHeight(temp -> left), getHeight(temp -> right)) + 1;

    if(parent == root) {
        root = temp;
    }
    //returns the root
    return temp;
}

// Rotate the subtree to right at the
// given node and returns the new subroot.
Node* AVLTree::rotateRight(Node*parent) {
    Node* temp = parent -> left;
    Node* curr = temp -> right; //its null in this case
    //right rotation
    temp -> right = parent;
    parent -> left = curr;
    //update the height
    parent ->height = getMax(getHeight(parent -> left), getHeight(parent->right)) + 1;
    temp ->height = getMax(getHeight(temp -> left), getHeight(temp -> right)) + 1;

    if(parent == root) {
        root = temp;
    }
    //returns the root
    return temp;
}


int AVLTree::getMax(int a, int b) {
// A utility function to get maximum of two integers
    return (a > b) ? a : b;
}


int AVLTree::getHeight(Node*print ) {
    if(print == 0) {
        return -1;
    }
    return print->height;
}

void AVLTree::printBalanceFactors(Node *print) {
    if (print == 0)
        return;

    printBalanceFactors(print->left);
    cout << print -> data << "(" << balanceFactor(print) << "), ";
    printBalanceFactors(print -> right);
}

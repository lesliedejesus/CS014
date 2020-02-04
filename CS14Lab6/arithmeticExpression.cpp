//
// Created by Leslie De Jesus on 11/6/19.
//

#include <iostream>
#include <cstdlib>
#include "arithmeticExpression.h"
#include "stack.h"
#include <sstream>
#include <fstream>

using namespace std;

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}


string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

arithmeticExpression::arithmeticExpression(const string & thing){
    root = new TreeNode(0, 0);
    infixExpression = thing;
}

/* Implementation of destrucor is optional.
   The destructor should deallocate all the nodes in the tree. */
//~arithmeticExpression();

/* Converts the infixExpression to its equivalent postfix string
   and then generates the tree and assigns the root node to the
   root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree(){
    string thing = infix_to_postfix();

}

/* Calls the recursive infix function. */
void infix();

/* Calls the recursive prefix function. */
void prefix();

/* Calls the recursive postfix function. */
void postfix();

/* Calls the recursive visualizeTree function and generates the .png file using system call. */
void visualizeTree(const string &);



/* Helper function that outputs the infix notation of the arithmetic expression tree
   by performing the inorder traversal of the tree.
   An opening and closing parenthesis must be added at the
   beginning and ending of each expression. */
void infix(TreeNode *);

/* Helper function that outputs the prefix notation of the arithmetic expression tree
   by performing the preorder traversal of the tree. */
void prefix(TreeNode *);

/* Helper function that outputs the postfix notation of the arithmetic expression tree
   by performing the postorder traversal of the tree. */
void postfix(TreeNode *);

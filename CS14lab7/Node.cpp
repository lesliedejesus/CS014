//
// Created by Leslie De Jesus on 11/13/19.


#include <iostream>
#include "Node.h"

using namespace std;


Node::Node( const string &s) {
    left = 0;
    right = 0;
    height = 0;
    data = s;
}
//
// Created by Leslie De Jesus on 12/3/19.
//

#ifndef CS14LAB10_VERTEX_H
#define CS14LAB10_VERTEX_H
#include <string>
#include <list>
#include <map>
#include <climits>
#include "Graph.h"

using namespace std;

class Vertex {
public:
    list<pair<int, int> > neighbors;
    string label;
    int distance;
    string color;
    Vertex* prev;
    void addEdge(int u, int v)    {
        neighbors.push_back(make_pair(u, v));
    };
    Vertex():label(""),distance(INT_MAX),color("WHITE"),prev(0){}
    ~Vertex(){}
};
#endif //CS14LAB10_VERTEX_H

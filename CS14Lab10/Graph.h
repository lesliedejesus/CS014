//
// Created by Leslie De Jesus on 12/3/19.
//

#ifndef CS14LAB10_GRAPH_H
#define CS14LAB10_GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>

#include "Vertex.h"

using namespace std;

const int maxNameLength = 15;
const int maxN = 50;
const int maxM = 200;

class Edge {
public:
    Edge(Vertex* n1, Vertex* n2, int w):v(n2),weight(w){};
    ~Edge() {};
    void      setWeight(double w)  {weight=w;};
    Vertex*     getVertex()   const    {return v;};
    double    getWeight() const    {return weight;};
private:
    Vertex*  v;
    double weight;
    friend class Vertex;
};

class Graph {
private:
    vector<Vertex> vertices;
    int numNodes;
    int numEdges;
    string type;
public:
    Graph();
    Graph(ifstream&);
    ~Graph();
    void output_graph();
    void bfs();
    void addEdge(string , string, int w);
};


#endif //CS14LAB10_GRAPH_H

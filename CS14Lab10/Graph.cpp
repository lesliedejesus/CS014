//
// Created by Leslie De Jesus on 12/3/19.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Graph.h"
#include <queue>
using namespace std;

//Reads the graph input file and instantiates a graph object.
Graph::Graph(ifstream& ifs){
    int line = 0;
    string u,v;
    int c;
        if (line == 0){
            ifs >> numNodes;
            ++line;
        }
        if (line == 1){
            ifs >> numEdges;
        }
        for (int i = 0; i < numNodes; ++i){
            Vertex newV;
            vertices.push_back(newV);
            ifs >> type;
            vertices.at(i).label = type;
        }
        for(int j = 0; j < numEdges; ++j){
            ifs >> u; //vertex 1
            ifs >> v; //vertex 2
            ifs >> c; //weight
            addEdge(u, v, c);
        }

}
Graph::~Graph(){
    vertices.clear();
}
void Graph::output_graph(){
    for (int i = 0; i < numNodes; ++i){
        cout << vertices.at(i).label << " [";
        cout << vertices.at(i).label << ", " << vertices.at(i).distance << " ";
        //list<pair<int, int>> ::iterator it;
//        for (it = vertices.at(i).neighbors.begin(); it != vertices.at(i).neighbors.end(); ++it ){
//            cout << vertices.at((*it).second).label << ", " << vertices.at((*it).second).distance << " ";
//        }
        cout << "]" << endl;
    }

}
//Breadth First Search. Via a BFS traversal, this function
// should assign each individual vertex's distance to the number
// of hops that the vertex is from the start vertex. You can
// find the pseudo code for BFS on graphs.pdf
void Graph::bfs(){
    queue<Vertex> visited;
    Vertex current; int u;
    visited.push(vertices.at(0));
    vertices.at(0).distance = 0;
    vertices.at(0).color = "GRAY";
    while (!visited.empty()){
        current = visited.front();
        visited.pop();
        for (int i = 0; i < vertices.size(); ++i){
            if (current.label == vertices.at(i).label){
                u = i;
            }
        }

        list<pair<int, int>> ::iterator it;
        for (it = current.neighbors.begin(); it != current.neighbors.end(); ++it ){
            if (vertices.at((*it).second).color == "WHITE"){
                vertices.at((*it).second).color = "GRAY";
                vertices.at((*it).second).distance = vertices.at(u).distance + 1;
                visited.push(vertices.at((*it).second));
            }
            vertices.at((*it).second).color = "BLACK";

        }
    }

}

void Graph::addEdge(string k1, string k2, int w) {
    int u, v = 0;
    for (unsigned int i = 0; i < vertices.size(); ++i){
        if (vertices.at(i).label == k1){
            u = (int)i;
        }
        if (vertices.at(i).label == k2){
            v = (int)i;
        }
    }
    vertices.at(u).addEdge(u,v);
    //vertices.at(v).addEdge(v, u);
}
//
// Created by Leslie De Jesus on 12/2/19.
//

#ifndef CS14ASSN5_GRAPH_H
#define CS14ASSN5_GRAPH_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Edge;

//Node
class Node {
public:
    Node(const string& elem):payload(elem),visited(false), distance(numeric_limits<int>::max()), prev(0){
        adjacents = new vector<Edge* >();
    };
    ~Node() {};
    void   setVisited(bool v)        {visited = v;};
    bool    isVisited()              {return visited;};
    void   addEdge(Edge* e)    {
        adjacents->push_back(e);
    };
    int    degree()  const           {return adjacents->size();};
    string getPayload() const        {return payload;}
    vector<string>*  neighbors();
    void setDistance(double d){distance = d;}
    Node* getPrev() const { return prev;}
    void setPrev(Node* p){prev = p;}
    double getDistance(){ return distance;}
    vector<Edge* >*  adjacentsList()     {return adjacents;};
private:
    string        payload;
    double distance;
    Node* prev;

    bool          visited;
    vector<Edge* >* adjacents;
};


//Edge
class Edge {
public:
    Edge(Node* n, double w):node(n),weight(w){};
    ~Edge() {};
    void      setWeight(double w)  {weight=w;};
    Node*     getNode()   const    {return node;};
    double    getWeight() const    {return weight;};
private:
    Node*  node;
    double weight;
    friend class Node;
};


//Graph
class Graph {
public:
    Graph(bool directed):directed(directed){
        graph = new map<string,Node*>();
    };

    ~Graph() {
        delete graph;
    };

    //DO NOT CHANGE THE FOLLOWING METHODS
    void addNode(string node);
    void addEdge(string nid1 , string nid2, double w);
    void printGraph();

    //Homework

    //returns true if there are three nodes in the graph that are all
    //connected to each other. E.g., a,b,c, with edges (a,b),(b,c),(a,c)
    bool IsThereTripletClique();
    // returns shortest path distance between city1 and
    //city 2. Hint: You may use Dijkstra Algorithm
    double GetMinDistance(string city1,string city2);
    // returns true if graph is connected
    bool isGraphConnected();
    static void traverse(Node* );


private:
    map<string,Node*>* graph;
    bool directed;
};


#endif //CS14ASSN5_GRAPH_H

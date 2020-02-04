//
// Created by Leslie De Jesus on 12/2/19.
//

#include "graph.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


vector<string>* Node::neighbors() {
    auto* vec = new vector<string>();
    vector<Edge*>::iterator it;
    for(it=adjacents->begin();it!=adjacents->end();it++) {
        vec->push_back((*it)->getNode()->getPayload());
    }
    return vec;
}


void Graph::addNode(string name) {
    Node* node = new Node(name);
    graph->insert(pair<string,Node*>(name,node));
}

void Graph::addEdge(string k1, string k2, double w) {
    map<string,Node* >::iterator it1,it2;
    it1 = graph->find(k1);
    it2 = graph->find(k2);

    //Check both nodes exists using the map
    if (it1 != graph->end() && it2 != graph->end()) {
        Node* n1 = (*it1).second;
        Node* n2 = (*it2).second;
        //Create the edge and add it to the adjacents
        Edge* e = new Edge(n2,w);
        n1->addEdge(e);
        //Undirected graph: we add the reverse or back edge
        if (!directed) {
            Edge* be = new Edge(n1,w);
            n2->addEdge(be);
        }
    }
}


void Graph::printGraph() {
    //Iterate each node
    map<string,Node* >::iterator it;
    for (it=graph->begin(); it != graph->end();it++) {
        Node* n = (*it).second;
        cout << n->getPayload() << "[";

        //Iterate the neighbors
        vector<string>* neigh  = n->neighbors();
        vector<string>::iterator itn;
        for(itn=neigh->begin();itn!=neigh->end();itn++) {
            cout << (*itn) << " ";
        }
        cout << "]" << endl;
    }
}

bool Graph::IsThereTripletClique(){
    //Iterate each node
    map<string,Node* >::iterator it;
    vector<string> visitedV;
    vector<string> visitedN;
    for (it=graph->begin(); it != graph->end();it++) {
        Node *n = (*it).second; //second gives Node* value of map

        //Iterate the neighbors
        Node *node1, *node2;
        vector<Edge *>::iterator itn, itn1, itn2;
        for (itn = n->adjacentsList()->begin(); itn != n->adjacentsList()->end(); itn++) {
            node1 = (*itn)->getNode(); //current neighbor
            for (itn1 = node1->adjacentsList()->begin(); itn1 != node1->adjacentsList()->end(); itn1++){
                node2 = (*itn1)->getNode(); //neighbor's neighbor
                for (itn2 = node2->adjacentsList()->begin(); itn2 != node2->adjacentsList()->end(); itn2++) {
                    if ((*itn2)->getNode() == n) { //if connected, triangle created
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
double Graph::GetMinDistance(string city1,string city2){
    map<string,Node* >::iterator it, it1;
    Node* currentV, *startV, *endV;

    //find start and end nodes corresponding to city names
    for (it= graph->begin(); it != graph->end();it++){
        if ((*it).second->getPayload() == city1){
            startV = (*it).second;
        }
        else if ((*it).second->getPayload() == city2){
            endV = (*it).second;
        }
    }

    //NEW: Infinity def
    double INFINITY = numeric_limits<double>::max();
    //NEW pair priority queue sorted by min of first element (double distance)
    priority_queue<pair<double,Node*>,vector<pair<double,Node*> >,greater< > > unvisitedQueue;
    //push all vertices to queue
    for (it1=graph->begin(); it1 != graph->end();it1++) {
        Node* n = (*it1).second;
        //NEW: initialize distance and predecessors
        n->setDistance(INFINITY);
        n->setPrev(0);
        unvisitedQueue.push(make_pair(n->getDistance(),n));
    }

    // startV has a distance of 0 from itself
    //this will set it at top of queue
    startV->setDistance(0);

    double edgeWeight,alternativePathDistance;
    while(!unvisitedQueue.empty()){
        //vertex with min distance from startV
        currentV = unvisitedQueue.top().second;
        unvisitedQueue.pop();

        //NEW more "simple" for loop
        for(unsigned i = 0; i<currentV->adjacentsList()->size(); i++){
            edgeWeight = currentV->adjacentsList()->at(i)->getWeight();
            alternativePathDistance = currentV->getDistance()+edgeWeight;
            //If shorter path from startV to adjV is found,
            //update adjV's distance and predecessor
            if(alternativePathDistance < currentV->adjacentsList()->at(i)->getNode()->getDistance()){
                currentV->adjacentsList()->at(i)->getNode()->setDistance(alternativePathDistance);
                currentV->adjacentsList()->at(i)->getNode()->setPrev(currentV);
            }
        }
    }

    //NEW:finding shortest path to startV starting from endV using predV
    Node* n = endV;
    double minDistance=0.0;
    while(n!=startV){
        minDistance+=n->getDistance();
        n=n->getPrev();
    }
    return minDistance;
}


void Graph::traverse(Node* n){
    n->setVisited(true);
    //NEW more "simple" for loop
    for(unsigned i=0; i<n->adjacentsList()->size();i++){
        if(!n->adjacentsList()->at(i)->getNode()->isVisited()){
            traverse(n->adjacentsList()->at(i)->getNode());
        }
    }
}

bool Graph::isGraphConnected(){
    traverse(graph->begin()->second);
    map<string, Node*>::iterator it;
    for (it=graph->begin(); it != graph->end();it++) {
        Node* n = (*it).second;
        if (!(n->isVisited())){
            return false;
        }
    }
    return true;
}



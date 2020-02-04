#include <iostream>
#include "graph.h"
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;


int main() {

    Graph g(false);
//
//    g.addNode("a");
////    g.addNode("b");
////    g.addNode("c");
////
////    g.addEdge("a","b",10);
////    g.addEdge("b","c",5);
////    g.addEdge("c","a",9);
////
////    g.printGraph();
////
////    double min = g.GetMinDistance("a", "c");
////    cout << "Min distance from A to C is " << min << endl;

//    if (g.isGraphConnected()){
//        cout << "Graph is connected" << endl;
//    }
    srand(time(NULL));
    string alphabet[26] = { "a", "b", "c", "d", "e", "f", "g",
                           "h", "i", "j", "k", "l", "m", "n",
                           "o", "p", "q", "r", "s", "t", "u",
                           "v", "w", "x", "y", "z" };
    for (int i = 0; i < 100; ++i){
        g.addNode(alphabet[rand()%26]);
    }
    for (int i = 0; i < 500; ++i){
        g.addEdge(alphabet[rand()%26], alphabet[rand()%26], 1);
    }
    for (int i = 0; i < 500; ++i){
        g.addEdge(alphabet[rand()%26], alphabet[rand()%26], 2);
    }
    for (int i = 0; i < 500; ++i){
        g.addEdge(alphabet[rand()%26], alphabet[rand()%26], 3);
    }
    auto start = high_resolution_clock::now();
    double tc = g.GetMinDistance(alphabet[rand()%26],alphabet[rand()%26]);
    cout << "Min Distance (rand cities): " << tc <<endl;
    auto stop = high_resolution_clock::now();

//    auto start = high_resolution_clock::now();
//    bool tc = g.isGraphConnected();
//    auto stop = high_resolution_clock::now();
//    if (tc){
//        cout << "triplet clique found :)" << endl;
//    }
//    if (tc){
//        cout << "Graph is connected" << endl;
//    }
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


    return 0;
}
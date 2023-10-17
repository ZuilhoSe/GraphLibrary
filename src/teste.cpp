#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "../include/graph.h"

using namespace std;

int main(){
    adjListGraph g("../examples/graph_teste.txt");
    g.printList();
    g.heapDijkstra(1);

    for(int i = 0; i < g.nodesFather.size(); i++){
        cout << "Vertice: " << i+1 << " | Pai: " << g.nodesFather[i] << " | Grau: " << g.nodesDegree[i] << " | Level: " << g.nodesLevel[i] <<endl;
    }


    return 0;
}
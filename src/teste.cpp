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
    std::vector<float> neighbors = g.returnNeighbors(1);
    g.BFS(1);
    g.heapDijkstra(1);
    g.vectorDijkstra(1);
    return 0;
}
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "../include/graph.h"

using namespace std;

int main(){
    adjListGraph g1("C:/Users/segun/Documents/GitHub/GraphLibrary/data/grafo_W_1.txt");
    g1.heapDijkstra(10, true, "../examples/tree_g1.txt", "../examples/dist_g1.txt");
    g1.exportMinPathToTxt("../examples/min_path_g1.txt", 10, 20);
    g1.exportMinPathToTxt("../examples/min_path_g1.txt", 10, 30);
    g1.exportMinPathToTxt("../examples/min_path_g1.txt", 10, 40);
    g1.exportMinPathToTxt("../examples/min_path_g1.txt", 10, 50);
    g1.exportMinPathToTxt("../examples/min_path_g1.txt", 10, 60);

    adjListGraph g2("C:/Users/segun/Documents/GitHub/GraphLibrary/data/grafo_W_2.txt");
    g2.heapDijkstra(10, true, "../examples/tree_g2.txt", "../examples/dist_g2.txt");
    g2.exportMinPathToTxt("../examples/min_path_g2.txt", 10, 20);
    g2.exportMinPathToTxt("../examples/min_path_g2.txt", 10, 30);
    g2.exportMinPathToTxt("../examples/min_path_g2.txt", 10, 40);
    g2.exportMinPathToTxt("../examples/min_path_g2.txt", 10, 50);
    g2.exportMinPathToTxt("../examples/min_path_g2.txt", 10, 60);

    adjListGraph g3("C:/Users/segun/Documents/GitHub/GraphLibrary/data/grafo_W_3.txt");
    g3.heapDijkstra(10, true, "../examples/tree_g3.txt", "../examples/dist_g3.txt");
    g3.exportMinPathToTxt("../examples/min_path_g3.txt", 10, 20);
    g3.exportMinPathToTxt("../examples/min_path_g3.txt", 10, 30);
    g3.exportMinPathToTxt("../examples/min_path_g3.txt", 10, 40);
    g3.exportMinPathToTxt("../examples/min_path_g3.txt", 10, 50);
    g3.exportMinPathToTxt("../examples/min_path_g3.txt", 10, 60);

    adjListGraph g4("C:/Users/segun/Documents/GitHub/GraphLibrary/data/grafo_W_4.txt");
    g4.heapDijkstra(10, true, "../examples/tree_g4.txt", "../examples/dist_g4.txt");
    g4.exportMinPathToTxt("../examples/min_path_g4.txt", 10, 20);
    g4.exportMinPathToTxt("../examples/min_path_g4.txt", 10, 30);
    g4.exportMinPathToTxt("../examples/min_path_g4.txt", 10, 40);
    g4.exportMinPathToTxt("../examples/min_path_g4.txt", 10, 50);
    g4.exportMinPathToTxt("../examples/min_path_g4.txt", 10, 60);

    adjListGraph g5("C:/Users/segun/Documents/GitHub/GraphLibrary/data/grafo_W_5.txt");
    g5.heapDijkstra(10, true, "../examples/tree_g5.txt", "../examples/dist_g5.txt");
    g5.exportMinPathToTxt("../examples/min_path_g5.txt", 10, 20);
    g5.exportMinPathToTxt("../examples/min_path_g5.txt", 10, 30);
    g5.exportMinPathToTxt("../examples/min_path_g5.txt", 10, 40);
    g5.exportMinPathToTxt("../examples/min_path_g5.txt", 10, 50);
    g5.exportMinPathToTxt("../examples/min_path_g5.txt", 10, 60);

    return 0;
}
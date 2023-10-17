#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
#include "../include/graph.h"
#include <random>
#include <limits>

const float INF = std::numeric_limits<float>::max();

using namespace std;

/**
 * Aux functions
 */
bool readNextToken(int& token, ifstream& fin){
    char nextChar;
    fin >> nextChar;

    fin.unget(); 
    fin >> token;

    if(fin.fail()){
        return false;
    }

    return true;
}

bool comparePair(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

vector<int> sortArrayWithIndexes(const vector<int>& arr) {
    vector<pair<int, int>> indexedArray;
    vector<int> sortedArray;
    vector<int> indexes;

    // Populate the indexedArray with pairs of (element, index)
    for (int i = 0; i < arr.size(); i++) {
        indexedArray.push_back({arr[i], i});
    }

    // Sort the indexedArray based on elements
    sort(indexedArray.begin(), indexedArray.end(), comparePair);

    // Extract the sorted elements
    for (const auto& pair : indexedArray) {
        sortedArray.push_back(pair.first);
    }

    // Extract the indexes
    for (const auto& pair : indexedArray) {
        indexes.push_back(pair.second);
    }

    return indexes;
}

void Graph::BFS(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> level(nVertices, -1);
    queue<int> q;

    visited[v-1] = true;
    degree[v-1] = 0;
    father[v-1] = 0;
    level[v-1] = 0;
    q.push(v - 1);

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        cout << "Vertice: " << f+1 << endl;

        for (int w : returnNeighbors(f)) {  // Assuming adjacencyList is a vector<vector<int>>
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
                father[w] = f + 1;
                level[w] = level[f] + 1;
                degree[f]++;
            }
        }
    }

    this->nodesDegree = degree;
    this->nodesFather = father;
    this->nodesLevel = level;
    
    cout << "BFS Finalizada!" << endl;
    //for(int j = 0; j < nVertices; j++){
    //    cout << "Vertice: " << j+1 << " | Pai: " << father[j] << " | Grau: " << degree[j] << endl;
    //}
}

void Graph::DFS(int v){
    vector<bool> visited(nVertices, false);
    vector<int> degree(nVertices, 0);
    vector<int> father(nVertices, -1);
    vector<int> level(nVertices, -1);
    stack<int> s;  

    father[v-1] = 0;
    degree[v-1] = 0;
    level[v-1] = 0;
    s.push(v - 1);

    while (!s.empty()) {
        int f = s.top();
        s.pop();

        if (!visited[f]) {
            visited[f] = true;
            vector<float> neighbors = returnNeighbors(f);
            degree[f] = neighbors.size();

            for (int i = neighbors.size() - 1; i >= 0; --i) {
                int w = neighbors[i];

                if (!visited[w]) {
                    s.push(w);
                    father[w] = f + 1;
                    level[w] = level[f] + 1;
                }
            }
        }
    }

    this->nodesDegree = degree;
    this->nodesFather = father;
    this->nodesLevel = level;

    cout << "DFS Finalizada!" << endl;
    //for(int j = 0; j < nVertices; j++){
    //    cout << "Vertice: " << j+1 << " | Pai: " << father[j] << " | Grau: " << degree[j] << endl;
    //}
}

std::vector<float> Graph::heapDijkstra(int v){
    v = v - 1;
    int nV = this->getNVertices();
    std::vector<float> distance(nV, INF);
    std::vector<struct Edge>* L = this->getList();
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> pq;

    distance[v] = 0.0f;
    pq.push({distance[v], v});

    while (!pq.empty()) {
        float dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist != distance[u]) {
            continue; // Skip if we've already found a shorter path to this vertex
        }

        for (const Edge &edge : L[u]) {
            int v = edge.dest;
            float w = edge.weight;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the shortest distances from the source vertex to all vertices
    for (int i = 0; i < nV; i++) {
        cout << "Vertice: " << i+1 << " | Distancia: " << distance[i] << endl;
    }

    return distance;
}

std::vector<float> Graph::vectorDijkstra(int v){
    v = v - 1;
    int numVertices = this->getNVertices();
    std::vector<float> distance(numVertices, INF);
    std::vector<struct Edge>* L = this->getList();
    distance[v] = 0.0f;

    std::vector<bool> visited(numVertices, false);

    for (int i = 0; i < numVertices; i++) {
        // Find the unvisited vertex with the smallest distance
        int minVertex = -1;
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && (minVertex == -1 || distance[v] < distance[minVertex])) {
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = true;

        // Update distances to its neighbors
        for (const Edge &edge : L[minVertex]) {
            int neighbor = edge.dest;
            float weight = edge.weight;

            if (!visited[neighbor] && distance[minVertex] + weight < distance[neighbor]) {
                distance[neighbor] = distance[minVertex] + weight;
            }
        }
    }

    // Print the shortest distances from the source vertex to all vertices
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex: " << i + 1 << " | Distance: " << distance[i] << endl;
    }

    return distance;
}

/**
 * Graph functions
 */
bool Graph::createGraphFromTxt(std::string sFilename){
    ifstream fin(sFilename);
  
    if (!fin){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return false;
    }

    cout << "Arquivo aberto!" << endl;
    cout << "Lendo o arquivo..." << endl;

    nVertices = fin >> nVertices ? nVertices : 0;    
    
    createGraph(fin);

    fin.close();
    cout << "Arquivo lido!" << endl;
    return true;
}

int Graph::getNVertices(){
    return nVertices;
}

int Graph::getNEdges(){
    return nEdges;
}


void adjListGraph::createGraph(ifstream &fin){
    cout << "Criando grafo..." << endl;
    List = new vector<struct Edge>[nVertices];

    int token;
    int counter = 0;
    int v1;
    int v2;
    int w;

    while (readNextToken(token, fin)){
        if(counter%3 == 0){
            v1 = token;
        }else if (counter%3 == 1){
            v2 = token;
        }else{
            w = token;
            nEdges++;
            addEdgeAdjList(v1-1, v2-1, w);
        }
        counter++;
    }
}

void adjListGraph::addEdgeAdjList(int v1, int v2, float weight){
    Edge e1;
    e1.dest = v2;
    e1.weight = weight;

    Edge e2;
    e2.dest = v1;
    e2.weight = weight;

    List[v1].push_back(e1);
    List[v2].push_back(e2);
}

std::vector<float> adjListGraph::returnNeighbors(int v){
    vector<float> neighbors;

    for(int i = 0; i < List[v].size(); i++){
        neighbors.push_back(List[v][i].dest);
    }

    return neighbors;
}

void adjListGraph::printList(){
    int nV = this->getNVertices();

    for(int i = 0; i < nV; i++){
        cout << "Vertice " << i+1 << ": ";
        for(int j = 0; j < List[i].size(); j++){
            cout << List[i][j].dest+1 << "";
            cout << "(" << List[i][j].weight << ") ";
        }
        cout << endl;
    }
}

std::vector<struct Edge>* adjListGraph::getList(){
    return List;
}
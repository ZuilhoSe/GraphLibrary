#include <iostream>
#include <string>
#include <vector>

typedef class Graph{
    public:
        int nVertices;
        int nEdges = 0;
        int minDegree = -1;
        int maxDegree = -1;
        int avgDegree = -1;
        int medianDegree = -1;
        int diameter = -1;
        int nConnectedComponents = 0;
        bool hasNegativeWeight = false;

        // Graph functions
        bool createGraphFromTxt(std::string sFilename);
        int getNVertices();
        int getNEdges();
        int calcDistance(int v1, int v2);
        void BFS(int v);
        void DFS(int v);
        void exportGenTreeToTxt(std::string sFilename);
        std::vector<float> heapDijkstra(int v);
        std::vector<float> vectorDijkstra(int v);

        virtual void createGraph(std::ifstream &fin){};
        virtual std::vector<struct Edge> *getList(){};
        virtual std::vector<float> returnNeighbors(int v){};

        std::vector<int> *CC;
        std::vector<int> nodesFather;
        std::vector<int> nodesDegree;
        std::vector<int> nodesLevel;
} Graph;

typedef struct Edge{
    int dest;
    float weight;
} Edge;

typedef class adjListGraph: public Graph{
    private:
        std::vector<struct Edge> *List;        

    public:
        adjListGraph(std::string sFilename):Graph(){
            this->createGraphFromTxt(sFilename);
        };
        ~adjListGraph(){
            delete this->List;
        };
        void addEdge(int v1, int v2, float weight);
        void createGraph(std::ifstream &fin) override;
        std::vector<struct Edge> *getList() override;
        void printList();

        std::vector<float> returnNeighbors(int v) override;
}adjListGraph;
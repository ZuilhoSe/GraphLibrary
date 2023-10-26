#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include "../include/graph.h"

using namespace std;

typedef struct PesquisadorNo{
    int id;
    std::string name;
    PesquisadorNo(int id, std::string name){
        this->id = id;
        this->name = name;
    }
}PesquisadorNo;

std::vector<PesquisadorNo> createFromTxt(std::string sFilename){
    ifstream fin(sFilename);
    
    std::vector<PesquisadorNo> pesquisadores;

    if (!fin){
        cout<<endl;
        cout << "Erro ao abrir o arquivo." << endl;
        return pesquisadores;
    }
    
    int id;
    std::string name;
    std::string line;

    while (getline(fin, line)){
        size_t pos = line.find(",");
        if (pos != std::string::npos) {
            id = std::stoi(line.substr(0, pos));
            name = line.substr(pos + 1);
            pesquisadores.push_back(PesquisadorNo(id, name));
        }
    }

    fin.close();

    return pesquisadores;
}

int returnId(std::vector<PesquisadorNo> p, std::string name){
    for (int i = 0; i < p.size(); i++){
        if (p[i].name == name){
            return p[i].id;
        }
    }
    return -1;
}

void exportDistancesToTxt(string sFilename, vector<float> distances, std::vector<PesquisadorNo> p){
    cout << "Exportando distancias para o arquivo..." << endl;
    ofstream fout(sFilename);

    for (int i = 0; i < distances.size(); i++){
        fout << "Pesquisador: " << p[i].name << " | Distancia: " << distances[i] << endl;
    }
    cout << "Distancias exportadas!" << endl;

    fout.close();
}

void exportPathtoTxt(std::string sFilename, vector<int> path, std::vector<PesquisadorNo> p){
    cout << "Exportando caminho para o arquivo..." << endl;
    ofstream fout(sFilename, std::ios::app);

    if (path.size() == 0){
        fout << "Não há caminho entre os pesquisadores!" << endl;
        return;
    }

    for (int i = 0; i < path.size(); i++){
        fout << p[path[i]-1].name << " | ";
    }

    fout << endl;
    cout << "Caminho exportado!" << endl;
}

main(){
    std::vector<PesquisadorNo> p = createFromTxt("../data/rede_colaboracao_vertices.txt");

    int Dijkstra = returnId(p, "Edsger W. Dijkstra");
    int Turing = returnId(p, "Alan M. Turing");
    int Kruskal = returnId(p, "J. B. Kruskal");
    int Kleinberg = returnId(p, "Jon M. Kleinberg");
    int Tardos = returnId(p, "Éva Tardos");
    int Ratton = returnId(p, "Daniel R. Figueiredo");

    adjListGraph g("../data/rede_colaboracao.txt");
    std::vector<float> d = g.heapDijkstra(Dijkstra, false, "../data/dijkstra_tree.txt", "../data/dijkstra_distances.txt");
    exportDistancesToTxt("../data/dijkstra_distances.txt", d, p);
    std::vector<int> path = g.getPath(Dijkstra, Turing);
    exportPathtoTxt("../data/dijkstra_path.txt", path, p);
    path = g.getPath(Dijkstra, Kruskal);
    exportPathtoTxt("../data/dijkstra_path.txt", path, p);
    path = g.getPath(Dijkstra, Kleinberg);
    exportPathtoTxt("../data/dijkstra_path.txt", path, p);
    path = g.getPath(Dijkstra, Tardos);
    exportPathtoTxt("../data/dijkstra_path.txt", path, p);
    path = g.getPath(Dijkstra, Ratton);
    exportPathtoTxt("../data/dijkstra_path.txt", path, p);
}
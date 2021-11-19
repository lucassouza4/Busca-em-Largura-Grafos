#ifndef BFS_HPP
#define BFS_HPP

#include <vector>
using namespace std;

class Vertice{
public:
    int indice;
    bool visitado;
    vector<Vertice*> arestas;

    Vertice(int i);
    void addAresta(Vertice* destino);
};

class Grafo{
public:
    int qnt;
    vector<Vertice*> vertices;

    Grafo(int n);
    void add(int origem, int destino, int direcionado);
    Vertice* criarVertices(int indice);
    void BFS(int inicio, vector<Vertice*> *verticesVisitados);
    void printVisit(vector<Vertice*> *verticesVisitados);
};

#endif
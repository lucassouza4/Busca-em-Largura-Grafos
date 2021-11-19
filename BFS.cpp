#include <iostream>
#include <algorithm>
#include "BFS.hpp"
using namespace std;

Vertice::Vertice(int i)
{
    indice = i;
    visitado = false;
}
void Vertice::addAresta(Vertice *destino)
{
    arestas.push_back(destino);
}

Grafo::Grafo(int n)
{
    qnt = n;
}

void Grafo::add(int origem, int destino, int direcionado)
{
    Vertice *auxOri = criarVertices(origem);
    Vertice *auxDest = criarVertices(destino);
    if (direcionado == 0)
    {
        auxOri->addAresta(auxDest);
        auxDest->addAresta(auxOri);
    }
    else
        auxOri->addAresta(auxDest);
}

Vertice *Grafo::criarVertices(int indice)
{
    for (auto it = vertices.begin(); it != vertices.end(); it++)
    {
        if ((*it)->indice == indice)
        {
            return (*it);
        }
    }

    Vertice* v = new Vertice(indice);
    vertices.push_back(v);
    return ((*(vertices.end()-1)));
}

void Grafo::BFS(int inicio, vector<Vertice*> *verticesVisitados)
{
    int i = inicio;
    int j = 0;

    (*verticesVisitados).push_back((criarVertices(inicio)));

    while (j < (*verticesVisitados).size())
    {
        (*verticesVisitados)[j]->visitado = true;
        for (Vertice *v : (*verticesVisitados)[j]->arestas)
        {
            if (v->visitado == false)
            {
                (*verticesVisitados).push_back(v);
                v->visitado = true;
            }
        }
        j++;
    }
}

void Grafo::printVisit(vector<Vertice*> *verticesVisitados)
{
    for (Vertice *v : (*verticesVisitados))
    {
        cout << v->indice << endl;
    }
}


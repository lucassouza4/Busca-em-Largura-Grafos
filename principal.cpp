#include <iostream>
#include "BFS.hpp"
using namespace std;

int main()
{
    vector<Vertice*> verticesVisitados;
    int n, m, b, i, origem, destino, peso;

    cin >> n >> m >> b >> i;
    
    // CRIANDO GRAFO =======================================
    Grafo g = Grafo(n);

    // CRIANDO LISTA DE ADJACENCIA DOS VERTICES =============
    for (int i = 0; i < m; i++)
    {
        cin >> origem >> destino >> peso;
        g.add(origem,destino,b);
    }

    //INICIA BFS ============================================
    g.BFS(i,&verticesVisitados);
    //PRINTAR AS ARESTAS/VERTICE ============================
    g.printVisit(&verticesVisitados);

    return 0;
}
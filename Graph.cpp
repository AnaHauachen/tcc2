//
// Created by Ana Lucia on 07/08/17.
//

#include "Graph.h"
#include "Constants.h"
#include <bits/stdc++.h>


Graph::Graph(int N): n(N){ // Construtor da classe Graph
    M.resize(N);

    for(int j=0;j<N;j++){
        M[j].resize(N,INF);
    }
}

vector<double> & Graph::operator [](int i) {
    return M[i];
} // Não entendi

void Graph::edge(int a, int b, double w, bool directed){
    M[a][b]=w; // Significa que do vértice 'a' para o vértice 'b' existe uma aresta de peso 'w'


    if(!directed) { // Testa se o grafo é direcionado
        M[b][a]=w;

    }
}

void Graph::updateAresta(int a, int b){
    M[a][b] = M[a][b] * BETA;
}

#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "Graph.h"
#include "LORA.h"
#include "Constants.h"

int main() {

    int n, m; // quantidade de vértices e arestas, respectivamente.

    cin >> n >> m;

    Graph G(n);

    for(int i = 1; i <= m; i++){
        int a,b; //represeta uma aresta no formato: a -> b
        cin >> a >> b;
        G.edge(a,b,1);
    }

    vector < pair<int,int> > demandas;

    int D; //quantidade de demandas

    cin >> D;

    for(int i = 0; i < D; i++){
        int s,t; //representa uma demanda do vértice s para t.
        cin >> s >> t;
        demandas.push_back(make_pair(s,t));
    }

    LORA(G, demandas, BETA);

    return 0;
}
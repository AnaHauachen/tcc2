//
// Created by Ana Lucia on 07/08/17.
//

#ifndef TCC2_UTILS_H
#define TCC2_UTILS_H

#include "Graph.h"

vector <int> caminho_minimo(Graph G, int start, int end);
void print(vector<int> & v);
bool intersection(vector <int> v1, vector <int> v2);
vector <int> ordering_vertex(Graph G);
void coloracao(vector <int> vertices, int V, vector<vector<double> > M);

#endif //TCC2_UTILS_H

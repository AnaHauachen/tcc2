//
// Created by Ana Lucia on 07/08/17.
//

#ifndef TCC2_GRAPH_H
#define TCC2_GRAPH_H

#include <vector>

using namespace std;

class Graph {

public:

    vector<vector<double> > M; // vetor de vértices
    int n; // numero de vertices


    explicit Graph(int N);
    vector<double> & operator [](int i);
    void edge(int a, int b, double w=1.0, bool directed = false);
    void updateAresta(int a, int b);
};


#endif //TCC2_GRAPH_H

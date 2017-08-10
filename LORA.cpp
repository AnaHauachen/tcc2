//
// Created by Ana Lucia on 07/08/17.
//

#include "LORA.h"
#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <random>


using namespace std;


void LORA(Graph G, vector < pair<int,int> > demandas, double beta){
    vector < vector <int> > Paths;
    vector<int> caminho;
    vector <int> order;


    srand( time(NULL) );

    shuffle( demandas.begin(), demandas.end(), std::mt19937(std::random_device()()));


    for (int i = 0; i < demandas.size(); i++) {
        cout << "demanda : " ;
        cout <<  demandas[i].first <<" " << demandas[i].second << endl; // Imprimindo as demandas

        caminho = caminho_minimo(G, demandas[i].first, demandas[i].second);

        //print(caminho);

        Paths.push_back(caminho);

        for(int j = 0; j < caminho.size() - 1; j++){
            int u = caminho[j];
            int v = caminho[j+1];
            G.updateAresta(u,v);
        }


    }

    Graph grafoConflito( Paths.size() );

    for(int i = 0; i < Paths.size(); i++){
        for(int j = i+1; j < Paths.size(); j++){ // Descobre a interseção entre todos os caminhos do vetor Paths
            if(intersection(Paths[i], Paths[j])){
                printf("add edge caminho %d  caminho %d\n", i, j);
                grafoConflito.edge(i,j); // Se existir uma interseção entre Paths[i] e Paths[j], adicione um vértice entre i e j
            }
        }
    }

    order = ordering_vertex(grafoConflito);
    coloracao(order, grafoConflito.n, grafoConflito.M);
}
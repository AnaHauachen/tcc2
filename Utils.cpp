//
// Created by Ana Lucia on 07/08/17.
//

#include "Utils.h"
#include "Constants.h"
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>


vector <int> caminho_minimo(Graph G,int start,int end){
    // Função que retorna um vetor de inteiros,
    // ela recebe como parâmetro um Graph,
    // um vértice de início e fim na forma de inteiros

    vector<double> d;//vetor de distancia
    vector<int> p;//vetor de antecessor
    vector<int> marc;//vetor marcado
    vector<int> caminho;

    d.assign(G.n,INF); //atribuindo distancia infinita para todos os vértices
    p.assign(G.n,-1); // atribuindo -1 a todos os antecessores
    marc.assign(G.n,0); // nenhum vetor foi visitado ainda, todos recebem 0

    d[start]=0;

    while(true){

        int minIndex =-1;
        double minDist = INF; //Inicializando as variáveis

        //Encontra o vertice nao marcado com a menor distancia
        for (int i=0; i< G.n; i++){
            if( marc[i]==0 && d[i] < minDist){
                minDist = d[i];
                minIndex = i;
            }
        }

        marc[minIndex] = 1; //posiçao do vertice marcada visitada

        if(minIndex==-1 || minIndex == end) break; // sai do while se chegar ao fim do grafo
        // ou se todos os vértices já estiverem visitados

        for (int j=0; j< G.n; j++){ //atualiza todas as distancias do grafo se houver um menor caminho_minimo
            if ( d[j] > d[minIndex]+G[minIndex][j]){
                p[j]=minIndex;
                d[j]=d[minIndex]+G[minIndex][j];
            }
        }
    }
// Neste momento já temos o caminho minimo de A para B
    for(int u = end; p[u] != -1; u = p[u]){ // Poe dentro do array todos os predecessores de B até chegar em A
        caminho.push_back(u);
    }
    caminho.push_back(start); // Poe A dentro do array

    reverse( caminho.begin(), caminho.end() ); // reverte a ordem

    return caminho;
}

void print(vector<int> & v){ // void significa que não retorna nada
    cout << "caminho: ";
    for(int i : v) {
        cout << " " << i;
    }
    cout << endl;
}

bool intersection(vector <int> v1, vector <int> v2){

    //bitset armazena 0 ou 1, mesma coisa que bool porém otimizado para memória
    bitset<MAXNODES> bs1,bs2; //Dois arrays de 0 ou 1 de tamanho MAXNODES (1000)

    for(int i : v1)
        bs1.set(i);
    for(int i : v2)
        bs2.set(i); // O que faz set()?

    bs1 = bs1 & bs2; // Tá fazendo a interseção de bs1 e bs2
    return bs1.any(); // O que faz any()?
}

vector <int> ordering_vertex(Graph G){
    vector <int> order; // ?
    vector <int> grau; // Vetor de graus
    vector <bool> marc; // Vetor de marcação
    int grauMaximo;
    int pos;

    //Inicializando as variáveis
    order.assign(G.n, 0);
    grau.assign(G.n, 0);
    marc.assign(G.n, 0);
    grauMaximo = 0;

    //Acha o grau máximo do grafo G
    for(int i = 0; i < G.n; i++){
        grau[i] = 0;

        for(int j = 0; j < G.n; j++){
            if( G[i][j] != INF ) {

                grau[i]++;
            }
        }

        printf("grau[%d] = %d\n", i, grau[i]);

        grauMaximo = grau[i] > grauMaximo ? grau[i] : grauMaximo; // Se grau[i] for maior que o grauMaximo do momento, então
        // grauMaximo recebe grau[i], senão nada acontece.
    }

    printf("grau maximo %d\n", grauMaximo);

    // Não compreendi o que acontece dentro deste for
    for(int i = G.n-1; i >= 0; i--){

        int grauMinimo = grauMaximo+1;
        int pos = -1;

        for(int j = 0; j < G.n; j++){
            if(!marc[j] && grau[j] < grauMinimo){
                grauMinimo =  grau[j];
                pos = j;
            }
        }

        printf("order[%d]  =%d\n", i, pos );
        order[i] = pos;
        marc[pos] = 1;

        for(int j = 0; j < G.n; j++){
            if( j != pos && G[pos][j] ){
                grau[j]--;
            }
        }
    }
    return order;
}

//implementando a função coloração
void coloracao(vector <int> vertices, int V, vector<vector<double> > M){

    int cor[V];
    bool available[V];


    // Inicialize os V-1 vértices restantes como 'não atribuído'
    for (int u = 0; u < V; u++){
        cor[u] = -1;  // nenhuma cor atribuída a 'u'.
    }


    // Atribua cores aos V-1 vértices restantes
    for (int i = 0; i < vertices.size(); i++){
        int v = vertices[i];

        for (int cr = 0; cr < V; cr++){
            available[cr] = true;
        }


        // Processa todos os vértices adjacentes e marca as respectivas
        // cores como 'não disponível'.
        for (int j = 0; j < V; j++){
            if( M[v][j]==1 && cor[j] != -1){
                available[cor[j]] = false;
            }
        }

        // Ache a primeira cor que estiver disponível.
        for (int cr = 0; cr < V; cr++){
            if (available[cr]){
                cout << "vertice " << v << " recebe a cor " << cr << endl;
                cor[v] = cr; // Atribua a cor encontrada.
                break;
            }
        }
    }

    // Imprime o resultado
    int max_color = 0;
    for (int u = 0; u < V; u++){
        //cout << "Vertex " << u << " --->  Color " << cor[u] << endl;
        if( cor[u] > max_color) max_color = cor[u];
    }
    printf("maximo de cores %d\n", max_color);
}
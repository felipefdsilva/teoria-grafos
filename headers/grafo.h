/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef GRAFO_H
#define GRAFO_H "grafo.h"

#include <vector>

using namespace std;

class Graph {
  public:
    Graph (unsigned);//Construtor
    ~Graph();//Destrutor
    /*Métodos de encapsulamento*/
    virtual void setNeighbours (unsigned, unsigned) = 0;//configura os vizinhos de acordo com a representação
    void setNumberOfEdges (unsigned); //configura o numero de arestas
    unsigned getNumberOfVertices () const; //retorna o número de vertices
    unsigned getNumberOfEdges () const; //retorna o número de arestas
    virtual void getNeighbours (unsigned, vector<unsigned> *) = 0;//obtém os vizinhos do vertice de acordo com a representação
    /*Métodos de busca no grafo*/
    virtual void breadthFirstSearch (unsigned); //realiza a busca em largura
    //virtual void Graph::breadthFirstSearch (unsigned root, vector<unsigned> *Vertices, SpanningTree *tree)
    /*
    virtual void depthFirstSearch (unsigned); //realiza a busca em profundidade
    */
    /*Método para testes*/
    virtual void print ();//imprime o grafo
  private:
    unsigned mNumberOfVertices; //número de vértices do grafo
    unsigned mNumberOfEdges; //número de arestas do grafo
};

#endif

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef LISTA
#define LISTA "lista.h"

#include <iostream>
#include <stack>
#include "vertice-lista.h"

class AdjacencyList {
  public:
    friend ostream & operator<<(ostream& output, AdjacencyList& graph);
    /*Construtor que recebe o número de vértices*/
    AdjacencyList(unsigned);
    ~AdjacencyList();

    /*Metodos de encapsulamento*/
    AdjacencyListVertex* getVertex (unsigned); //obter vertice
    unsigned getNumberOfEdges (); //obter numero de arestas
    unsigned getNumberOfVertices () const; //obter numero de vertices
    void breadthFirstSearch (unsigned, vector <unsigned> *);
    void depthFirstSearch (unsigned);
    unsigned connectedComponents (unsigned);
    unsigned getHeight (unsigned,unsigned);
    unsigned getDiameter (unsigned);
  private:
    unsigned mNumberOfVertices; //atrituto para evitar usar frequentemente a função size() de vector
    vector <AdjacencyListVertex> mVertices; //vector com os vertices que compoem o grafo
};

#endif

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef GRAFO_H
#define GRAFO_H "grafo.h"

#include <iostream>
#include "vertice.h"

class Graph {
  /*Classe amiga usada apenas para teste*/
  friend ostream & operator<<(std::ostream &, Graph &);

  public:
    /*Construtor que recebe o número de vértices*/
    Graph(unsigned);

    /*Metodos de encapsulamento*/
    Vertex* getVertex (unsigned); //obter vertice
    unsigned getNumberOfEdges (); //obter numero de arestas
    unsigned getNumberOfVertices () const; //obter numero de vertices
    void computeDensity();
    void breadthFirstSearch (unsigned, unsigned);
    void depthFirstSearch (unsigned, unsigned);
    void connectedComponents (unsigned);
  private:
    unsigned mNumberOfVertices; //atrituto para evitar usar frequentemente a função size() de vector
    vector <Vertex> mVertices; //vector com os vertices que compoem o grafo
    float mDensity;
};

#endif

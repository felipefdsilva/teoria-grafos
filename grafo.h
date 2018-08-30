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
    /*Construtor que recebe o numero de vertices*/
    Graph(unsigned);

    /*Metodos de encapsulamento*/
    Vertex* getVertex (unsigned); //obter vertice
    unsigned getNumberOfEdges (); //obter numero de arestas
    unsigned getNumberOfVertices () const; //obter numero de vertices
    unsigned getMinDegree (); //obter grau minimo
    unsigned getMaxDegree (); // obter grau maximo
    float getAvgDegree (); //obter grau medio
    unsigned getMedianDegree (); //obter grau mediano

  private:
    unsigned mNumberOfVertices; //atrituto para evitar usar frequentemente a função size() de vector
    vector <Vertex> mVertices; //vector com os vertices que compoem o grafo
};

#endif

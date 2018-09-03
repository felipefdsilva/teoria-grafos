/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef MATRIZ
#define MATRIZ "matriz.h"

#include <vector>
#include <iostream>
#include "vertice.h"

using namespace std;

class AdjacencyMatrix {
  public:

    friend ostream & operator<<(ostream& output, AdjacencyMatrix& graph);

    AdjacencyMatrix(unsigned);
    ~AdjacencyMatrix();
    void setEntry(unsigned, unsigned);
    bool getEntry(unsigned, unsigned);
    Vertex *getVertex(unsigned);
    void breadthFirstSearch (unsigned);
    void depthFirstSearch (unsigned);
    unsigned getNumberOfEdges (); //obter numero de arestas
    unsigned getNumberOfVertices () const; //obter numero de vertices

  private:
    unsigned mNumberOfVertices;
    vector<Vertex> mVertices;
    vector<bool> mMatrix;
};

#endif 

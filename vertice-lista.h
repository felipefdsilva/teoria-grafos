/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef VERTICE_LISTA
#define VERTICE_LISTA "vertice-lista.h"

#include <vector>
#include "vertice.h"

using namespace std;

class AdjacencyListVertex: public Vertex {
  public:
    /*construtor*/
    AdjacencyListVertex ();

    void setNeighbour (unsigned);
    vector <unsigned>* getNeighbours();
    unsigned getDegree() const;

  private:
    vector <unsigned> mNeighbours; //vizinhos para lista de adjacências
};

#endif

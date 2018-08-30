/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef VERTICE_H
#define VERTICE_H "vertice.h"

#include <vector>

using namespace std;

class Vertex {
  public:
    /*construtor*/
    Vertex (unsigned, unsigned=0, char='0');

    /*metodos de encapsulamento*/
    void setNeighbour (unsigned);
    vector <unsigned>* getNeighbours();
    vector <char>* getAdjMatrixLine ();
    unsigned getDegree() const;

  private:
    vector <unsigned> mNeighbours; //vizinhos para lista de adjacências
    vector <char> mAdjMatrixLine; //Linha da matriz de adjacências
};

#endif

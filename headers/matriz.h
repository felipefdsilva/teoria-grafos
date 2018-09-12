/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef MATRIZ
#define MATRIZ "matriz.h"

#include <iostream>
#include "grafo.h"

using namespace std;

class AdjacencyMatrix: public Graph {
  public:
    AdjacencyMatrix(unsigned);//Contrutor
    ~AdjacencyMatrix();//Destrutor
    /*Métodos de Encapsulamento*/
    virtual void setNeighbours (unsigned, unsigned);
    virtual void getNeighbours (unsigned, vector<unsigned> *);
    /*Métodos de busca no grafo*/
    virtual void breadthFirstSearch (unsigned);//busca em largura
    virtual void depthFirstSearch (unsigned);//busca em profundidade
    /*Método para testes*/
    virtual void print ();//imprime o grafo

  private:
    vector<bool> mMatrix;//representação do grafo como matrix de adjacências (um vetor de booleanos)
};

#endif

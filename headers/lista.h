/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Declaração da classe lista (de adjacências)
*/

#ifndef LISTA
#define LISTA "lista.h"

#include <iostream>
#include <forward_list>
#include "grafo.h"

using namespace std;

class AdjacencyList: public Graph {
  public:

    AdjacencyList(char *); //Contrutor
    ~AdjacencyList(); //Destrutor
    /*Metodos de encapsulamento*/
    virtual void setNeighbours (unsigned, unsigned);
    virtual void getNeighbours (unsigned, vector<unsigned> *);
    /*Métodos para busca no grafo*/
    virtual void breadthFirstSearch (unsigned);//busca em largura
    //virtual void depthFirstSearch (unsigned);//busca em profundidade
    /*Método para teste*/
    virtual void print (); //imprime o grafo
    //unsigned connectedComponents (unsigned);
    //unsigned getHeight (unsigned,unsigned);
    //unsigned getDiameter (unsigned);
  private:
    vector <forward_list <unsigned> > mAdjList; //representação do grafo como vetor de listas encadeadas
};

#endif

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef SPANNING_TREE_H
#define SPANNING_TREE_H "componente-conexa.h"

//#include "vertice.h"

class Components {
  public:
    Components();
    ~Components();

    unsigned getComponentCount ();
    unsigned getComponentSize();
    void setComponentSize();
    void incrementComponents();
    void swapVerticesPosition(unsigned, unsigned);
    unsigned getNewRoot ();

  private:
    unsigned mFirstUndiscovered; //começa em 1. Se todos os vertices estão descobertos, vira 0.
    unsigned mNumberOfComponents;
    vector <unsigned> mVertices;//vetor de vertices do grafo, onde v.at(n)=n
    vector <unsigned> mComponentSize; //vetor com os tamanhos das componentes conexas
};

#endif

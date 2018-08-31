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
    Vertex (unsigned, unsigned=0, char='0', bool=false);

    /*metodos de encapsulamento*/
    void setNeighbour (unsigned);
    void setFather (unsigned);
    void setLevel (unsigned);
    void setMarkingStatus (bool); //0 é não marcado e 1 é marcado

    vector <unsigned>* getNeighbours();
    //vector <char>* getAdjMatrixLine ();
    unsigned getDegree() const;
    unsigned getFather ();
    unsigned getLevel ();
    bool getMarkingStatus ();

  private:
    unsigned mFather; //vertice pai (que descobriu este vertice)
    unsigned mLevel; //nivel na arvore geradora
    bool mMarkingStatus; //marcação (inicialmente é "não marcado")
    vector <unsigned> mNeighbours; //vizinhos para lista de adjacências
    //vector <char> mAdjMatrixLine; //Linha da matriz de adjacências
};

#endif

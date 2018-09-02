/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef _EDGE_
#define _EDGE_ "aresta.h"

class Edge {
  public:
    Edge();
    void setVertices(unsigned, unsigned);
    unsigned getVertex1();
    unsigned getVertex2();
  private:
    unsigned mVertex1, mVertex2;
};

#endif

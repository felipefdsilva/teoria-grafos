/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef VERTICE_H
#define VERTICE_H "vertice.h"

class Vertex {
  public:
    /*construtor*/
    Vertex (unsigned, unsigned, unsigned);//recebe o indice, o pai e o nivel do vertice
    Vertex (const Vertex &); //construtor de cópia
    /*metodos de encapsulamento*/
    void setIndex(unsigned); //configura o indice do vertice
    void setFather (unsigned); //salvar pai na arvore geradora
    void setLevel (unsigned); //salvar nivel na arvore geradora
    unsigned getIndex(); //obtém o indice do vertice
    unsigned getFather (); //obter pai da arvore geradora
    unsigned getLevel (); //obter nivel na arvore geradora

  protected:
    unsigned mIndex; //indice do vertice
    unsigned mFather; //vertice pai (que descobriu este vertice)
    unsigned mLevel; //nivel na arvore geradora
};

#endif

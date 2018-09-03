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
    /*recebe o numero de vertices e o status da marcação*/
    Vertex (bool=false, bool=false);

    /*metodos de encapsulamento*/
    void setFather (unsigned); //salvar pai na arvore geradora
    void setLevel (unsigned); //salvar nivel na arvore geradora
    void setDegree (unsigned); //grau do vertice
    void setMarkingStatus (bool); //'false' é não marcado e 'true' é marcado
    void setComponentStatus (bool); //define mComponentStatus (valor padrão é false)

    unsigned getDegree(); //grau do vertice
    unsigned getFather (); //obter pai da arvore geradora
    unsigned getLevel (); //obter nivel na arvore geradora
    bool getMarkingStatus (); //obter status da marcação
    bool getComponentStatus (); //obtém o valor de mComponentStatus

  protected:
    unsigned mFather; //vertice pai (que descobriu este vertice)
    unsigned mLevel; //nivel na arvore geradora
    bool mMarkingStatus; //marcação (iniciado como "não marcado")
    bool mComponentStatus; //indica se o vertice já pertence a uma componente conexa
    unsigned mDegree;
};

#endif 

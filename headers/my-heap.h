/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Declaração da classe MyHeap
*/

#ifndef MY_HEAP_H
#define MY_HEAP_H "my-heap.h"

#include <vector>
#include "headers/vertice.h"

using namespace std;

class MyHeap {
  public:
    MyHeap (unsigned); //Contrutor
    ~MyHeap(); //Destrutor
    void push (Vertex); //adiciona um elemento ao heap
    Vertex pop (); //remove a raiz do heap
    void update (unsigned, float); //atualiza a distancia de um vertice que já está no heap
    void show (); //exibe o heap
    void empty (); //destroi o heap
  private:
    vector<Vertex> mQueue;
    vector<unsigned> mHeapIndex;
};
#endif

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
    MyHeap (unsigned);
    ~MyHeap();
    void push (Vertex);
    Vertex pop ();
    void update (unsigned, float);
    void show ();
    void empty ();
  private:
    vector<Vertex> mQueue;
    vector<unsigned> mHeapIndex;
};
#endif

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include "aresta.h"

using namespace std;

Edge::Edge(){
}
void Edge::setVertices(unsigned vertex1, unsigned vertex2){
  mVertex1 = max(vertex1, vertex2);
  mVertex2 = min(vertex1, vertex2);
}
unsigned Edge::getVertex1(){
  return mVertex1;
}
unsigned Edge::getVertex2(){
  return mVertex2;
}

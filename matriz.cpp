/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <iostream>
#include <queue>
#include <stack>
#include "matriz.h"
#include "vertice.h"

ostream & operator<<(ostream& output, AdjacencyMatrix& graph){

  for (unsigned i=1; i <= graph.getNumberOfVertices(); i++){
    for (unsigned j=1; j <= graph.getNumberOfVertices(); j++){
      output << graph.getEntry(i,j) << " ";
    }
    output << endl;;
  }
  return output;
}

AdjacencyMatrix::AdjacencyMatrix(unsigned numberOfVertices):
                                mNumberOfVertices(numberOfVertices),
                                mVertices(numberOfVertices+1),
                                mMatrix((numberOfVertices+1)*(numberOfVertices)){
}

AdjacencyMatrix::~AdjacencyMatrix(){
  cout << "AdjacencyMatrix detroyed!" << endl;
}

void AdjacencyMatrix::setEntry(unsigned line, unsigned column){
  unsigned entry = line + (column-1)*mNumberOfVertices;
  mMatrix.at(entry)=true;
}

bool AdjacencyMatrix::getEntry(unsigned line, unsigned column){
  unsigned entry = column + (line-1)*mNumberOfVertices;
  return mMatrix.at(entry);
}

Vertex* AdjacencyMatrix::getVertex(unsigned vertex){
  return &mVertices.at(vertex);
}

void AdjacencyMatrix::breadthFirstSearch (unsigned root){
  cout << "Matriz Size: " << mMatrix.size() << endl;
  queue <unsigned> bdsQueue;
  unsigned vertex;
  unsigned level=0;

  for (unsigned v=1; v <= mNumberOfVertices; v++){
    (*this).getVertex(v)->setMarkingStatus(false);
  }

  (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  level++;
  bdsQueue.push(root); //colocando o vertice na fila
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção

  while (!bdsQueue.empty()){
    vertex = bdsQueue.front();
    bdsQueue.pop(); //remove vertex da fila

    for (unsigned nb=1; nb <= mNumberOfVertices; nb++){
      if (mMatrix.at(nb+(vertex-1)*mNumberOfVertices)){
        if (!(*this).getVertex(nb)->getMarkingStatus()){
          (*this).getVertex(nb)->setMarkingStatus(true);
          (*this).getVertex(nb)->setLevel(level);
          bdsQueue.push(nb);
          (*this).getVertex(nb)->setFather(vertex);
        }
      }
    }
    level++;
  }
}
void AdjacencyMatrix::depthFirstSearch (unsigned root){
  stack <unsigned> dfsStack;
  unsigned vertex, father;
  unsigned level=0;

  for (unsigned v=1; v <= mNumberOfVertices; v++){
    (*this).getVertex(v)->setMarkingStatus(false);
  }
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  dfsStack.push(root); //colocando o vertice na pilha
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção
  father = root;

  while (!dfsStack.empty()){
    vertex = dfsStack.top();
    dfsStack.pop(); //remove vertex da fila

    if (!((*this).getVertex(vertex)->getMarkingStatus())){
      (*this).getVertex(vertex)->setFather(father);
      (*this).getVertex(vertex)->setLevel((*this).getVertex(father)->getLevel()+1); //nivel da raiz é 0
      (*this).getVertex(vertex)->setMarkingStatus(true); //marcando o vertice como explorado

      for (unsigned nb=1; nb <= mNumberOfVertices; nb++){
        if (mMatrix.at(nb+(vertex-1)*mNumberOfVertices))
          dfsStack.push((nb));
        }
      father = vertex;
    }
  }
}
/*Método para obter o número de arestas do grafo*/
unsigned AdjacencyMatrix::getNumberOfEdges (){
  unsigned numberOfEdges, degree = 0;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    for (unsigned j=1; j <= mNumberOfVertices; j++){
      degree += mMatrix.at(j+(i-1)*mNumberOfVertices);
    }
    (*this).getVertex(i)->setDegree(degree);
    numberOfEdges += degree;
  }
  numberOfEdges = numberOfEdges/2;
  return numberOfEdges;
}
/*metodo para obter o numero de vertices do grafo*/
unsigned AdjacencyMatrix::getNumberOfVertices () const{
  return mNumberOfVertices;
}

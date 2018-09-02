/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <queue>
#include <stack>
#include "lista.h"

using namespace std;

/*Construtor da Classe Graph*/
AdjacencyList::AdjacencyList (unsigned numberOfVertices): mVertices(numberOfVertices+1){
  mNumberOfVertices = numberOfVertices;
}
/*Método da classe Graph para acessar um vértice fora do escopo da classe*/
AdjacencyListVertex* AdjacencyList::getVertex(unsigned vertex) {
  return &mVertices.at(vertex);
}
/*Método para obter o número de arestas do grafo*/
unsigned AdjacencyList::getNumberOfEdges (){
  unsigned numberOfEdges = 0;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    numberOfEdges += (*this).getVertex(i)->getDegree();
  }
  numberOfEdges = numberOfEdges/2;
  return numberOfEdges;
}
/*Método para obter o numero de vértices do grafo*/
unsigned AdjacencyList::getNumberOfVertices () const{
  return mNumberOfVertices;
}
/*Método que implementa a busca em largura*/
void AdjacencyList::breadthFirstSearch (unsigned root, vector<unsigned>* connectedComponent){
  queue <unsigned> bdsQueue;
  unsigned vertex;
  unsigned level=0;

  for (unsigned v=1; v <= mNumberOfVertices; v++){
    (*this).getVertex(v)->setMarkingStatus(false);
  }

  (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  connectedComponent->push_back(root);
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  level++;
  bdsQueue.push(root); //colocando o vertice na fila
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção

  vector <unsigned>* neighbours;

  while (!bdsQueue.empty()){
    vertex = bdsQueue.front();
    bdsQueue.pop(); //remove vertex da fila
    neighbours = (*this).getVertex(vertex)->getNeighbours();
    for (unsigned nb=0; nb < neighbours->size(); nb++){
      if (!(*this).getVertex(neighbours->at(nb))->getMarkingStatus()){
        (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
        connectedComponent->push_back(nb);
        (*this).getVertex(neighbours->at(nb))->setLevel(level);
        bdsQueue.push(neighbours->at(nb));
        (*this).getVertex(neighbours->at(nb))->setFather(vertex);
      }
    }
    level++;
  }
}
/*Método que implementa a busca em profundidade*/
void AdjacencyList::depthFirstSearch (unsigned root){
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
  vector <unsigned>* neighbours;

  while (!dfsStack.empty()){
    vertex = dfsStack.top();
    dfsStack.pop(); //remove vertex da fila
    if (!((*this).getVertex(vertex)->getMarkingStatus())) {
      (*this).getVertex(vertex)->setFather(father);
      (*this).getVertex(vertex)->setLevel((*this).getVertex(father)->getLevel()+1); //nivel da raiz é 0
      (*this).getVertex(vertex)->setMarkingStatus(true); //marcando o vertice como explorado

      neighbours = (*this).getVertex(vertex)->getNeighbours();

      for (unsigned nb=0; nb < neighbours->size(); nb++){
          dfsStack.push(neighbours->at(nb));
        }
      father = vertex;
    }
  }
}

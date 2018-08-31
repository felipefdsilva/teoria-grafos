/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <queue>
#include <stack>
#include "grafo.h"

using namespace std;

//Apenas para teste - Imprime um grafo arranjado como Lista de adjacências
ostream & operator<<(ostream& output, Graph& graph){
  vector <unsigned>* neighbours;
  vector <char>* matrixLine;
  /*Imprime Lista de Adjacências*/
  for (unsigned i=1; i <= graph.getNumberOfVertices(); ++i){
    output << i << "-->";
    neighbours = graph.getVertex(i)->getNeighbours();
    for (unsigned j=0; j < (*neighbours).size(); ++j){
      output << neighbours->at(j) << ", ";
    }
    output << endl;
  }/*Imprime Matriz*/
  /*for (unsigned i=1; i <= graph.getNumberOfVertices(); ++i){
    output << i << ' ';
    matrixLine = graph.getVertex(i)->getAdjMatrixLine();
    for (unsigned j=1; j <= graph.getNumberOfVertices(); ++j){
      output << matrixLine->at(j) << ' ';
    }
    cout << endl;
  }*/
  return output;
}
/*Construtor da Classe Graph*/
Graph::Graph (unsigned numberOfVertices): mVertices(numberOfVertices+1, numberOfVertices){
  mNumberOfVertices = numberOfVertices;
}
/*Método da classe Graph para acessar um vértice fora do escopo da classe*/
Vertex* Graph::getVertex(unsigned vertex) {
  return &mVertices.at(vertex);
}
/*Método para obter o número de arestas do grafo*/
unsigned Graph::getNumberOfEdges (){
  unsigned numberOfEdges = 0;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    numberOfEdges += (*this).getVertex(i)->getDegree();
  }
  numberOfEdges = numberOfEdges/2;
  return numberOfEdges;
}
/*Método para obter o numero de vértices do grafo*/
unsigned Graph::getNumberOfVertices () const{
  return mNumberOfVertices;
}
void Graph::computeDensity(){
  mDensity = 2.0*(*this).getNumberOfEdges()/(mNumberOfVertices*(mNumberOfVertices-1));
}
void Graph::breadthFirstSearch (unsigned root){
  queue <unsigned> bdsQueue;
  unsigned vertex;
  unsigned level=0;

  (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  level++;
  bdsQueue.push(root); //colocando o vertice na fila
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção

  if (mDensity > 0.6){ //caso em que é melhor representar por matriz de adjacencia
  /*  cout << "MATRIZ!!" << endl;
    vector <char>* neighbours;

    while (!bdsQueue.empty()){
      vertex = bdsQueue.front();
      bdsQueue.pop(); //remove vertex da fila
      neighbours = (*this).getVertex(vertex)->getAdjMatrixLine();
      for (unsigned nb=0; nb < neighbours->size(); nb++){
        if (neighbours->at(nb)){
          if (!(*this).getVertex(nb)->getMarkingStatus()){
            (*this).getVertex(nb)->setMarkingStatus(true);
            (*this).getVertex(nb)->setLevel(level);
            bdsQueue.push(nb);
            (*this).getVertex(nb)->setFather(vertex);
          }
        }
      }
      level++;
    }*/
  }
  else { //caso em que é nelhor representar por lista de adjacencia
    cout << "LISTA!!" << endl;
    vector <unsigned>* neighbours;

    while (!bdsQueue.empty()){
      vertex = bdsQueue.front();
      bdsQueue.pop(); //remove vertex da fila
      neighbours = (*this).getVertex(vertex)->getNeighbours();
      for (unsigned nb=0; nb < neighbours->size(); nb++){
        if (!(*this).getVertex(neighbours->at(nb))->getMarkingStatus()){
          (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
          (*this).getVertex(neighbours->at(nb))->setLevel(level);
          bdsQueue.push(neighbours->at(nb));
          (*this).getVertex(neighbours->at(nb))->setFather(vertex);
        }
      }
      level++;
    }
  }
}

void Graph::depthFirstSearch (unsigned root){
  stack <unsigned> dfsStack;
  unsigned vertex;
  unsigned level=0;

  (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  level++;
  dfsStack.push(root); //colocando o vertice na pilha
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção

  if (mDensity > 0.6){ //caso em que é melhor representar por matriz de adjacencia
  /*  cout << "MATRIZ!!" << endl;
    vector <char>* neighbours;

    while (!dfsStack.empty()){
      vertex = dfsStack.top();
      dfsStack.pop(); //remove vertex da fila
      neighbours = (*this).getVertex(vertex)->getAdjMatrixLine();
      for (unsigned nb=0; nb < neighbours->size(); nb++){
        if (neighbours->at(nb)){
          if (!(*this).getVertex(nb)->getMarkingStatus()){
            (*this).getVertex(nb)->setMarkingStatus(true);
            (*this).getVertex(nb)->setLevel(level);
            dfsStack.push(nb);
            (*this).getVertex(nb)->setFather(vertex);
          }
        }
      }
      level++;
    }*/
  }
  else { //caso em que é nelhor representar por lista de adjacencia
    cout << "LISTA!!" << endl;
    vector <unsigned>* neighbours;

    while (!dfsStack.empty()){
      vertex = dfsStack.top();
      dfsStack.pop(); //remove vertex da fila
      neighbours = (*this).getVertex(vertex)->getNeighbours();
      for (unsigned nb=0; nb < neighbours->size(); nb++){
        if (!(*this).getVertex(neighbours->at(nb))->getMarkingStatus()){
          (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
          (*this).getVertex(neighbours->at(nb))->setLevel(level);
          dfsStack.push(neighbours->at(nb));
          (*this).getVertex(neighbours->at(nb))->setFather(vertex);
        }
      }
      level++;
    }
  }
}

// void Graph::connectedComponents (unsigned V){
//   unsigned root = 1;
//   queue <unsigned> bdsQueue;
//   unsigned vertex;
//   unsigned level=0;
// 
//   (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
//   (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
//   level++;
//   bdsQueue.push(root); //colocando o vertice na fila
//   (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção
// 
//   if (mDensity > 0.6){ //caso em que é melhor representar por matriz de adjacencia
//   /*  cout << "MATRIZ!!" << endl;
//     vector <char>* neighbours;
// 
//     while (!bdsQueue.empty()){
//       vertex = bdsQueue.front();
//       bdsQueue.pop(); //remove vertex da fila
//       neighbours = (*this).getVertex(vertex)->getAdjMatrixLine();
//       for (unsigned nb=0; nb < neighbours->size(); nb++){
//         if (neighbours->at(nb)){
//           if (!(*this).getVertex(nb)->getMarkingStatus()){
//             (*this).getVertex(nb)->setMarkingStatus(true);
//             (*this).getVertex(nb)->setLevel(level);
//             bdsQueue.push(nb);
//             (*this).getVertex(nb)->setFather(vertex);
//           }
//         }
//       }
//       level++;
//     }*/
//   }
//   else { //caso em que é nelhor representar por lista de adjacencia
//     cout << "LISTA!!" << endl;
//     vector <unsigned>* neighbours;
// 	for (unsigned x=1; x <= V; x++){
// 	if (!((*this).getVertex(x)->getMarkingStatus()){
// 		while (!bdsQueue.empty()){
// 		  vertex = x;
// 		  bdsQueue.pop(); //remove vertex da fila
// 		  neighbours = (*this).getVertex(vertex)->getNeighbours();
// 		  for (unsigned nb=0; nb < neighbours->size(); nb++){
// 			if (!(*this).getVertex(neighbours->at(nb))->getMarkingStatus()){
// 			  (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
// 			  bdsQueue.push(neighbours->at(nb));
// 			  cout << (*this).getVertex(neighbours->at(nb)) << " "
// 			}
// 		  }
// 		}
// 		}
// 		cout << "\n"
// 		}
// 	  }
}

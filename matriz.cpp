/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include "matriz.h"

/*Construtor*/
AdjacencyMatrix::AdjacencyMatrix(unsigned numberOfVertices):
                                Graph(numberOfVertices),
                                mMatrix((numberOfVertices+1)*(numberOfVertices)){
}
/*Destrutor*/
AdjacencyMatrix::~AdjacencyMatrix(){
  cout << "AdjacencyMatrix detroyed!" << endl;
}
/*Configura entrada na matriz de adjacencias*/
void AdjacencyMatrix::setNeighbours(unsigned vertex1, unsigned vertex2){
  unsigned line = min (vertex1, vertex2);
  unsigned column = max (vertex1, vertex2);
  unsigned numberOfVertices = this->getNumberOfVertices();

  unsigned entry = line + (column-1)*numberOfVertices;
  mMatrix.at(entry)=true;
}
/*Procura os vizinhos do vértice na matriz de adjacencias*/
void AdjacencyMatrix::getNeighbours(unsigned vertex, vector<unsigned> *neighbours){
  unsigned numberOfVertices = this->getNumberOfVertices();
  unsigned entry;

  while (!neighbours->empty()){
    neighbours->pop_back();
  }
  for (unsigned neighbour=1; neighbour <= numberOfVertices; neighbour++){
    if (neighbour < vertex){
      entry = neighbour + (vertex-1)*numberOfVertices;
    } else {
      entry = vertex + (neighbour-1)*numberOfVertices;
    }
    if (mMatrix.at(entry)){
      neighbours->push_back(neighbour);
    }
  }
}
/*Método para imprimir a matriz de adjacencias*/
void AdjacencyMatrix::print (){
  Graph::print();
}
/*Método que executa a busca em largura*/
void AdjacencyMatrix::breadthFirstSearch (unsigned root){
  Graph::breadthFirstSearch(root);
}
/*Metodo que executa a busca em profundidade*/
void AdjacencyMatrix::depthFirstSearch (unsigned root){
  Graph::depthFirstSearch(root);
}

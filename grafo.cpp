/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include <queue>
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
  for (unsigned i=1; i <= graph.getNumberOfVertices(); ++i){
    output << i << ' ';
    matrixLine = graph.getVertex(i)->getAdjMatrixLine();
    for (unsigned j=0; j < graph.getNumberOfVertices(); ++j){
      output << matrixLine->at(j) << ' ';
    }
    cout << endl;
  }
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
/*Método para obter o grau mínimo entre o vertices de um grafo*/
unsigned Graph::getMinDegree (){
  unsigned minDegree=(*this).getVertex(1)->getDegree();

   for (unsigned i=2; i <= mNumberOfVertices; i++){
     if ((*this).getVertex(i)->getDegree()) //evita vertices sem relacionamentos
      minDegree = min(minDegree, (*this).getVertex(i)->getDegree());
  }
  return minDegree;
}
/*Método para obter o grau máximo entre os vértices de um grafo*/
unsigned Graph::getMaxDegree (){
  unsigned maxDegree=(*this).getVertex(1)->getDegree();

   for (unsigned i=2; i <= mNumberOfVertices; i++){
    maxDegree = max(maxDegree, (*this).getVertex(i)->getDegree());
  }
  return maxDegree;
}
/*Método para obter o grau médio do grafo*/
float Graph::getAvgDegree () {
  return (*this).getNumberOfEdges()*2.0/mNumberOfVertices*1.0;
}
/*Método para obter o grau mediano do grafo*/
unsigned Graph::getMedianDegree () {
	vector<unsigned> degrees; //vetor para guardar todos os graus

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    degrees.push_back((*this).getVertex(i)->getDegree());
  }
  sort(degrees.begin(), degrees.end()); //Para encontrar o grau mediano, o vector precisa estar ordenado

  if (mNumberOfVertices % 2) { //se for impar
    return degrees[(mNumberOfVertices/2)];
  } //se for par
  return (degrees[(mNumberOfVertices/2)-1]+degrees[(mNumberOfVertices/2)])/2;
}

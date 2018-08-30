/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include <iostream>
#include "grafo.h"

/*Construtor - na prática recebe apenas o numero de vertices*/
Vertex::Vertex (unsigned numberOfVertices,
                unsigned neighboursVectorSize, //possui valor padrão 0
                char matrixLineInitializer): //possui valor padrão '0'
                mNeighbours(neighboursVectorSize), //inicia o vetor de vizinhos de um vertice com tamanho zero
                mAdjMatrixLine(numberOfVertices, matrixLineInitializer){//inicia o vetor 'linha da matriz' com tamanho numberOfVertices e valor padrão zero
}
/*estabele um novo vizinho para o objeto vertice*/
void Vertex::setNeighbour (unsigned neighbour){
  mNeighbours.push_back(neighbour); //na lista de adjacencia
  mAdjMatrixLine.at(neighbour-1) = '1'; //na matriz de adjacência
}
/*metodo para acessar os vizinhos de um vertice*/
vector <unsigned>* Vertex::getNeighbours (){
  sort(&mNeighbours.at(0), &mNeighbours.at(mNeighbours.size()-1)); //ordena por otimização
  return &mNeighbours;
}
/*metodo para obter a linha correspondente ao vertice na matriz de adjacencia*/
vector <char>* Vertex::getAdjMatrixLine (){
  return &mAdjMatrixLine;
}
/*metodo para obter o grau do vertice*/
unsigned Vertex::getDegree () const{
  return mNeighbours.size();
}

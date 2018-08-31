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
                char matrixLineInitializer,
                bool markingStatus): //possui valor padrão '0'
                mNeighbours(neighboursVectorSize), //inicia o vetor de vizinhos de um vertice com tamanho zero
                //mAdjMatrixLine(numberOfVertices+1, matrixLineInitializer), //inicia o vetor 'linha da matriz' com tamanho numberOfVertices e zeros
                mMarkingStatus(markingStatus){
}
/*estabele um novo vizinho para o objeto vertice*/
void Vertex::setNeighbour (unsigned neighbour){
  mNeighbours.push_back(neighbour); //na lista de adjacencia
  //mAdjMatrixLine.at(neighbour) = '1'; //na matriz de adjacência
}
/*estabele o pai atual do vertice na arvore geradora*/
void Vertex::setFather (unsigned father){
  mFather = father;
}
/*estabele o nivel do vertice na arvore geradora*/
void Vertex::setLevel (unsigned level){
  mLevel = level;
}
/*estabele o vertice como marcado ou não marcado*/
void Vertex::setMarkingStatus (bool markingStatus){
  mMarkingStatus = markingStatus;
}
/*metodo para acessar os vizinhos de um vertice*/
vector <unsigned>* Vertex::getNeighbours (){
  sort(&mNeighbours.at(0), &mNeighbours.at(mNeighbours.size()-1)); //ordena por otimização
  return &mNeighbours;
}
/*metodo para obter a linha correspondente ao vertice na matriz de adjacencia*/
//vector <char>* Vertex::getAdjMatrixLine (){
//  return &mAdjMatrixLine;
//}
/*metodo para obter o grau do vertice*/
unsigned Vertex::getDegree () const{
  return mNeighbours.size();
}
/*método para obter o pai do vertice na arvore geradora*/
unsigned Vertex::getFather (){
  return mFather;
}
/*metodo para obter o nivel do vertice na arvore geradora*/
unsigned Vertex::getLevel (){
  return mLevel;
}
/*metodo para obter o status de marcação do vértice*/
bool Vertex::getMarkingStatus (){
  return mMarkingStatus;
}

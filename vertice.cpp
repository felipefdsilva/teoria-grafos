/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include "vertice.h"

/*Construtor*/
Vertex::Vertex (bool markingStatus){
  mMarkingStatus=markingStatus;
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
void Vertex::setDegree(unsigned degree){
  mDegree = degree;
}
unsigned Vertex::getDegree (){
  return mDegree;
}

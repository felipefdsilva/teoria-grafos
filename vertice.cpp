/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include "vertice.h"

/*Construtor*/
Vertex::Vertex (bool markingStatus, bool componentStatus){
  mMarkingStatus=markingStatus;
  mComponentStatus=componentStatus;
}
/*estabele o pai atual do vertice na arvore geradora*/
void Vertex::setFather (unsigned father){
  mFather = father;
}
/*estabele o nivel do vertice na arvore geradora*/
void Vertex::setLevel (unsigned level){
  mLevel = level;
}
/*Define o grau do vertice*/
void Vertex::setDegree(unsigned degree){
  mDegree = degree;
}
/*estabele o vertice como marcado ou não marcado*/
void Vertex::setMarkingStatus (bool markingStatus){
  mMarkingStatus = markingStatus;
}
void Vertex::setComponentStatus (bool status){
  mComponentStatus = status;
}
/*método para obter o pai do vertice na arvore geradora*/
unsigned Vertex::getFather (){
  return mFather;
}
/*metodo para obter o nivel do vertice na arvore geradora*/
unsigned Vertex::getLevel (){
  return mLevel;
}
unsigned Vertex::getDegree (){
  return mDegree;
}
/*metodo para obter o status de marcação do vértice*/
bool Vertex::getMarkingStatus (){
  return mMarkingStatus;
}
/*método para obter a informação se o vertice já foi marcado uma vez e pertece a uma componente conexa*/
bool Vertex::getComponentStatus(){
  return mComponentStatus;
}

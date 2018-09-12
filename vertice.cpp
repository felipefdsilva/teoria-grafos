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
Vertex (const Vertex &V2){
  mIndex = V2.getIndex();
  mFather = V2.getFather();
  mLevel = V2.getLevel();
}
/*Configura o indice do vertice*/
void setIndex (unsigned index){
  mIndex = index;
}
/*Estabele o pai atual do vertice na arvore geradora*/
void Vertex::setFather (unsigned father){
  mFather = father;
}
/*Estabele o nivel do vertice na arvore geradora*/
void Vertex::setLevel (unsigned level){
  mLevel = level;
}
unsigned getIndex (){
  return mIndex;
}
/*método para obter o pai do vertice na arvore geradora*/
unsigned Vertex::getFather (){
  return mFather;
}
/*metodo para obter o nivel do vertice na arvore geradora*/
unsigned Vertex::getLevel (){
  return mLevel;
}

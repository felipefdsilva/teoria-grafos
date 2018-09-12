/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include "componente-conexa.h"

Components(){
}
~Components(){
}
unsigned getComponentCount (){
  return mNumberOfComponents;
}
void setComponentSize (){
  mComponentSize.at(mNumberOfComponents-1)=mComponentSize.at(mNumberOfComponents-1)
}
void incrementComponents(){
  mNumberOfComponents++;
}
void swapVerticesPosition(unsigned discovered){
  unsigned aux = mVertices.at(mFirstUndiscovered);
  mVertices.at(mFirstUndiscovered) = discovered;
  mVertices.at(discovered) = aux;
  if (mFirstUndiscovered < mVertices.size()){
    mFirstUndiscovered++;
  }
}
unsigned getNewRoot (){
  return Vertices.at(mFirstUndiscovered);
}

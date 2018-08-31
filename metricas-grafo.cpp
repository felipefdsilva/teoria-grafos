/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include "grafo.h"
#include "metricas-grafo.h"

GraphMetrics::GraphMetrics(Graph& graph){
  unsigned degree;

  for (unsigned i=1; i<=graph.getNumberOfVertices(); i++){
      mDegrees.push_back(graph.getVertex(i)->getDegree());
  }
  sort(mDegrees.begin(), mDegrees.end());
  mSumOfDegrees = graph.getNumberOfEdges()*2.0;
}
/*Método para obter o grau mínimo entre o vertices de um grafo*/
unsigned GraphMetrics::getMinDegree (){
  return mDegrees.at(0);
}
/*Método para obter o grau máximo entre os vértices de um grafo*/
unsigned GraphMetrics::getMaxDegree (){
  return mDegrees.at(mDegrees.size()-1);
}
/*Método para obter o grau médio do grafo*/
float GraphMetrics::getAvgDegree () {
  return mSumOfDegrees/mDegrees.size()*1.0;
}
/*Método para obter o grau mediano do grafo*/
unsigned GraphMetrics::getMedianDegree () {
  unsigned numberOfVertices = mDegrees.size();

  if (numberOfVertices % 2) { //se for impar
    return mDegrees[numberOfVertices/2];
  } //se for par
  return (mDegrees[numberOfVertices/2-1]+mDegrees[numberOfVertices/2])/2;
}

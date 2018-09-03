
/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include <queue>
#include "lista.h"
#include "matriz.h"
#include "metricas.h"

ostream & operator<<(ostream& output, GraphMetrics& graphMetrics){
  output << "Grau minimo: " << graphMetrics.getMinDegree() << endl;
  output << "Grau maximo: " << graphMetrics.getMaxDegree() << endl;
  output << "Grau medio: " << graphMetrics.getAvgDegree() << endl;
  output << "Grau mediano: " << graphMetrics.getMedianDegree() << endl;
  return output;
}

GraphMetrics::GraphMetrics (AdjacencyList* graph){
  mListGraph = graph;

  for (unsigned i=1; i<=graph->getNumberOfVertices(); i++){
      mDegrees.push_back(graph->getVertex(i)->getDegree());
  }
  sort(mDegrees.begin(), mDegrees.end());
  mSumOfDegrees = graph->getNumberOfEdges()*2.0;
}
GraphMetrics::GraphMetrics (AdjacencyMatrix* graph){
  mMatrixGraph = graph;

  for (unsigned i=1; i<=graph->getNumberOfVertices(); i++){
      mDegrees.push_back(graph->getVertex(i)->getDegree());
  }
  sort(mDegrees.begin(), mDegrees.end());
  mSumOfDegrees = graph->getNumberOfEdges()*2.0;
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
/*Método para encontrar as componentes conexas de um grafo*/
void GraphMetrics::findGraphConnectedComponents (){
  //cout << *mListGraph;
  unsigned root = 1;
  vector <unsigned> component;
  unsigned exploredVertices=0;
  priority_queue <vector <unsigned> > connectedComponents;
  unsigned dumb=0;

  for (unsigned v=1; v <= mListGraph->getNumberOfVertices(); v++){
    mListGraph->getVertex(v)->setComponentStatus(false);
  }
  unsigned i=1;
  while (exploredVertices < mListGraph->getNumberOfVertices()){
    cout << "Numero de vertices explorados" << exploredVertices << endl;

    if (!mListGraph->getVertex(i)->getComponentStatus()){
      mListGraph->breadthFirstSearch(i, &component);
      connectedComponents.push(component);
      exploredVertices += component.size();
    }
    while (!component.empty()){
      component.pop_back();
    }
    i++;
  }
	while(!connectedComponents.empty()){

    cout << "Tamanho da componente: " << connectedComponents.top().size() << endl;
    for (unsigned j=0; j < connectedComponents.top().size(); j++){
      cout << connectedComponents.top().at(j) << " ";
      if (j == 20) break;
    }
    cout << endl;
    connectedComponents.pop();
    cout << endl;
  }
}
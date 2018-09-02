/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
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
  unsigned root = 1;
  vector <unsigned> connectedComponents;
  vector <unsigned> componentSize;
  unsigned sizeBefore;
  vector <bool> discoveredVertices (mListGraph->getNumberOfVertices(), false);

  unsigned stackIndex = 0;
  unsigned discoveredIndex=0;

  mListGraph->breadthFirstSearch(root, &connectedComponents);
  componentSize.push_back(connectedComponents.size());
  sizeBefore = connectedComponents.size();

  while (connectedComponents.size() != mListGraph->getNumberOfVertices()){
    for(unsigned j=0; j < sizeBefore; j++){
      discoveredVertices.at(connectedComponents.at(stackIndex))=true;
      stackIndex++;
    }

    while (discoveredVertices.at(discoveredIndex++)){
      if (discoveredIndex == discoveredVertices.size()-1)
        break;
    }
    cout << "The problem is not here!" << endl;

    if (root != discoveredIndex){
      root = discoveredIndex;
      mListGraph->breadthFirstSearch(root, &connectedComponents);
      componentSize.push_back(connectedComponents.size() - sizeBefore);
      sizeBefore = connectedComponents.size();
    }
  }

	for (unsigned i=0; i<componentSize.size(); i++){
    cout << "Tamanho da componente " << i+1 << ": "<< componentSize[i] << endl;
  }

	cout << "\n \n" << "Número de componentes conexas: " << componentSize.size() << endl;

	cout << "Maior componente: " << *max_element(componentSize.begin(), componentSize.end()) << endl;
	cout << "Menor componente: " << *min_element(componentSize.begin(), componentSize.end()) << endl;
}

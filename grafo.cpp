/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include "grafo.h"

using namespace std;

ostream & operator<<(std::ostream & output, Graph &graph){ //lista de adjacencia
  vector <unsigned> *neighbours;
  for (unsigned i=1; i <= graph.getNumberOfVertices(); ++i){
    output << i << "-->";
    neighbours = graph.getVertex(i)->getNeighbours();
    for (unsigned j=0; j < (*neighbours).size(); ++j){
      output << neighbours->at(j) << ", ";
    }
    output << endl;
  }
  return output;

}







Graph::Graph (unsigned numberOfVertices): mVertices(numberOfVertices+1){
  mNumberOfVertices = numberOfVertices;
}
Vertex* Graph::getVertex(unsigned vertex) {
  return &mVertices.at(vertex);
}
unsigned Graph::getNumberOfEdges (){
  unsigned numberOfEdges = 0;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    numberOfEdges += (*this).getVertex(i)->getDegree();
  }
  numberOfEdges = numberOfEdges/2;
  return numberOfEdges;
}
unsigned Graph::getNumberOfVertices () const{
  return mNumberOfVertices;
}
unsigned Graph::getMinDegree (){
  int minDegree = 10000*10000;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    if ((*this).getVertex(i)->getDegree()<minDegree){
    	minDegree=(*this).getVertex(i)->getDegree();};
  }
  return minDegree;
}
unsigned Graph::getMaxDegree (){
  int maxDegree = 0;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    if ((*this).getVertex(i)->getDegree()>maxDegree){
    	maxDegree=(*this).getVertex(i)->getDegree();};
  }
  return maxDegree;
}
unsigned Graph::getAvgDegree () {
  return ((*this).getNumberOfEdges()*2)/mNumberOfVertices;
}
unsigned Graph::getMedianDegree () {
	vector<unsigned> degrees;
  for (unsigned i=1; i <= mNumberOfVertices; i++){
    degrees.push_back((*this).getVertex(i)->getDegree());
  }
  sort(degrees.begin(), degrees.end());

  if (mNumberOfVertices % 2){ //se for impar
    return degrees[(mNumberOfVertices/2)+1];
  }
  else{ //se for par
  return (degrees[(mNumberOfVertices/2)]+degrees[(mNumberOfVertices/2)+1])/2;}}
  


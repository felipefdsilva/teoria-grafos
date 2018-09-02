/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <iostream>
#include <fstream>
#include "aresta.h"
#include "lista.h"
#include "matriz.h"
#include "metricas.h"

using namespace std;

int main (int argc, char *argv[]){

  unsigned numberOfVertices;
  unsigned vertex1;
  unsigned vertex2;
  unsigned root = 1;
  unsigned end = 5;
  Edge edge;
  vector<Edge> graphEdges;

  bool useMatrix = false;

  /*confere o numero de argumentos passados pela linha de comando*/
  if (argc != 2){
    cout << "Please, provide a text file with the graph description" << endl;
    cout << "Usage: ./" << argv[0] << " <graph_file.txt>" << endl; //indica como usar o programa
    exit(1);
  }

  /*leitor de arquivo*/
  ifstream file (argv[1], ifstream::in);
	//ofstream myfile;
	//myfile.open ("result.txt");

  file>>numberOfVertices; //a primeira linha é sempre o numero de vertices

  cout << "Number of Vertices: " << numberOfVertices << endl;

  /*Montagem do grafo, a partir da leitura do arquivo texto*/
  while (file.good()) {
    file >> vertex1 >> vertex2;

    if (vertex1 < numberOfVertices && vertex2 < numberOfVertices){
      edge.setVertices(vertex1, vertex2);
      graphEdges.push_back(edge);
    }
  }
  graphEdges.pop_back(); //remove a repetição da ultima aresta

  file.close();

  unsigned size = graphEdges.size();

  if (useMatrix){
    AdjacencyMatrix graph(numberOfVertices);

    for (unsigned i=0; i < size; i++){
      graph.setEntry(graphEdges.at(i).getVertex1(), graphEdges.at(i).getVertex2());
      graph.setEntry(graphEdges.at(i).getVertex2(), graphEdges.at(i).getVertex1());
    }

    while (!graphEdges.empty()){
      graphEdges.pop_back();
    }
    graph.depthFirstSearch (root);

    if (graph.getVertex(end)->getMarkingStatus()){
      cout << "Shortest path between " << root << " and " << end << endl;
      vertex1 = end;
      while (vertex1 != root){
        cout << vertex1 << ", ";
        vertex1 = graph.getVertex(vertex1)->getFather();
      }
      cout << vertex1 << endl;
    }
    else {
      cout << "There is no path between " << root << "and " << end << endl;
    }
    cout << "Numero de vertices: " << graph.getNumberOfVertices() << endl;
    cout << "Numero de arestas: " << graph.getNumberOfEdges() << endl;
    GraphMetrics graphMetrics(&graph);
    cout << graphMetrics;
  }
  else {
    AdjacencyList graph (numberOfVertices);

    for (unsigned i=0; i < size; i++){
      graph.getVertex(graphEdges.at(i).getVertex1())->setNeighbour(graphEdges.at(i).getVertex2());
      graph.getVertex(graphEdges.at(i).getVertex2())->setNeighbour(graphEdges.at(i).getVertex1());
    }
    while (!graphEdges.empty()){
      graphEdges.pop_back();
    }
    vector <unsigned> connectedComponents;
    graph.breadthFirstSearch (root, &connectedComponents);

    if (graph.getVertex(end)->getMarkingStatus()){
      cout << "Shortest path between " << root << " and " << end << endl;
      vertex1 = end;
      while (vertex1 != root){
        cout << vertex1 << ", ";
        vertex1 = graph.getVertex(vertex1)->getFather();
      }
      cout << vertex1 << endl;
    }
    else {
      cout << "There is no path between " << root << "and " << end << endl;
    }
    cout << vertex1 << endl;
    cout << "Numero de vertices: " << graph.getNumberOfVertices() << endl;
    cout << "Numero de arestas: " << graph.getNumberOfEdges() << endl;

    GraphMetrics graphMetrics(&graph);
    cout << graphMetrics;
    graphMetrics.findGraphConnectedComponents();
  }
}

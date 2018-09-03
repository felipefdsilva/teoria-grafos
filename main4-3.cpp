/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#include "aresta.h"
#include "lista.h"
#include "matriz.h"
#include "metricas.h"

using namespace std::chrono;

int main (int argc, char *argv[]){

  unsigned numberOfVertices;
  unsigned vertex1, vertex2;
  Edge edge;
  vector<Edge> graphEdges;
  bool useMatrix = true;

  /*confere o numero de argumentos passados pela linha de comando*/
  if (argc != 2){
    cout << "Please, provide a text file with the graph description" << endl;
    cout << "Usage: ./" << argv[0] << " <graph_file.txt>" << endl; //indica como usar o programa
    exit(1);
  }

  /*leitor de arquivo*/
  ifstream file (argv[1], ifstream::in);

  file >> numberOfVertices; //primeira linha é sempre o numero de vertices do grafo
  /*Montagem do grafo, a partir da leitura do arquivo texto*/
  while (file.good()) {
    file >> vertex1 >> vertex2;

    if (vertex1 <= numberOfVertices && vertex2 <= numberOfVertices){
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
    vector <unsigned> connectedComponents;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (unsigned i=1; i < 1000; i++){
      graph.depthFirstSearch (i);
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "LEVOU: " << duration/1000 << " milisegundos" << endl;
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
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (unsigned i=1; i<1000; i++){
      graph.depthFirstSearch (i);
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << "LEVOU: " << duration/1000 << " milisegundos" << endl;
  }
  return 0;
}

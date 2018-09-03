/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

/*programa de teste para a 4.1*/

#include <iostream>
#include <fstream>
#include "aresta.h"
#include "lista.h"
#include "matriz.h"

using namespace std;

int main (int argc, char *argv[]){

  unsigned numberOfVertices;
  unsigned vertex1, vertex2;
  bool useMatrix = false;

  Edge edge;
  vector<Edge> graphEdges;

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
    cin.get();
  } else {
    AdjacencyList graph (numberOfVertices);

    for (unsigned i=0; i < size; i++){
      graph.getVertex(graphEdges.at(i).getVertex1())->setNeighbour(graphEdges.at(i).getVertex2());
      graph.getVertex(graphEdges.at(i).getVertex2())->setNeighbour(graphEdges.at(i).getVertex1());
    }
    while (!graphEdges.empty()){
      graphEdges.pop_back();
    }
    cin.get();
  }
  return 0;
}

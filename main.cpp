/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

//#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "grafo.h"

using namespace std;

int main (int argc, char *argv[]){

  string line;
  unsigned vertex1, vertex2;

  if (argc != 2){
    cout << "Please, provide a text file with the graph description" << endl;
    exit(1);
  }

  ifstream file (argv[1], ifstream::in);
	ofstream myfile;
	myfile.open ("result.txt");

  getline(file, line);

  Graph graph(stoul(line));

  cout << "Graph size: " << graph.getNumberOfVertices() << endl;
  while (file.good()) {
    //cout << line << endl;
    string v1, v2;
    file>>v1>>v2;
    vertex1 = stoul(v1);
    vertex2 = stoul(v2);
    //cout << "Vertex 1: " << vertex1 << endl;
    //cout << "Vertex 2: " << vertex2 << endl;
    graph.getVertex(vertex1)->setNeighbour(vertex2);
    graph.getVertex(vertex2)->setNeighbour(vertex1);

    getline(file, line);
  }
//   cout << graph;

  file.close();

  myfile << "Numero de vértices: " << graph.getNumberOfVertices() << endl;
  myfile << "Numero de arestas: " << graph.getNumberOfEdges() << endl;
  myfile << "Grau mínimo: " << graph.getMinDegree() << endl;
  myfile << "Grau máximo: " << graph.getMaxDegree() << endl;
  myfile << "Grau médio: " << graph.getAvgDegree() << endl;
  myfile << "Grau mediano: " << graph.getMedianDegree() << endl;
  
  myfile.close();

}

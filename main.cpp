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
#include "metricas-grafo.h"

using namespace std;

int main (int argc, char *argv[]){

  string numberOfVertices;
  string vertex1, vertex2;
  unsigned v1, v2;

  /*confere o numero de argumentos passados pela linha de comando*/
  if (argc != 2){
    cout << "Please, provide a text file with the graph description" << endl;
    cout << "Usage: ./" << argv[0] << "<graph_file.txt>" << endl; //indica como usar o programa
    exit(1);
  }

  /*leitor de arquivo*/
  ifstream file (argv[1], ifstream::in);
	//ofstream myfile;
	//myfile.open ("result.txt");

  file>>numberOfVertices; //a primeira linha é sempre o numero de vertices

  Graph graph(stoul(numberOfVertices)); //instanciando a objeto grafo a iniciando-o com o numero de vertices

  //cout << "Number of Vertices: " << graph.getNumberOfVertices() << '\n' << endl; //teste

  /*Montagem do grafo, a partir da leitura do arquivo texto*/
  while (file.good()) {
    file >> vertex1 >> vertex2;

    if (!((v1 == stoul (vertex1)) && (v2 == stoul (vertex2))) && stoul(vertex1) <= graph.getNumberOfVertices() && stoul(vertex2) <= graph.getNumberOfVertices()) { /*evita releitura da ultima linha*/
      v1 = stoul(vertex1);
      v2 = stoul (vertex2);
      graph.getVertex(v1)->setNeighbour(v2);
      graph.getVertex(v2)->setNeighbour(v1);
    }
  }
  file.close();

  //cout << graph; //teste
  
  unsigned V = graph.getNumberOfVertices();
  
//   for (unsigned i = 1; i <=5; i++){
//   	for (unsigned j = 10; j<=50; j+=10 ){
// 		  int root = i;
// 		  int end = j;
// 
// 		  graph.breadthFirstSearch (root, V);
// 
// 		  cout << "Shortest path between " << root << " and " << end << endl;
// 		  v1 = end;
// 		  if (graph.getVertex(end)->getMarkingStatus()){
// 		  while (v1 != root){
// 			cout << v1 << ", ";
// 			v1 = graph.getVertex(v1)->getFather();
// 		  }
// 		  cout << v1 << endl;}
// 		  else {cout << "No path between " << root << " and " << end << endl;}
//   
//   }
//   }

	graph.connectedComponents(V);


  GraphMetrics graphMetrics(graph);

  cout << "Numero de vertices: " << graph.getNumberOfVertices() << endl;
  cout << "Numero de arestas: " << graph.getNumberOfEdges() << endl;
  cout << "Grau minimo: " << graphMetrics.getMinDegree() << endl;
  cout << "Grau maximo: " << graphMetrics.getMaxDegree() << endl;
  cout << "Grau medio: " << graphMetrics.getAvgDegree() << endl;
  cout << "Grau mediano: " << graphMetrics.getMedianDegree() << endl;

  /*myfile.close();*/
}

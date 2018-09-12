/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include <chrono>
#include "lista.h"
//#include "matriz.h"
//#include "metricas.h"

using namespace std::chrono;

int main (int argc, char *argv[]){

  unsigned numberOfVertices;
  unsigned vertex1, vertex2;
  unsigned auxV1, auxV2;
  unsigned edgeCount = 0;
  Graph *pGraph;

  /*confere o numero de argumentos passados pela linha de comando*/
  if (argc != 3){
    cout << "Please, provide a text file with the graph description" << endl;
    cout << "Usage: ./" << argv[0] << " <graph_file.txt> --<representation [matrix][list]>"  << endl; //indica como usar o programa
    exit(1);
  }
  if (strcmp(argv[2], "--matrix") && strcmp(argv[2], "--list")){
    cout << "Please, chose a representation (matrix or list)" << endl;
    cout << argv[2] << endl;
    exit(1);
  }

  /*leitor de arquivo*/
  ifstream file (argv[1], ifstream::in);

  file >> numberOfVertices; //primeira linha é sempre o número de vértices do grafo
  /*Montagem do grafo, a partir da leitura do arquivo texto*/

  pGraph = new AdjacencyList(numberOfVertices);

  while (file.good()) {
    file >> vertex1 >> vertex2;
    if ((vertex1 != auxV1) || (vertex2 != auxV2)){ //evita releitura da ultima linha
      if (vertex1 <= numberOfVertices && vertex2 <= numberOfVertices){ //evita leitura de vertices invalidos
        pGraph->setNeighbours(vertex1, vertex2);
        edgeCount++;
      }
    }
    auxV1 = vertex1;
    auxV2 = vertex2;
  }
  file.close();

  pGraph->setNumberOfEdges(edgeCount);
  cout << "graph representation done" << endl;
  cout << "Started BFS!" << endl;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  pGraph->breadthFirstSearch (1);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>( t2 - t1 ).count();
  cout << "Took: " << duration/1000 << " miliseconds" << endl;
  return 0;
}
/*for (unsigned i=0; i<1000; i++){
      graph.breadthFirstSearch (i, &connectedComponents);
    }

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
    }*/



 /*unsigned V = graph.getNumberOfVertices();

    GraphMetrics graphMetrics(&graph);

    time_t time0;   // create timers.
    time_t time1;

    time(&time0);


	graph.connectedComponents(V);

	if(graph.connectedComponents(V)==1){
	cout << "Diâmetro "<< graph.getDiameter(V)<< "\n" << endl;}
	else{
	cout << "Diâmetro infinito" << "\n" <<endl;
	}
	time(&time1);

	double seconds = (time1 - time0);

    cout << "seconds since start: " << seconds <<'\n';

    ofstream out("metricas.txt"); // redireciona o cout para um arquivo
    streambuf *coutbuf = std::cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    cout << "Numero de vertices: " << graph.getNumberOfVertices() << endl;
    cout << "Numero de arestas: " << graph.getNumberOfEdges() << endl;
    cout << graphMetrics;

    cout.rdbuf(coutbuf);
  }*/


    /*if (argv[2] == "--matrix"){
      pGraph =  new AdjacencyMatrix(numberOfVertices);

      while (file.good()) {
        file >> vertex1 >> vertex2;
        if ((vertex1 != auxV1) || (vertex2 != auxV2)){ //evita releitura da ultima linha
          if (vertex1 <= numberOfVertices && vertex2 <= numberOfVertices){ //evita leitura de vertices invalidos
            pGraph->setNeighbours(vertex1, vertex2);
            edgeCount++;
          }
        }
        auxV1 = vertex1;
        auxV2 = vertex2;
      }
  } else {*/

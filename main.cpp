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
  unsigned vertex1, vertex2;
  //unsigned root = 1;
  //unsigned end = 5;
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
    for (unsigned i=0; i < 1000; i++){
      graph.breadthFirstSearch (i);
    }
    /*
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
    cout << graphMetrics;*/
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
    //for (unsigned i=0; i<1000; i++){
    //  graph.breadthFirstSearch (i, &connectedComponents);
    //}

    /*if (graph.getVertex(end)->getMarkingStatus()){
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
    cout << "Numero de vertices: " << graph.getNumberOfVertices() << endl;
    cout << "Numero de arestas: " << graph.getNumberOfEdges() << endl;
	
	
	unsigned V = graph.getNumberOfVertices();
	
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
	
	double seconds = time1 - time0;

    cout << "seconds since start: " << seconds <<'\n';
    
    ofstream out("metricas.txt"); // redireciona o cout para um arquivo
    streambuf *coutbuf = std::cout.rdbuf(); 
    cout.rdbuf(out.rdbuf());
    
    cout << graphMetrics;
    
    cout.rdbuf(coutbuf);
  }
  return 0;
}
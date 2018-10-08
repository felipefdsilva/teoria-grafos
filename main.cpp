/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação do programa de testes da biblioteca de grafos
*/

//#include <time.h>
//#include <chrono>
#include <iostream>
#include "headers/lista.h"

//using namespace std::chrono;
using namespace std;

int main (int argc, char *argv[]){

  Graph *pGraph;

  /*confere o numero de argumentos passados pela linha de comando*/
  if (argc != 2){
    cout << "Please, provide a text file with the graph description" << endl;
    cout << "Usage: ./" << argv[0] << " <graph_file.txt>"  << endl; //indica como usar o programa
    exit(1);
  }

  pGraph = new AdjacencyList(argv[1]);
  cout << "Graph representation done." << endl;

  pGraph->print();

  /*
  cout << "Started BFS!" << endl;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  pGraph->breadthFirstSearch (1);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>( t2 - t1 ).count();
  cout << "Took: " << duration/1000 << " miliseconds" << endl;
  return 0;*/
}

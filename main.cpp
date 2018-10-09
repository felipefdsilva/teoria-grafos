/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação do programa de testes da biblioteca de grafos
*/

#include <ctime>
#include <chrono>
#include <iostream>
#include "headers/lista.h"

using namespace std::chrono;

int main (int argc, char *argv[]){

  unsigned vertex;
  float eccentricity;
  float duration;
  Graph *pGraph;

  /*confere o numero de argumentos passados pela linha de comando*/
  if (argc != 2){
    cout << "Please, provide a text file with the graph description" << endl;
    cout << "Usage: ./" << argv[0] << " <graph_file.txt>"  << endl; //indica como usar o programa
    exit(1);
  }

  pGraph = new AdjacencyList(argv[1]);
  cout << "Graph representation done." << endl;

  //pGraph->print()
  clock_t start;
  start = clock();

  cout << "Distância média: " << pGraph->averageDistance() << endl;
 	teste.search("Antonio Albano", "Alex Aussem");

 	for (int i=1; i<=10; i++){
 		vertex = rand() % pGraph->getNumberOfVertices()+1;
 		eccentricity = pGraph->eccentricity(vertex);

    if (eccentricity < INT_MAX){
      cout<<"Excentricidade: "<< eccentricity << endl;
    } else {
      cout << "Excentricidade infinita" << endl;
    }
	}
  pGraph->greatestDegrees();
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  cout << "Tempo de Execução: " << duration << endl;
  //cout << "Tempo de Execução médio: " << duration/N << endl;
  return 0;
}

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
#include "lista.h"

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
  cout << "Grafo " << argv[1] << endl;

  //pGraph->print()
  clock_t start;
  start = clock();

  /*Caso de uso 1*/
  /*
  cout << "Distancia e caminho minimo" << endl;
  pGraph->search(1, 10);
  pGraph->search(1, 20);
  pGraph->search(1, 30);
  pGraph->search(1, 40);
  pGraph->search(1, 50);
  */
  /*Caso de uso 2*/
  cout << "Excentricidades:" << endl;
  cout << "Vertice 10: " << pGraph->eccentricity(10) << endl;
  cout << "Vertice 20: " << pGraph->eccentricity(20) << endl;
  cout << "Vertice 30: " << pGraph->eccentricity(30) << endl;
  cout << "Vertice 40: " << pGraph->eccentricity(40) << endl;
  cout << "Vertice 50: " << pGraph->eccentricity(50) << endl;

/*
  cout << "Distancia media: ";
  cout << pGraph->averageDistance() << endl;

  cout << "Calculando caminho minimo entre pesquisadores" << endl;
 	pGraph->minPathBetweenResearchers("Antonio Albano", "Alex Aussem");
  cout << "Fim do calculo de caminho minimo" << endl;

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
  cout << "Tempo de Execução: " << duration << endl;*/
  //cout << "Tempo de Execução médio: " << duration/N << endl;
  return 0;
}

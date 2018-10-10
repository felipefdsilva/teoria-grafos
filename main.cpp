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
#include <cstdlib> //rand
#include "lista.h"

using namespace std::chrono;

int main (int argc, char *argv[]){

  high_resolution_clock::time_point t1, t2;
  unsigned vertex, n, numberOfVertices;
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
  //cout << "Graph representation done." << endl;
  cout << "Grafo " << argv[1] << endl;
  //pGraph->print()

  /*Estudo de Caso 1*/
  /*
  cout << "Distancia e caminho minimo" << endl;
  pGraph->search(1, 10);
  pGraph->search(1, 20);
  pGraph->search(1, 30);
  pGraph->search(1, 40);
  pGraph->search(1, 50);
  */
  /*Estudo de Caso 2*/
  /*
  cout << "Excentricidades:" << endl;
  cout << "Vertice 10: " << pGraph->eccentricity(10) << endl;
  cout << "Vertice 20: " << pGraph->eccentricity(20) << endl;
  cout << "Vertice 30: " << pGraph->eccentricity(30) << endl;
  cout << "Vertice 40: " << pGraph->eccentricity(40) << endl;
  cout << "Vertice 50: " << pGraph->eccentricity(50) << endl;
  */
  /*Estudo de caso 3*/
  /*
  cout << "Tempo medio para calculo da excentricidade de um vertice" << endl;
  srand (time(nullptr));
  duration=0;
  numberOfVertices = pGraph->getNumberOfVertices()+1;
  for (n=0; n < 100; n++){
    vertex = rand() % numberOfVertices;
    t1 = high_resolution_clock::now();
    pGraph->eccentricity(vertex);
    t2 = high_resolution_clock::now();
    duration += duration_cast<microseconds>(t2-t1).count();
  }
  cout << duration/1000000/n << " s" << endl;
  */
  /*Estudo de caso 4*/
  /*
  cout << "Obtendo a arvore geradora minima" << endl;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  cout << "Peso: " << pGraph->prim(1) << endl;
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2-t1).count();
  cout << "Tempo de Execucao: " << duration/1000000 << " s" << endl;
  */
  /*Estudo de caso 5*/
  /*
  cout << "Distancia media: ";
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  cout << pGraph->averageDistance() << endl;
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2-t1).count();
  cout << "Tempo de Execucao: " << duration/1000000 << " s" << endl;
  */
  /*Estudo de caso 6*/
  cout << "Calculando caminho minimo entre pesquisadores" << endl;
 	pGraph->minPathBetweenResearchers("Edsger W. Dijkstra", "Alan M. Turing");
  pGraph->minPathBetweenResearchers("Edsger W. Dijkstra", "J. B. Kruskal");
  pGraph->minPathBetweenResearchers("Edsger W. Dijkstra", "Jon M. Kleinberg");
  pGraph->minPathBetweenResearchers("Edsger W. Dijkstra", "Éva Tardos");
  pGraph->minPathBetweenResearchers("Edsger W. Dijkstra", "Daniel R. Figueiredo");

  /*Estudo de caso 7*/
  /*
  cout << "Maiores graus na arvore geradora" << endl;
  pGraph->greatestDegrees();
  */
  return 0;
}

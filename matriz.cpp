/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação do classe matriz (de adjacências)
*/

#include <fstream>
#include "headers/matriz.h"

using namespace std;

/*Construtor*/
AdjacencyMatrix::AdjacencyMatrix(char *graphFile): mMatrix(1,0){
  unsigned numberOfVertices;
  unsigned vertex1, vertex2, weight;
  unsigned auxV1, auxV2;
  unsigned edgeCount = 0;

  ifstream file (graphFile, ifstream::in); //abre arquivo para leitura

  /*Montagem do grafo, a partir da leitura do arquivo texto*/
  file >> numberOfVertices; //primeira linha é sempre o número de vértices do grafo
  Graph::setNumberOfVertices (numberOfVertices); //salva o numero de vertices no objeto da classe grafo
  mMatrix.resize((numberOfVertices+1)*(numberOfVertices), 0); //redimensiona a matriz de acordo com o grafo

  while (file.good()) {
    file >> vertex1 >> vertex2 >> weight;
    cout << "vertex1 = " << vertex1 << " vertex2 = " << vertex2 << " weight = " << weight << endl;
    if ((vertex1 != auxV1) || (vertex2 != auxV2)){ //evita releitura da ultima linha
      if (vertex1 <= numberOfVertices && vertex2 <= numberOfVertices){ //evita leitura de vertices invalidos
        setNeighbours(vertex1, vertex2);
        edgeCount++;
      }
    }
    auxV1 = vertex1;
    auxV2 = vertex2;
  }
  /*Fim da montagem do grafo*/

  file.close(); //fim da leitura do arquivo

  setNumberOfEdges(edgeCount); //salva o numero de arestas no objeto da classe grafo
}
/*Destrutor*/
AdjacencyMatrix::~AdjacencyMatrix(){
  cout << "AdjacencyMatrix detroyed!" << endl;
}
/*Configura entrada na matriz de adjacencias*/
void AdjacencyMatrix::setNeighbours(unsigned vertex1, unsigned vertex2){
  unsigned line = min (vertex1, vertex2);
  unsigned column = max (vertex1, vertex2);
  unsigned numberOfVertices = this->getNumberOfVertices();

  unsigned entry = line + (column-1)*numberOfVertices;
  mMatrix.at(entry)=true;
}
/*Procura os vizinhos do vértice na matriz de adjacencias*/
void AdjacencyMatrix::getNeighbours(unsigned vertex, vector<unsigned> *neighbours){
  unsigned numberOfVertices = this->getNumberOfVertices();
  unsigned entry;

  while (!neighbours->empty()){
    neighbours->pop_back();
  }
  for (unsigned neighbour=1; neighbour <= numberOfVertices; neighbour++){
    if (neighbour < vertex){
      entry = neighbour + (vertex-1)*numberOfVertices;
    } else {
      entry = vertex + (neighbour-1)*numberOfVertices;
    }
    if (mMatrix.at(entry)){
      neighbours->push_back(neighbour);
    }
  }
}
/*Método para imprimir a matriz de adjacencias*/
void AdjacencyMatrix::print (){
  Graph::print();
}
/*Método que executa a busca em largura*/
void AdjacencyMatrix::breadthFirstSearch (unsigned root){
  Graph::breadthFirstSearch(root);
}
/*Metodo que executa a busca em profundidade*/
/*
void AdjacencyMatrix::depthFirstSearch (unsigned root){
  Graph::depthFirstSearch(root);
}
*/

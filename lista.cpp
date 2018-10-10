/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe lista de adjacências
*/

#include <iostream> //para função print
#include <fstream> //para leitura/escrita de arquivo
#include "split.h"
#include "lista.h"

using namespace std;

/*Construtor da Classe AdjacencyList*/
AdjacencyList::AdjacencyList (char *graphFile) {
  unsigned numberOfVertices;
  unsigned vertex1, vertex2;
  float weight;
  unsigned begin;
  unsigned edgeCount = 0;
  string line;
  bool flag = false;
  vector <string> verticesAndWeight (0);

  ifstream file (graphFile, ifstream::in); //abre arquivo para leitura

  /*Montagem do grafo, a partir da leitura do arquivo texto*/
  file >> numberOfVertices; //primeira linha é sempre o número de vértices do grafo
  Graph::setNumberOfVertices (numberOfVertices); //salva o numero de vertices no objeto da classe grafo
  mAdjList.resize(numberOfVertices+1);
  resizeDegreeVector(numberOfVertices+1);

  getline (file, line, '\n');

  while (file.good()) {
    getline(file, line, '\n');
    splitString (line, " ", verticesAndWeight, begin);
    if ((verticesAndWeight.size()-begin) == 3 && flag == false){
      setWeightedGraphStatus(true);
    }
    flag = true;
    if (begin != verticesAndWeight.size()) { //evita ler o "\n" no final do arquivo
      vertex1 = stoi (verticesAndWeight.at(begin), nullptr, 10); //converte vertice de string para inteiro
      vertex2 = stoi (verticesAndWeight.at(begin+1), nullptr, 10); //converte vertice de string para inteiro
      if (vertex1 <= numberOfVertices && vertex2 <= numberOfVertices){ //evita leitura de vertices invalidos
        setNeighbours(vertex1, vertex2); //adiciona info na lista de adjacências
        edgeCount++; //incrementa numero de arestas
        if (weighted()){ //se existe peso
          weight = stof(verticesAndWeight.at(begin+2), nullptr);
          if (weight < 0){
            cout << "Os pesos das arestas devem ser todos positivos" << endl;
            exit (1);
          }
          Graph::setWeight (vertex1, vertex2, weight);
        }
      }
    }
  }
  /*Fim da montagem do grafo*/
  file.close(); //fim da leitura do arquivo
  setNumberOfEdges(edgeCount); //salva o numero de arestas no objeto da classe grafo
}
/*Destrutor*/
AdjacencyList::~AdjacencyList (){
}
//Apenas para teste - Imprime um grafo arranjado como Lista de adjacências
void AdjacencyList::print (){
  Graph::print();
}
/*Adiciona o vertice a lista de vizinhos de cada vertice*/
void AdjacencyList::setNeighbours (unsigned vertex1, unsigned vertex2){
  mAdjList.at(vertex1).push_front(vertex2);
  mAdjList.at(vertex2).push_front(vertex1);

  incrementDegree(vertex1);
  incrementDegree(vertex2);
}
/*retorna por referência um vetor com os vizinhos de vertex*/
void AdjacencyList::getNeighbours (unsigned vertex, vector<unsigned> *neighbours){
  forward_list<unsigned>::iterator it = mAdjList.at(vertex).begin();

  while (!neighbours->empty()){
    neighbours->pop_back();
  }
  for (; it != mAdjList.at(vertex).end(); it++){
    neighbours->push_back(*it);
  }
}
/*Método que implementa a busca em largura*/
void AdjacencyList::breadthFirstSearch (unsigned root){
  Graph::breadthFirstSearch(root);
}
/*Método que implementa a busca de menores caminhos em um grafo com peso*/
float AdjacencyList::dijkstra (unsigned root){
  return Graph::dijkstra(root);
}
/*Método que implmenta um algoritmo gerador de mst's mínimas em um grafo com pesos*/
float AdjacencyList::prim(unsigned root){
  float totalWeight = 0;
  float peso = Graph::dijkstra(root);
  ofstream myfile;

  cout << "Criando arquivo da mst" << endl;
  myfile.open("mst.txt");
  myfile << getNumberOfVertices() << endl;
  for (int i = 0; i < mParent.size(); i++) {
    if(mParent[i] > 0){
      myfile << i + 1 << " " << mParent[i] << " " << mMinDist[i] << endl;
      totalWeight+=mMinDist.at(i);//com mais um vertice adicionado a mst, o peso dela aumenta com o custo do vertice
    }
  }
  myfile.close();
  return peso;
}
/*Imprime os vizinhos de um vertice*/
void AdjacencyList::printNeighbours(const char *pName){
  Graph::printNeighbours(pName);
}

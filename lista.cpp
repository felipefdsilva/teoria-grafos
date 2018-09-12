/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <fstream>
#include <iostream>
#include "lista.h"

using namespace std;

/*Construtor da Classe AdjacencyList*/
AdjacencyList::AdjacencyList (unsigned numberOfVertices): Graph(numberOfVertices),
                                                          mAdjList(numberOfVertices+1){
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
/*Método que implementa a busca em profundidade*/
/*
void AdjacencyList::depthFirstSearch (unsigned root){
  Graph::depthFirstSearch(root);
}
*/
/*
unsigned AdjacencyList::connectedComponents (unsigned V){
  stack <unsigned> dfsStack;
  unsigned vertex;
  vector <unsigned> componentsize; // vetor de tamanho de componentes, com mesmo indice de components
  vector <vector<int> > components; //vetor de vetores de componentes
  vector <int> component;
  unsigned numComponent=1;
  unsigned root = x;
  vector <unsigned>* neighbours;

  for (unsigned x=1; x <= V; x++){
    (*this).getVertex(x)->setMarkingStatus(false);
  }

	for (unsigned x=1; x <= V; x++){
  	if (!((*this).getVertex(x)->getMarkingStatus())){
  		component.clear(); // zera o vetor componente atual
  		component.push_back(root); // adiciona a raiz da componente atual ao seu vetor
  		(*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  		dfsStack.push(root); //colocando o vertice na pilha
  		while (!dfsStack.empty()){
			  vertex = dfsStack.top();
			  dfsStack.pop(); //remove vertex da fila
			  neighbours = (*this).getVertex(vertex)->getNeighbours();
			  for (unsigned nb=0; nb < neighbours->size(); nb++){
					if (!(*this).getVertex(neighbours->at(nb))->getMarkingStatus()){
					  (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
					  dfsStack.push(neighbours->at(nb));
						component.push_back(neighbours->at(nb)); // adiciona o vertice à componente atual
					  numComponent++; // aumenta em 1 o tamanho da componente
          }
			  }
			}
  		components.push_back(component); // adiciona o vetor da componente atual ao vetor de componentes
  		componentsize.push_back(numComponent); // adiciona o tamanho da componente ao componentsize
    }
  }

	cout << "\n \n" << "Número de componentes conexas: " << componentsize.size() << endl;

	cout << "Tamanho da maior componente: " << *max_element(componentsize.begin(), componentsize.end()) << endl;
	cout << "Tamanho da menor componente: " << *min_element(componentsize.begin(), componentsize.end()) << endl;

	sort(components.begin(), components.end(), [](const vector<int>& a, const vector<int>& b) {return a.size() > b.size();});

  ofstream out("connectedcomponents.txt"); // redireciona o cout para um arquivo
  streambuf *coutbuf = std::cout.rdbuf();
  cout.rdbuf(out.rdbuf());

	cout << "Componentes em ordem decrescente: " << "\n" << endl;

	for(int x=0; x < components.size(); x++){
		for (int i=0; i < components[x].size(); i++){
		cout << components[x][i] << " ";
		}
		cout << "\n" << endl;
	}
  cout.rdbuf(coutbuf); // volta o cout para o output em linha de comando
  return componentsize.size();
}
unsigned vertice=0;
unsigned AdjacencyList::getHeight (unsigned root){
  queue <unsigned> bdsQueue;
  unsigned vertex;
  unsigned level=0;

  for (unsigned x=1; x <= V; x++){
    (*this).getVertex(x)->setMarkingStatus(false);
	}


  (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  level++;
  bdsQueue.push(root); //colocando o vertice na fila
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção

  vector <unsigned>* neighbours;

  while (!bdsQueue.empty()){
    vertex = bdsQueue.front();
    bdsQueue.pop(); //remove vertex da fila
    neighbours = (*this).getVertex(vertex)->getNeighbours();
    for (unsigned nb=0; nb < neighbours->size(); nb++){
      if (!(*this).getVertex(neighbours->at(nb))->getMarkingStatus()){
        (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
        (*this).getVertex(neighbours->at(nb))->setLevel(level);
        bdsQueue.push(neighbours->at(nb));
        (*this).getVertex(neighbours->at(nb))->setFather(vertex);
        vertice = neighbours->at(nb);
      }
    }
	  level++;
  }
  unsigned height = 0;
  unsigned vertex1 = vertice;
  while (vertex1 != root){
    vertex1 = (*this).getVertex(vertex1)->getFather();
    height++;
  }
  return height;
}
unsigned AdjacencyList::getDiameter (){
  unsigned vertice = 0;
  unsigned x = 1; // 1a opção: fazer uma bfs a partir de um vertice qq (1, nesse caso) e depois outra bfs a partir
  x=getHeight(1, mNumberOfVertices);// do último vertice marcado na primeira bfs - tirar a distancia da segunda bfs = diametro
  unsigned diameter = getHeight(vertice,V);
  return diameter;
}
*/

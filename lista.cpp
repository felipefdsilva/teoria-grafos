/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <iostream> //remover junto com sobrecarga de '<<'
#include <queue>
#include <stack>
#include "lista.h"
#include <iostream>
#include <fstream>

using namespace std;

//Apenas para teste - Imprime um grafo arranjado como Lista de adjacências
ostream & operator<<(ostream& output, AdjacencyList& graph){
  vector <unsigned>* neighbours;
  /*Imprime Lista de Adjacências*/
  for (unsigned i=1; i <= graph.getNumberOfVertices(); ++i){
    output << i << "-->";
    neighbours = graph.getVertex(i)->getNeighbours();
    for (unsigned j=0; j < (*neighbours).size(); ++j){
      output << neighbours->at(j) << ", ";
    }
    output << endl;
  }
  return output;
}
/*Construtor da Classe Graph*/
AdjacencyList::AdjacencyList (unsigned numberOfVertices): mVertices(numberOfVertices+1){
  mNumberOfVertices = numberOfVertices;
}
AdjacencyList::~AdjacencyList (){
  cout << "AdjacencyList detroyed" << endl;
}
/*Método da classe Graph para acessar um vértice fora do escopo da classe*/
AdjacencyListVertex* AdjacencyList::getVertex(unsigned vertex) {
  return &mVertices.at(vertex);
}
/*Método para obter o número de arestas do grafo*/
unsigned AdjacencyList::getNumberOfEdges (){
  unsigned numberOfEdges = 0;

  for (unsigned i=1; i <= mNumberOfVertices; i++){
    numberOfEdges += (*this).getVertex(i)->getDegree();
  }
  numberOfEdges = numberOfEdges/2;
  return numberOfEdges;
}
/*Método para obter o numero de vértices do grafo*/
unsigned AdjacencyList::getNumberOfVertices () const{
  return mNumberOfVertices;
}
/*Método que implementa a busca em largura*/
void AdjacencyList::breadthFirstSearch (unsigned root, vector<unsigned>* connectedComponent){
  //cout << "Called bfs!!" << endl;
  queue <unsigned> bdsQueue;
  unsigned vertex;
  unsigned level=0;

  for (unsigned v=1; v <= mNumberOfVertices; v++){
    (*this).getVertex(v)->setMarkingStatus(false);
  }

  (*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
  (*this).getVertex(root)->setComponentStatus(true); //indicando q esse vertice ja foi marcado
  connectedComponent->push_back(root);
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
        //cout << "The discovered nb is: " << neighbours->at(nb) << endl;
        (*this).getVertex(neighbours->at(nb))->setMarkingStatus(true);
        (*this).getVertex(neighbours->at(nb))->setComponentStatus(true);
        connectedComponent->push_back(nb);
        (*this).getVertex(neighbours->at(nb))->setLevel(level);
        bdsQueue.push(neighbours->at(nb));
        (*this).getVertex(neighbours->at(nb))->setFather(vertex);
      }
    }
    level++;
    //cout << "Connected Component increased to: " << connectedComponent->size() << endl;
  }
  //cout << "connectedComponent->size()" << connectedComponent->size() << endl;
}
/*Método que implementa a busca em profundidade*/
void AdjacencyList::depthFirstSearch (unsigned root){
  stack <unsigned> dfsStack;
  unsigned vertex, father;
  unsigned level=0;

  for (unsigned v=1; v <= mNumberOfVertices; v++){
    (*this).getVertex(v)->setMarkingStatus(false);
  }
  (*this).getVertex(root)->setLevel(level); //nivel da raiz é 0
  dfsStack.push(root); //colocando o vertice na pilha
  (*this).getVertex(root)->setFather(root); //o pai do vertice raiz é ele mesmo, por convenção
  father = root;
  vector <unsigned>* neighbours;

  while (!dfsStack.empty()){
    vertex = dfsStack.top();
    dfsStack.pop(); //remove vertex da fila
    if (!((*this).getVertex(vertex)->getMarkingStatus())) {
      (*this).getVertex(vertex)->setFather(father);
      (*this).getVertex(vertex)->setLevel((*this).getVertex(father)->getLevel()+1); //nivel da raiz é 0
      (*this).getVertex(vertex)->setMarkingStatus(true); //marcando o vertice como explorado

      neighbours = (*this).getVertex(vertex)->getNeighbours();

      for (unsigned nb=0; nb < neighbours->size(); nb++){
          dfsStack.push(neighbours->at(nb));
        }
      father = vertex;
    }
  }
}

	unsigned AdjacencyList::connectedComponents (unsigned V){
	  stack <unsigned> dfsStack;
	  unsigned vertex;
	  vector <unsigned> componentsize; // vetor de tamanho de componentes, com mesmo indice de components
	  vector <vector<int> > components; //vetor de vetores de componentes

	
	  
	  for (unsigned x=1; x <= V; x++){
	  (*this).getVertex(x)->setMarkingStatus(false);
	  }
		vector <int> component;
		for (unsigned x=1; x <= V; x++){
		if (!((*this).getVertex(x)->getMarkingStatus())){
			unsigned numComponent=1;
			unsigned root = x;
			component.clear(); // zera o vetor componente atual
			component.push_back(root); // adiciona a raiz da componente atual ao seu vetor
			(*this).getVertex(root)->setMarkingStatus(true); //marcando o vertice como descoberto
			  dfsStack.push(root); //colocando o vertice na pilha
			
// 			  if (mDensity > 0.6){ //caso em que é melhor representar por matriz de adjacencia
			  /*  cout << "MATRIZ!!" << endl;
				vector <char>* neighbours;

				while (!dfsStack.empty()){
				  vertex = dfsStack.top();
				  dfsStack.pop(); //remove vertex da fila
				  neighbours = (*this).getVertex(vertex)->getAdjMatrixLine();
				  for (unsigned nb=0; nb < neighbours->size(); nb++){
					if (neighbours->at(nb)){
					  if (!(*this).getVertex(nb)->getMarkingStatus()){
						(*this).getVertex(nb)->setMarkingStatus(true);
						(*this).getVertex(nb)->setLevel(level);
						dfsStack.push(nb);
						(*this).getVertex(nb)->setFather(vertex);
					  }
					}
				  }
				  level++;
				}*/
// 			  }
// 			  else { //caso em que é nelhor representar por lista de adjacencia
				vector <unsigned>* neighbours;

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
// 			  }	
		}
		
		
		}
		
// 		for (unsigned i=0; i<componentsize.size(); i++){ // caso queira saber o tamanho de cada componente
// 		cout << "Tamanho da componente " << i+1 << ": "<< componentsize[i] << endl;
// 		} 
		
		cout << "\n \n" << "Número de componentes conexas: " << componentsize.size() << endl;
		
		cout << "Tamanho da maior componente: " << *max_element(componentsize.begin(), componentsize.end()) << endl;
		cout << "Tamanho da menor componente: " << *min_element(componentsize.begin(), componentsize.end()) << endl;

	

		sort(components.begin(), components.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
  return a.size() > b.size();
});


	ofstream out("connectedcomponents.txt"); // redireciona o cout para um arquivo
    streambuf *coutbuf = std::cout.rdbuf(); 
    cout.rdbuf(out.rdbuf());
    
		cout << "Componentes em ordem decrescente: " << "\n" << endl;	
		
		for(int x=0; x < components.size(); x++){
			for (int i=0; i < components[x].size(); i++){
			cout << components[x][i] << " ";
			};
			cout << "\n" << endl;
		}
		
	    cout.rdbuf(coutbuf); // volta o cout para o output em linha de comando
	    return componentsize.size();
	}
	
	unsigned vertice=0;
unsigned AdjacencyList::getHeight (unsigned root, unsigned V){
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

//   if (mDensity > 0.6){ //caso em que é melhor representar por matriz de adjacencia
  /*  cout << "MATRIZ!!" << endl;
    vector <char>* neighbours;

    while (!bdsQueue.empty()){
      vertex = bdsQueue.front();
      bdsQueue.pop(); //remove vertex da fila
      neighbours = (*this).getVertex(vertex)->getAdjMatrixLine();
      for (unsigned nb=0; nb < neighbours->size(); nb++){
        if (neighbours->at(nb)){
          if (!(*this).getVertex(nb)->getMarkingStatus()){
            (*this).getVertex(nb)->setMarkingStatus(true);
            (*this).getVertex(nb)->setLevel(level);
            bdsQueue.push(nb);
            (*this).getVertex(nb)->setFather(vertex);
          }
        }
      }
      level++;
    }*/
//   }
//   else { //caso em que é nelhor representar por lista de adjacencia
    // cout << "LISTA!!" << endl;
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
        // }
      }
      
    }
	level++;
  } 
//   cout << vertice << endl;   
//   cout << (*this).getVertex(vertice)->getLevel() << endl;

      unsigned height = 0;
      unsigned vertex1 = vertice;
      while (vertex1 != root){
        vertex1 = (*this).getVertex(vertex1)->getFather();
        height++;
      }
      
  return height;
}

	
unsigned AdjacencyList::getDiameter (unsigned V){
	unsigned x = 1; // 1a opção: fazer uma bfs a partir de um vertice qq (1, nesse caso) e depois outra bfs a partir 
   x=getHeight(1,V);// do último vertice marcado na primeira bfs - tirar a distancia da segunda bfs = diametro
   unsigned diameter = getHeight(vertice,V);
   

return diameter;

// 	unsigned x = 1; //2a opcao: rodar uma bfs pra cada vertice do grafo, usando cada um como raiz de cada vez
//    for (int i=0; i<=V;i++){
//    		if (getHeight(i,V)>x){
//    			x=getHeight(i,V);}
//    			}
//    	return x;
}



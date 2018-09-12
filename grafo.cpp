/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <iostream> //para função print
#include <queue> //para a fila da bfs
#include "grafo.h" //declaração da classe grafo

using namespace std;

Graph::Graph (unsigned numberOfVertices){
  mNumberOfVertices = numberOfVertices;
}
Graph::~Graph(){
}
/*Método que configura o número de arestas do grafo*/
void Graph::setNumberOfEdges (unsigned numberOfEdges){
  mNumberOfEdges = numberOfEdges;
}
/*Método que retorna o número de vertices do grafo*/
unsigned Graph::getNumberOfVertices () const{
  return mNumberOfVertices;
}
/*Método que retorna o numero de arestas do grafo*/
unsigned Graph::getNumberOfEdges () const{
  return mNumberOfEdges;
}
/*Método que implementa a busca em largura*/
void Graph::breadthFirstSearch (unsigned root){//, vector<unsigned> *Vertices, SpanningTree *tree
  queue <unsigned> bdsQueue; //fila da busca em largura
  vector <unsigned> neighbours; //vetor de vizinhos de um vertice
  vector <bool> discovered (mNumberOfVertices+1, false); //vetor de marcação (descoberto ou não descoberto)
  unsigned numberOfNeighbours; //grau do vertice
  unsigned neighbour; //um vizinho do vertice
  unsigned vertex; //vertice retirado da fila
  unsigned parentLevel=1;
  unsigned level; //nivel na arvore geradora

  discovered.at(root) = true; //marcando a raiz como descoberta
  //discoveryCount++; //incrementa o contador de vertices descobertos
  bdsQueue.push(root); //colocando a raiz na fila
  //Vertices.at(discoveryCount) = root; //colocando o vertice raiz na primeira posição após descobertos
  //tree.setBegin(&Vertices.at(discoveryCount));
  //Vertices.at(root) = discoveryCount; //colocando o vertice na primeira posição de não descobertos na antiga posição de raiz

  while (!bdsQueue.empty()){
    vertex = bdsQueue.front();
    bdsQueue.pop(); //remove o vertice da fila
    getNeighbours(vertex, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours = neighbours.size(); //salvando o grau do vertice

    for (unsigned nb=0; nb < numberOfNeighbours; nb++){ //para cada vizinho de vertex
      neighbour = neighbours.at(nb);
      if (!(discovered.at(neighbour))) { //se o vizinho não estiver marcado
        discovered.at(neighbour) = true; //marcar o vizinho
        //discoveryCount++; //incrementa o contador de vertices descobertos
        bdsQueue.push(neighbour); //adiciona o vizinho descoberto na fila
        //Vertices.at(discoveryCount) = neighbour; //coloca o vertice descoberto na primeira posição de vertices não descobertos
        //Vertices.at(neighbour) = discoveryCount; //coloca o vertice não descoberto na posição antiga de neighbour
        level = parentLevel+1; //nivel do vertices descoberto é o nivel do pai mais um
      }
    }
    parentLevel = level; //o proximo vertice retirado da fila será, possivelmente, o pai de seus vizinhos
  }
  //tree.setHeigth(parentLevel);
}
/*Método que implementa a busca em profundidade*/
/*
virtual void Graph::depthFirstSearch (unsigned root){
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
*/
/*Imprime o grafo (graficamente é uma lista de adjacencias, mas pode estar na memoria como uma matriz)*/
void Graph::print (){
  unsigned numberOfVertices = this->getNumberOfVertices();
  vector <unsigned> neighbours;
  vector <unsigned>::iterator it;
  vector <unsigned>::iterator end;

  for (unsigned i=1; i <= numberOfVertices; ++i){
    cout << i << "-->";
    this->getNeighbours(i, &neighbours);
    end = neighbours.end();
    for (it = neighbours.begin(); it != end; it++){
        cout << *it << ", ";
    }
    cout << endl;
  }
}

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe grafo
*/

#include <iostream> //para função print
#include <queue> //para a fila da bfs
#include <string>
#include <algorithm> //para min, max
#include "headers/grafo.h" //declaração da classe grafo

using namespace std;

Graph::Graph (){
}
Graph::~Graph(){
}
void Graph::setNumberOfVertices (unsigned numberOfVertices){
  mNumberOfVertices = numberOfVertices;
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
/*Método que configura o peso de uma aresta*/
void Graph::setWeight (unsigned vertex1, unsigned vertex2, float weight){
  pair<unsigned, unsigned> edge(max(vertex1, vertex2), min(vertex1, vertex2));
  mWeight[edge]= weight;
}
/*Método que retorna o peso de uma aresta*/
float Graph::getWeight (unsigned vertex1, unsigned vertex2){
  pair<unsigned, unsigned> edge(max(vertex1, vertex2), min(vertex1, vertex2));
  return mWeight[edge];
}
/*Método que calcula a distância média do grafo*/
float averageDistance(){
  float total_dist = 0;

  for (unsigned i = 0; i < mNumberOfVertices; i++){
    dijkstra(i+1);
    for (unsigned j = 1; j <= mNumberOfVertices; j++) {
      if (mMinDist[j] < INT_MAX){
        total_dist += mMinDist[j];
      }
    }
    return total_dist/mNumberOfEdges;
  }
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
/*Método que implementa o algortimo Dijkstra*/
void Graph::dijkstra (unsigned rootVertex){
  vector <unsigned> neighbours; //vetor de vizinhos de um vertice
  pair<unsigned, unsigned> tempEdge;
  unsigned neighbour;
	mMinDist.clear();
	mParent.clear();

  for(unsigned i = 1; i <= mNumberOfVertices; i++){
    mMinDist.push_back(INT_MAX); //iniciando o vetor de distancias com infinito
    mParent.push_back(-1); //iniciando o vetor de pais com -1
  }
  mMinDist.at(rootVertex) = 0; //distancia mínima para o vertice raiz é conhecida e é zero
  mParent.at(rootVertex) = 0; //o pai do vertice raiz é 0

  myHeap heap (mNumberOfVertices); //cria o heap
  Vertex vertexZero (0, mMinDist[0]); //apenas para ajustar o tamanho do heap
  heap.push(vertexZero); //posição 0 do heap é um vertice que não deve ser usado (não existe no grafo)

  for(unsigned i = 1; i <= mNumberOfVertices; i++){ //inicialização do heap
    Vertex vertex(i, mMinDist[i]);
    heap.push(vertex);
  }
  while (!heap.empty()){
    Vertex minDistVertex = heap.pop();
    unsigned explored = minDistVertex.getIndex();
    getNeighbours(explored, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours = neighbours.size(); //salvando o grau do vertice
    for (unsigned i=1; i <= numberOfNeighbours; i++){
      neighbour = neighbours.at(i);
      tempEdge = make_pair(max(explored, neighbour),

      min(explored, neighbour));
      if (mMinDist[neighbour] > mMinDist[explored] + mWeights[tempEdge]){
        mMinDist[neighbour] = mMinDist[explored] + mWeights[tempEdge];
        heap.update(neighbour, mMinDist[neighbour]);
        mParent[neighbour]=explored;
      }
    }
  }
}
/*Método que implementa o algoritmo de Prim*/
void Graph::prim(unsigned rootVertex){
  float totalWeight = 0;
  vector <unsigned> neighbours; //vetor de vizinhos de um vertice
  pair<unsigned, unsigned> tempEdge;
  unsigned neighbour;
  vector<unsigned> parent(mNumberOfVertices, 0); //vetor de pais para a mst
  vector<bool> markingStatus(mNumberOfVertices, false); //vetor de marcação do vertice (explorado ou não)
  myHeap heap(mNumberOfVertices); //mst

  mMinDist.assign(mNumberOfVertices, INT_MAX); //resetando o vetor de distancias

  mMinDist[rootVertex] = 0; //distancia do vertice raiz é conhecida
  parent[rootVertex] = 0; //o pai da raiz é o vertice 0 por convenção

  Vertex vertexZero (0, mMinDist[0]); //apenas para ajustar o tamanho do heap
  heap.push(vertexZero); //posição 0 do heap é um vertice que não deve ser usado (não existe no grafo)

  for(unsigned i = 1; i <= mNumberOfVertices; i++){ //inicializando o heap
    Vertex vertex(i, mMinDist[i]);
    heap.push(vertex);
  }
  while(!heap.empty()){
    Vertex minDistVertex = heap.pop(); //retira o vertice do topo do heap
    unsigned explored = minDistVertex.getIndex(); //identifica o vertice com menor caminho conhecido
    markingStatus[explored]=true; //marca o vertice como explorado
    getNeighbours(explored, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours = neighbours.size(); //salvando o grau do vertice
    for (unsigned i = 1; i <= numberOfNeighbours; i++) { //para cada vizinho do vertice explorado
      neighbour = neighbours.at(i);
      tempEdge = make_pair(max(explored, neighbour), min(explored, neighbour)); //seleciona a aresta
      if (mMinDist[explored] > mWeights[tempEdge] && marking[neighbour] == 0){
          parent[neighbour] = explored;
          mMinDist[neighbour] = mWeights[tempEdge];
          heap.update(neighbour, mMinDist[neighbour]);
      }
    }
  }
  ofstream myFile;
  myFile.open("mst.txt");
  myFile << mNumberOfVertices << "\n";
  for (unsigned i = 1; i <= parent.size(); i++) {
    if(parent[i] > 0){
      myFile << i << " " << parent[i] << " " << mMinDist[i] << "\n";
      totalWeight += mMinDist[i];
    }
  }
  cout << endl;
  myFile << totalWeight;
  myFile.close();
}
/*Método que calcula a Excentricidade de um vértice*/
float Graph::eccentricity(unsigned rootVertex){
  dijkstra(rootVertex);
  return *max_element(min_dist.begin()+1, min_dist.end());
}
/*Método que encontra o menor caminho entre dois pesquisadores*/
void search(const char* person1, const char* person2){
 ifstream myNetMap;
 myNetMap.open("rede_colaboracao_vertices.txt");
 stringstream iss;
 string line, line2;
 string name[2];
 vector <unsigned> path(2);
 vector<unsigned> spath;
 unsigned currentVertex;
 unsigned i;

 while(getline(myNetMap, line, '\n')){
   iss << line;
   i = 0;
   while(getline(iss, line2, ',')){
     name[i] = line2;
     i++;
   }
   vertexName[stoi(name[0], nullptr, 10)]=name[1];
   iss.clear();
   if (string(name[1]) == string(person1)) {
     path[0]=stoi(name[0], nullptr,10);
   }
   else if (string(name[1]) == string(person2)) {
     path[1]=stoi(name[0], nullptr, 10);
   }
 }
 myNetMap.close();
 dijkstra(path[0]);
 currentVertex = path[1];
 cout << currentVertex << endl;
 while (currentVertex != 0) {
   spath.push_back(currentVertex);
   currentVertex = mParent.at(currentVertex);
 }
 for (unsigned i = spath.size()-1; i >= 1; i--) {
   cout << vertexName[spath[i]] << endl;
 }
}
/*Método que determina os vizinhos de Dijkstra e Ratton*/
void printNeighbours(const char * pName) {
  ifstream myNetMap;
  vector <unsigned> neighbours;
	myNetMap.open("rede_colaboracao_vertices.txt");
	stringstream iss;
	string line;
	string line2;
	string name[2];
	unsigned path;
	bool empty = vertexName.empty();
  unsigned i;

	while(getline(myNetMap, line, '\n')) { //lê as linhas do arquivo de mapeamento
	 	iss << line;
	 	i = 0;
	 	while(getline(iss, line2, ',')){ //lê cada string separada por virgula ex:"5,nome-do-pesquisador"
	 		name[i] = line2;
	 		i++;
	 	}
	 	if (string(name[1]) == string(pName)) { //se o nome do pesquisar é o desejado
 			path = stoi(name[0], nullptr, 10); //salvar o indice correspondente ao vertice do grafo
 		}
 		if (empty) {
	 		vertexName[stoi(name[0], nullptr, 10)] = name[1];
	 	}
	 	iss.clear();
	}
	myNetMap.close();

  getNeighbours(path, &neighbours); //encontrando os vizinhos do vertice
  numberOfNeighbours = neighbours.size(); //salva o grau do vertice

	for (unsigned i=0; i < numberOfNeighbours; i++) {
		cout << neighbours.at(i) << endl; //imprime os vizinhos do pesquisador no grafo
	}




}
/*Método que determina os três vértices de maior grau (pessoas e os graus)*/
void greatestDegrees() {
	unsigned first=0, second=0, third=0;
	bool empty=vertex_name.empty();
  vector<unsigned> neighbours;
  unsigned numberOfNeighbours1, numberOfNeighbours2;
  unsigned i;

 	if (empty) {
 		ifstream myNetMap;
		myNetMap.open("rede_colaboracao_vertices.txt");
		string line;
		string line2;
		stringstream iss;
		string name[2];
		while(getline(myNetMap,line,'\n')) {
		 	iss << line;
		 	i = 0;
		 	while(getline(iss,line2,',')){
		 		name[i] = line2;
		 		i++;
		 	}
		 	vertex_name[stoi(name[0], nullptr, 10)] = name[1];
		 	iss.clear();
		}
		myNetMap.close();
	}
	for (unsigned i=1; i <= mNumberOfVertices; i++) {
    getNeighbours(i, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours1 = neighbours.size(); //salvando o grau do vertice
    getNeighbours(first, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours2 = neighbours.size(); //salvando o grau do vertice
    getNeighbours(second, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours3 = neighbours.size(); //salvando o grau do vertice
    getNeighbours(third, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours4 = neighbours.size(); //salvando o grau do vertice

		if (numberOfNeighbours1 > numberOfNeighbours2) {
			third=second;
			second=first;
			first=i;
		}
		else if (numberOfNeighbours1 > numberOfNeighbours3) {
			third=second;
			second=i;
		}
		else if (numberOfNeighbours1 > numberOfNeighbours4) {
			third=i;
		}
	}
	cout << vertex_name[first] << " " << container.getDegree(first) << endl;
	cout << vertex_name[second] << " " << container.getDegree(second) << endl;
	cout << vertex_name[third] << " " << container.getDegree(third) << endl;
}
/*Método que imprime o grafo (deve ser usado apenas em grafos muito pequenos)*/
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

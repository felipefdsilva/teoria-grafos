/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe grafo
*/

#include <iostream> //para função print
#include <queue> //para a fila da bfs
#include <string> //para o tipo string
#include <algorithm> //para min, max
#include <fstream> //para leitura de arquivo
#include <sstream> //para manipular strings
#include "grafo.h" //declaração da classe grafo
#include "my-heap.h" //para o objeto MyHeap

using namespace std;

/*Construtor*/
Graph::Graph (){
}
/*Destrutor*/
Graph::~Graph(){
}
/*Método que configura o numero de vertices do grafo*/
void Graph::setNumberOfVertices (unsigned numberOfVertices){
  mNumberOfVertices = numberOfVertices;
}
/*Método que configura o número de arestas do grafo*/
void Graph::setNumberOfEdges (unsigned numberOfEdges){
  mNumberOfEdges = numberOfEdges;
}
/*Método para redimensionar o tamanho do vetor de graus*/
void Graph::resizeDegreeVector (unsigned size){
  mDegree.resize(size);
}
/*Método que incrementa o grau de um vertice*/
void Graph::incrementDegree (unsigned vertex) {
  mDegree.at(vertex) = mDegree.at(vertex)+1;
}
/*Método que retorna o grau de um vertice*/
unsigned Graph::getDegree (unsigned vertex){
  return mDegree.at(vertex);
}
/*Método que retorna o número de vertices do grafo*/
unsigned Graph::getNumberOfVertices () const{
  return mNumberOfVertices;
}
/*Método que retorna o numero de arestas do grafo*/
unsigned Graph::getNumberOfEdges () const{
  return mNumberOfEdges;
}
/*Método que configura a flag de grafo com peso*/
void Graph::setWeightedGraphStatus (bool status){
  mWeightedGraph = status;
}
/*metodo que retorna o valor da flag de grafo com peso*/
bool Graph::weighted (){
  return mWeightedGraph;
}
/*Método que configura o peso de uma aresta*/
void Graph::setWeight (unsigned vertex1, unsigned vertex2, float weight){
  pair<unsigned, unsigned> edge(max(vertex1, vertex2), min(vertex1, vertex2));
  mWeights[edge] = weight;
}
/*Método que retorna o peso de uma aresta*/
float Graph::getWeight (unsigned vertex1, unsigned vertex2){
  pair<unsigned, unsigned> edge(max(vertex1, vertex2), min(vertex1, vertex2));
  return mWeights[edge];
}
/*Método que calcula a distância média da componente conexa de um grafo*/
float Graph::averageDistance(){
  float total_dist = 0;
  float pairsCount = mNumberOfVertices*(mNumberOfVertices-1)/2; //numero máximo de pares de vertice (caso do grafo conexo)
  for (unsigned i = 1; i <= mNumberOfVertices; i++){ //para cada vertice, roda-se dijkstra
    dijkstra(i);
    for (unsigned j = 1; j <= mNumberOfVertices; j++) { //para cada vertice, checa-se a distancia dada por dijkstra
      if (mMinDist[j] < INT_MAX){ //se a distancia não for infinita
        total_dist += mMinDist[j]; //soma a distancia
      }
      else { //neste caso, grafo não é conexo
        pairsCount--; //reduz-se o numero total de pares de vertices possíveis
      }
    }
    return total_dist/pairsCount;
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
  bdsQueue.push(root); //colocando a raiz na fila

  while (!bdsQueue.empty()){
    vertex = bdsQueue.front();
    bdsQueue.pop(); //remove o vertice da fila
    getNeighbours(vertex, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours = neighbours.size(); //salvando o grau do vertice

    for (unsigned nb=0; nb < numberOfNeighbours; nb++){ //para cada vizinho de vertex
      neighbour = neighbours.at(nb);
      if (!(discovered.at(neighbour))) { //se o vizinho não estiver marcado
        discovered.at(neighbour) = true; //marcar o vizinho
        bdsQueue.push(neighbour); //adiciona o vizinho descoberto na fila
        level = parentLevel+1; //nivel do vertices descoberto é o nivel do pai mais um
      }
    }
    parentLevel = level; //o proximo vertice retirado da fila será, possivelmente, o pai de seus vizinhos
  }
}
/*Método que implementa o algortimo Dijkstra*/
float Graph::dijkstra(unsigned rootVertex){
  vector <unsigned> neighbours; //vetor de vizinhos de um vertice
  pair<unsigned, unsigned> tempEdge;
  unsigned numberOfNeighbours;
  unsigned neighbour;
  Vertex vertex, minDistVertex;
  MyHeap heap (mNumberOfVertices);

  mMinDist.assign(mNumberOfVertices+1, INT_MAX); //inicia o vetor de distancias com infinito
  mParent.assign(mNumberOfVertices+1, 0);  //inicia o vetor de pais com 0

  mMinDist.at(rootVertex) = 0; //distancia mínima para o vertice raiz é conhecida e é zero
  mParent.at(rootVertex) = rootVertex; //o pai do vertice raiz é ele mesmo

  for(unsigned i = 1; i < mNumberOfVertices; i++){ //inicialização do heap
    vertex.setIndex(i);
    vertex.setDistance(mMinDist[i]);
    heap.push(vertex);
  }
  while (!heap.empty()){
    minDistVertex = heap.pop(); //retira do heap o vertice com menor distancia conhecida
    unsigned explored = minDistVertex.getIndex(); //identifica o vertice retirado
    getNeighbours(explored, &neighbours); //encontra os vizinhos do vertice
    numberOfNeighbours = neighbours.size(); //salvando o grau do vertice
    for (unsigned i=0; i < numberOfNeighbours; i++){ //para cada vizinho
      neighbour = neighbours.at(i); //seleciona um vizinho
      tempEdge = make_pair(max(explored, neighbour), min(explored, neighbour)); //define a aresta, para encontrar o peso
      if (mMinDist[neighbour] > mMinDist[explored] + mWeights[tempEdge]){//se a distancia anterior for maior que a nova
        mMinDist[neighbour] = mMinDist[explored] + mWeights[tempEdge]; //atualiza o vetor de distancias com a distancia menor
        heap.update(neighbour, mMinDist[neighbour]); //atualiza o heap com a nova distancia
        mParent[neighbour]=explored; //define o vertice explorado como o pai do vizinho que teve a distancia atualizada
      }
    }
  }
}
/*Método que implementa o algoritmo de Prim*/
void Graph::prim(unsigned rootVertex){
  float totalWeight = 0;
  pair<unsigned, unsigned> tempEdge;
  unsigned neighbour;
  unsigned numberOfNeighbours;
  vector <unsigned> neighbours; //vetor de vizinhos de um vertice
  vector<unsigned> parent(mNumberOfVertices, 0); //vetor de pais para a mst
  vector<bool> markingStatus(mNumberOfVertices, false); //vetor de marcação do vertice (explorado ou não)
  MyHeap heap(mNumberOfVertices); //arvore geradora minima
  ofstream myFile;
  Vertex vertex, minDistVertex;

  mMinDist.assign(mNumberOfVertices, INT_MAX); //resetando o vetor de distancias

  mMinDist[rootVertex] = 0; //distancia do vertice raiz é conhecida
  parent[rootVertex] = 0; //o pai da raiz é o vertice 0 por convenção

  Vertex vertexZero (0, mMinDist[0]); //apenas para ajustar o tamanho do heap
  heap.push(vertexZero); //posição 0 do heap é um vertice que não deve ser usado (não existe no grafo)

  for(unsigned i = 1; i <= mNumberOfVertices; i++){ //inicializando o heap
    vertex.setIndex(i);
    vertex.setDistance(mMinDist[i]);
    heap.push(vertex);
  }
  while(!heap.empty()){
    minDistVertex = heap.pop(); //retira o vertice do topo do heap
    unsigned explored = minDistVertex.getIndex(); //identifica o vertice com menor caminho conhecido
    markingStatus[explored]=true; //marca o vertice como explorado
    getNeighbours(explored, &neighbours); //encontrando os vizinhos do vertice
    numberOfNeighbours = neighbours.size(); //salvando o grau do vertice
    for (unsigned i = 0; i < numberOfNeighbours; i++) { //para cada vizinho do vertice explorado
      neighbour = neighbours.at(i);//seleciona um vizinho
      tempEdge = make_pair(max(explored, neighbour), min(explored, neighbour)); //define a aresta
      if (mMinDist[explored] > mWeights[tempEdge] && markingStatus[neighbour] == false){
          parent[neighbour] = explored;
          mMinDist[neighbour] = mWeights[tempEdge];
          heap.update(neighbour, mMinDist[neighbour]);
      }
    }
  }
  myFile.open("resultados - parte 2/mst.txt");
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
/*Método que calcula a Excentricidade de um vertice*/
float Graph::eccentricity(unsigned root){
  float eccentricity;
  dijkstra(root);
  //for (unsigned i=1; i < mMinDist.size(); i++){
  //  cout << "mMinDist[" << i << "]: " << mMinDist.at(i) << endl;
  //}
  return eccentricity = *max_element(mMinDist.begin()+1, mMinDist.end());
}
/*Método que encontra o menor caminho entre dois pesquisadores*/
void Graph::minPathBetweenResearchers(const char* person1, const char* person2){
 ifstream myNetMap;
 myNetMap.open("grafos/rede_colaboracao_vertices.txt"); //abre o arquivo de mapeamento
 stringstream iss;
 string line, line2;
 string name[2];
 vector <unsigned> path(2,0);
 vector<unsigned> spath;
 unsigned currentVertex;

 while(getline(myNetMap, line, '\n')){//laço para varrer o arquivo e encontrar o vertice correspondente as pessoas
   iss << line;
   for (unsigned i=0; getline(iss, line2, ','); i++){ //lê uma das duas strings em uma linha ex: "4, alfredo das couves"
     name[i] = line2;
   }
   vertexName[stoi(name[0], nullptr, 10)]=name[1]; //salva a informação da linha do arquivo em um map
   iss.clear();
   if (string(name[1]) == string(person1)) { //se encontrou o primeiro pesquisador
     path[0]=stoi(name[0], nullptr,10); //salva o indice do vertice correspondente
   }
   else if (string(name[1]) == string(person2)) { //se encontrou o segundo pesquisador
     path[1]=stoi(name[0], nullptr, 10); //salva o indice do vertice correspondente
   }
 }
 if (!(path[0] && path[1])){
   cout << "Researcher not found" << endl;
   exit(1);
 }
 myNetMap.close(); //fecha o arquivo de mapeamento
 dijkstra(path[0]); //roda dijkstra para encontrar o caminho da pessoa 1 para a pessoa 2
 currentVertex = path[1]; //imprime o caminho a partir da pessoa 2, olhando o pai de cada vertice do caminho
 cout << currentVertex << endl;
 while (currentVertex != mParent.at(currentVertex)) { //a condição de parada é o vertice ser pai dele mesmo (raiz)
   spath.push_back(currentVertex); //salva o caminho
   currentVertex = mParent.at(currentVertex); //passa para o pai
 }
 for (unsigned i = spath.size()-1; i > 0; i--) { //imprime o caminho
   cout << vertexName[spath[i]] << endl;
 }
}
/*Método que determina os vizinhos de Dijkstra e Ratton*/
void Graph::printNeighbours(const char * pName) {
  ifstream myNetMap;
  vector <unsigned> neighbours;
	myNetMap.open("rede_colaboracao_vertices.txt");
	stringstream iss;
	string line;
	string line2;
	string name[2];
	unsigned path;
  unsigned numberOfNeighbours;
	bool empty = vertexName.empty();

	while(getline(myNetMap, line, '\n')) { //lê as linhas do arquivo de mapeamento
	 	iss << line;
	 	for (unsigned i=0; getline(iss, line2, ','); i++){ //lê cada string separada por virgula ex:"5,nome-do-pesquisador"
	 		name[i] = line2;
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
void Graph::greatestDegrees() {
	unsigned newDegree, first=1, second=1, third=1;
	bool empty=vertexName.empty();
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
		 	vertexName[stoi(name[0], nullptr, 10)] = name[1];
		 	iss.clear();
		}
		myNetMap.close();
	}
	for (unsigned i=2; i <= mNumberOfVertices; i++) {
    newDegree = getDegree(i); //salvando o grau do i-ésimo vertice

		if (newDegree > getDegree(first)) {
			third=second;
			second=first;
			first=i;
		}
		else if (newDegree > getDegree(second)) {
			third=second;
			second=i;
		}
		else if (newDegree > getDegree(third)) {
			third=i;
		}
	}
	cout << vertexName[first] << " " << getDegree(first) << endl;
	cout << vertexName[second] << " " << getDegree(second) << endl;
	cout << vertexName[third] << " " << getDegree(third) << endl;
}
/*Função que escolhe o algotimo de busca e determina distancia e caminho minimos*/
void Graph::search(unsigned root, unsigned leaf){
  vector<int> path;
  unsigned currentVertex;

 if(weighted()){
   dijkstra(root);
 } else{
   breadthFirstSearch(root);
 }
 if(leaf){
   if(mMinDist[leaf] == INT_MAX){
     cout << "Nao ha caminho entre os vertices "<< root << " e " << leaf << "."<< endl;
   } else {
     cout << "Distancia entre os vertices " << root << " e " << leaf << ": " << mMinDist[leaf] << endl;
     cout << "Caminho entre os vertices " << root << " e " << leaf << ": ";

     currentVertex=leaf;
     while (currentVertex != mParent.at(currentVertex)) {
       path.push_back(currentVertex);
       currentVertex = mParent[currentVertex];
     }
     path.push_back(currentVertex);
     for (unsigned i = path.size()-1; i > 0; i--) {
       cout << path[i] << ", ";
     }
     cout << path.at(0) << endl;
   }
 }
 cout << endl;
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

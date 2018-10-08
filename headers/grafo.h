/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Declaração da classe grafo
*/

#ifndef GRAFO_H
#define GRAFO_H "grafo.h"

#include <map>
#include <vector>

using namespace std;

class Graph {
  public:
    Graph ();//Construtor
    ~Graph();//Destrutor
    /*Métodos de encapsulamento*/
    virtual void setNeighbours (unsigned, unsigned) = 0;//configura os vizinhos de acordo com a representação
    void setNumberOfVertices (unsigned); //configura o numero de vertices do grafo
    void setNumberOfEdges (unsigned); //configura o numero de arestas
    unsigned getNumberOfVertices () const; //retorna o número de vertices
    unsigned getNumberOfEdges () const; //retorna o número de arestas
    virtual void getNeighbours (unsigned, vector<unsigned> *) = 0;//obtém os vizinhos do vertice de acordo com a representação
    void setWeight(unsigned, unsigned, float); //insere o peso de uma aresta no vetor de pesos
    float getWeight (unsigned, unsigned); //returna o peso de uma aresta do grafo
    float averageDistance(); //calcula a distancia média do grafo
    /*Métodos de busca no grafo*/
    virtual void breadthFirstSearch (unsigned); //realiza a busca em largura
    //virtual void depthFirstSearch (unsigned); //realiza a busca em profundidade
    float dijkstra (unsigned); //determina caminhos mínimos em grafos com pesos
    void prim(unsigned); //determina uma mst de um grafo com pesos
    void minPathBetweenResearchers(const char*, const char*); //determina o menor caminho entre pesquisadores
    void printNeighbours(const char *); //imprime os vizinhos de um pesquisador no grafo
    void greatestDegrees(); //obtem os maiores três graus de um grafo
    /*Método para testes*/
    virtual void print ();//imprime o grafo
  private:
    unsigned mNumberOfVertices; //número de vértices do grafo
    unsigned mNumberOfEdges; //número de arestas do grafo
    map <pair<unsigned ,unsigned>, float> mWeights; //map com os pesos das arestas do grafo
    vector <float> mMinDist; //usado por djkistra para determinar a distancia minima
    vector <unsigned> mParent; //usado por djkistra para determinar a arvore geradora
    map <int, string>  vertexName;
};

#endif

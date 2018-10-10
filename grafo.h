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
    void setNumberOfEdges (unsigned); //configura o numero de aresta
    void resizeDegreeVector(unsigned); //redimensiona o tamanho do vetor de graus dos vertices
    void incrementDegree (unsigned); //incrementa o grau do vertice
    unsigned getNumberOfVertices () const; //retorna o número de vertices
    unsigned getNumberOfEdges () const; //retorna o número de arestas
    virtual void getNeighbours (unsigned, vector<unsigned> *) = 0;//obtém os vizinhos do vertice de acordo com a representação
    unsigned getDegree (unsigned);//retorna o grau de vertice
    void setWeightedGraphStatus (bool); //configura a flag que indica se o grafo possui pesos ou não
    bool weighted (); //indica se é um grafo com pesos ou não
    void setWeight(unsigned, unsigned, float); //insere o peso de uma aresta no vetor de pesos
    float getWeight (unsigned, unsigned); //returna o peso de uma aresta do grafo
    float averageDistance(); //calcula a distancia média do grafo
    /*Métodos de busca no grafo*/
    virtual void breadthFirstSearch (unsigned); //realiza a busca em largura
    //virtual void depthFirstSearch (unsigned); //realiza a busca em profundidade
    virtual float dijkstra (unsigned); //determina caminhos mínimos em grafos com pesos
    virtual float prim(unsigned); //determina uma mst de um grafo com pesos
    float eccentricity(unsigned); //determina a excentricidade de um vertice
    void minPathBetweenResearchers(const char*, const char*); //determina o menor caminho entre pesquisadores
    virtual void printNeighbours(const char *); //imprime os vizinhos de um pesquisador no grafo
    void greatestDegrees(); //obtem os maiores três graus de um grafo
    void search(unsigned, unsigned=0);
    /*Método para testes*/
    virtual void print ();//imprime o grafo
  protected:
    vector <float> mMinDist; //usado por djkistra para determinar a distancia minima
    vector <unsigned> mParent; //usado para determinar a arvore geradora
  private:
    unsigned mNumberOfVertices; //número de vértices do grafo
    unsigned mNumberOfEdges; //número de arestas do grafo
    map <pair<unsigned ,unsigned>, float> mWeights; //map com os pesos das arestas do grafo
    map <int, string>  mVertexName;
    vector <unsigned> mDegree; //vetor com os graus do vertices
    bool mWeightedGraph;
};

#endif

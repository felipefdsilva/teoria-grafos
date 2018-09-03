/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef METRICAS
#define METRICAS "metricas.h"

using namespace std;

class GraphMetrics {
  public:
    friend ostream & operator<<(ostream& output, GraphMetrics& graph);

    GraphMetrics(AdjacencyList*);
    GraphMetrics(AdjacencyMatrix*);
    unsigned getMinDegree (); //obter grau minimo
    unsigned getMaxDegree (); // obter grau maximo
    float getAvgDegree (); //obter grau medio
    unsigned getMedianDegree (); //obter grau mediano
    void findGraphConnectedComponents ();
  private:
    vector<int> mDegrees;
    float mSumOfDegrees;
    AdjacencyList *mListGraph;
    AdjacencyMatrix *mMatrixGraph;
};

#endif
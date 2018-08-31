/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#ifndef METRICAS_GRAFO
#define METRICAS_GRAFO "metricas-grafo.h"

using namespace std;

class GraphMetrics {
  public:
    GraphMetrics(Graph&);
    unsigned getMinDegree (); //obter grau minimo
    unsigned getMaxDegree (); // obter grau maximo
    float getAvgDegree (); //obter grau medio
    unsigned getMedianDegree (); //obter grau mediano
  private:
    vector<int> mDegrees;
    float mSumOfDegrees;
};

#endif

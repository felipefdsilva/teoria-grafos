/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 1
* Felipe Ferreira e Luis Fernando
*/

#include <algorithm>
#include "vertice-lista.h"

/*Construtor*/
AdjacencyListVertex::AdjacencyListVertex (){}
/*estabele um novo vizinho para o objeto vertice*/
void AdjacencyListVertex::setNeighbour (unsigned neighbour){
  mNeighbours.push_back(neighbour); //na lista de adjacencia
}
/*metodo para acessar os vizinhos de um vertice*/
vector <unsigned>* AdjacencyListVertex::getNeighbours (){
  if (mNeighbours.size() > 0)
    sort(&mNeighbours.at(0), &mNeighbours.at(mNeighbours.size()-1)); //ordena por otimização
  return &mNeighbours;
}
/*metodo para obter o grau do vertice*/
unsigned AdjacencyListVertex::getDegree () const{
  return mNeighbours.size();
}

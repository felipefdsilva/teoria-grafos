/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe vertice
*/

#include "vertice.h"

/*Função amiga para imprimir o vertice*/
ostream& operator<<(ostream & s, const Vertex & z) {
	s << z.getIndex();
	return s;
}
/*Construtor da classe vertex*/
Vertex::Vertex (){
}
/*Contrutor da classe Vertex*/
Vertex::Vertex (int i, float d) {
	mIndex=i;
	mDistance=d;
}
/*Método para configurar o indice do vertice*/
void Vertex::setIndex (unsigned index){
	mIndex = index;
}
/*Método para obter o indice do vertice*/
unsigned Vertex::getIndex () const{
	return mIndex;
}
/*Método para configurar a distancia para o vertice*/
void Vertex::setDistance (float distance){
	mDistance = distance;
}
/*Método para obter a distancia para o vertice*/
float Vertex::getDistance () const{
	return mDistance;
}
/*Sobrecarga do operador 'menor que' para comparar vertices por distancia*/
bool Vertex::operator<(const Vertex &x){
	return mDistance < x.getDistance();
}
/*Sobrecarga do operador 'maior que' para comparar vertices por distancia*/
bool Vertex::operator>(const Vertex &x){
	return mDistance > x.getDistance();
}
/*Sobrecarga do operador 'igual a' para copiar um vertice*/
void Vertex::operator=(const Vertex &x){
	mIndex = x.getIndex();
	mDistance = x.getDistance();
}

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe vertice
*/

#include "headers/vertice.h"

friend ostream & operator <<(ostream & s, const Vertex & z) {
	s << z.v_index;
	return s;
}
Vertex::Vertex (int i, float d) {
	v_index=i;
	mDistance=d;
}
unsigned Vertex::getIndex (){
	return mIndex;
}
void Vertex::setDistance (float distance){
	mDistance = distance
}
float Vertex::getDistance (){
	return mDistance;
}
bool Vertex::operator<(const Vertex &x) {
	return mDistance < x.getDistance();
}
bool Vertex::operator>(const Vertex &x) {
	return mDistance > x.getDistance();
}
void Vertex::operator=(const Vertex &x) {
	mIndex = x.getIndex();
	mDistance = x.getDistance();
}

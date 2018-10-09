/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Declaração da classe vertice
*/

#ifndef VERTICE_H
#define VERTICE_H	"vertice.h"

#include <iostream>

using namespace std;

class Vertex {
	friend ostream & operator <<(ostream & s, const Vertex & z);
	public:
		Vertex ();
		Vertex (int, float); //construtor
		void setIndex (unsigned);//configura o indice do vertice
		unsigned getIndex () const; //retorna o indice que identifica o vertice
		void setDistance (float); //configura a distancia para este vertice a partir de uma raiz conhecida
		float getDistance () const; //retorna a distancia para o vertice
		bool operator<(const Vertex &x); //sobrecarga do operador 'menor que' para comparar distancias dos vertices
		bool operator>(const Vertex &x); //sobrecarga do operador 'maior que' para comparar distancias dos vertices
		void operator=(const Vertex &x); //sobrecarga do operador 'igual a' para copiar um vertice
	private:
		int mIndex; //atributo que identifica o vertice
		float mDistance; //atributo que indica a distancia para chegar ao vertice
};

#endif

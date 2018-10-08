/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Declaração da classe vertice
*/

#ifndef VERTICE_H
#define VERTICE_H	"vertice.h"

class Vertex {
	friend ostream & operator <<(ostream & s, const Vertex & z);
	public:
		Vertex (int, float);
		unsigned getIndex ();
		void setDistance (float);
		float getDistance ();
		bool operator<(const Vertex &x);
		bool operator>(const Vertex &x);
		void operator=(const Vertex &x);
	private:
		int mIndex;
		float mDistance;
};

#endif

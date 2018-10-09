/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe MyHeap
*/

#include <cmath> //para a função floor
#include "my-heap.h"

/*Construtor da classe MyHeap*/
MyHeap::MyHeap (unsigned n) {
	mHeapIndex.resize(n);
}
/*Destrutor da classe MyHeap*/
MyHeap::~MyHeap (){
}
/*Método que adiciona um elemento ao heap*/
void MyHeap::push(Vertex vertex) {
	Vertex temp;
	mQueue.push_back(vertex); //adiciona o vertice no heap
	unsigned position = mQueue.size(); //obtem o novo tamanho do heap (numero de vertices)
	mHeapIndex[vertex.getIndex()-1] = position-1; //salva a posição do vertice no heap (final do heap) num vetor de posições

	if (position != 1) {//se há mais de um elemento no heap
		while (mQueue[position-1] < mQueue[floor(position/2)-1]) {//laço para rearrumar o heap
			temp = mQueue[floor(position/2)-1];
			mQueue[floor(position/2)-1] = mQueue[position-1];
			mQueue[position-1]=temp;
			mHeapIndex[mQueue[position-1].getIndex()-1]=position-1;
			mHeapIndex[mQueue[floor(position/2)-1].getIndex()-1]=floor(position/2)-1;
			position=floor(position/2);
			if (position==1) {
				break;
			}
		}
	}
}
/*Método que remove a raíz do heap*/
Vertex MyHeap::pop() {
	Vertex temp;
	Vertex popedVertex = mQueue[0];
	mQueue[0]=mQueue.back(); //pega o vertice do final do heap e coloca na raiz
	mQueue.pop_back(); //diminui o tamanho do heap

	mHeapIndex[mQueue[0].getIndex()-1]=0; //o vertice colocado na raiz agora esta na posição 0 do heap
	unsigned i=1;
	while ((2*i-1) < mQueue.size()) { //laço para rearrumar o heap
			temp = mQueue[i-1];
			if ((2*i) < mQueue.size()) {
				if (mQueue[2*i-1] < mQueue[2*i] && mQueue[i-1] > mQueue[2*i-1]) {
					mQueue[i-1] = mQueue[2*i-1];
					mQueue[2*i-1] = temp;
					mHeapIndex[mQueue[2*i-1].getIndex()-1] = 2*i-1;
					mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
					i=2*i;
				}
				else if (mQueue[i-1] > mQueue[2*i]){
					mQueue[i-1] = mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()-1] = 2*i;
					mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
					i = 2*i+1;
				}
				else {
					break;
				}
			}
			else {
				if (mQueue[i-1] > mQueue[2*i-1]) {
					mQueue[i-1] = mQueue[2*i-1];
					mQueue[2*i-1] = temp;
					mHeapIndex[mQueue[2*i-1].getIndex()-1] = 2*i-1;
					mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
					i = 2*i;
				}
				else {
					break;
				}
			}
		}
	return popedVertex;
}
/*Método que atualiza a distancia de um vertice do heap*/
void MyHeap::update(unsigned vertex, float distance) {
	Vertex temp;
	unsigned vIndex = mHeapIndex[vertex-1]; //identifica a posição do vertice no heap
	mQueue[vIndex].setDistance(distance); //atualiza sua distancia

	unsigned i = vIndex + 1;
	/*Rearrumando o heap*/
	if (mQueue[i-1] < mQueue[floor(i/2)-1]) {
		if (i != 1) {
			while (mQueue[i-1] < mQueue[floor(i/2)-1]) {
				temp = mQueue[floor(i/2)-1];
				mQueue[floor(i/2)-1] = mQueue[i-1];
				mQueue[i-1] = temp;
				mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
				mHeapIndex[mQueue[floor(i/2)-1].getIndex()-1] = floor(i/2)-1;
				i = floor(i/2);
				if (i==1) {
					break;
				}
			}
		}
	}
	else {
		while ((2*i-1) < mQueue.size()) {
			temp = mQueue[i-1];
			if ((2*i) < mQueue.size()) {
				if (mQueue[2*i-1] < mQueue[2*i] && mQueue[i-1] > mQueue[2*i-1]) {
					mQueue[i-1] = mQueue[2*i-1];
					mQueue[2*i-1] = temp;
					mHeapIndex[mQueue[2*i-1].getIndex()-1] = 2*i-1;
					mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
					i=2*i;
				}
				else if (mQueue[i-1]>mQueue[2*i]){
					mQueue[i-1]=mQueue[2*i];
					mQueue[2*i]=temp;
					mHeapIndex[mQueue[2*i].getIndex()-1] = 2*i;
					mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
					i=2*i+1;
				}
				else {
					break;
				}
			}
			else {
				if (mQueue[i-1]>mQueue[2*i-1]) {
					mQueue[i-1]=mQueue[2*i-1];
					mQueue[2*i-1] = temp;
					mHeapIndex[mQueue[2*i-1].getIndex()-1] = 2*i-1;
					mHeapIndex[mQueue[i-1].getIndex()-1] = i-1;
					i = 2*i;
				}
				else {
					break;
				}
			}
		}
	}
}
/*Método que exibe o heap*/
void MyHeap::show() {
	for (unsigned i=0; i < mQueue.size(); i++) {
		cout << mQueue[i].getIndex() << " ";
	}
	cout << endl;
}
/*Método que confere se o heap está vazio*/
bool MyHeap::empty() {
	return mQueue.empty();
}

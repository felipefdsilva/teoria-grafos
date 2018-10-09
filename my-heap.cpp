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
	for (unsigned i=0; i<n; i++) {
		mHeapIndex.push_back(-1);
	}
}
/*Destrutor da classe MyHeap*/
MyHeap::~MyHeap (){
}
/*Método que adiciona um elemento ao heap*/
void MyHeap::push(Vertex vertex) {
	Vertex temp;
	mQueue.push_back(vertex); //adiciona o vertice no heap
	unsigned position = mQueue.size()-1; //obtem o novo tamanho do heap (numero de vertices)
	mHeapIndex[vertex.getIndex()] = position; //salva a posição do vertice no heap (final do heap) num vetor de posições

	if (position != 1) {
		while (mQueue[position] < mQueue[floor(position/2)]) {//laço para rearrumar o heap
			temp = mQueue[floor(position/2)];
			mQueue[floor(position/2)] = mQueue[position];
			mQueue[position]=temp;
			mHeapIndex[mQueue[position].getIndex()]=position;
			mHeapIndex[mQueue[floor(position/2)].getIndex()]=floor(position/2);
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
	Vertex popedVertex = mQueue[1];
	mQueue[1]=mQueue.back(); //pega o vertice do final do heap e coloca na raiz
	mQueue.pop_back(); //diminui o tamanho do heap

	mHeapIndex[mQueue[1].getIndex()]=1; //o vertice colocado na raiz agora esta na posição 1 do heap
	for (unsigned i=1; (2*i) < mQueue.size(); i=2*i) { //laço para rearrumar o heap
			temp = mQueue[i];
			if ((2*i) < mQueue.size()) {
				if (mQueue[2*i] < mQueue[2*i] && mQueue[i] > mQueue[2*i]) {
					mQueue[i-1] = mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2*i;
					mHeapIndex[mQueue[i].getIndex()] = i;
				}
				else if (mQueue[i-1] > mQueue[2*i]){
					mQueue[i] = mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2*i;
					mHeapIndex[mQueue[i].getIndex()] = i;
					i = 2*i+1;
				}
				else {
					break;
				}
			}
			else {
				if (mQueue[i] > mQueue[2*i]) {
					mQueue[i] = mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2*i;
					mHeapIndex[mQueue[i].getIndex()] = i;
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
	unsigned vIndex = mHeapIndex[vertex]; //identifica a posição do vertice no heap
	mQueue[vIndex].setDistance(distance); //atualiza sua distancia

	unsigned i = vIndex + 1;
	/*Rearrumando o heap*/
	if (mQueue[i] < mQueue[floor(i/2)]) {
		if (i != 1) {
			while (mQueue[i] < mQueue[floor(i/2)]) {
				temp = mQueue[floor(i/2)];
				mQueue[floor(i/2)] = mQueue[i];
				mQueue[i] = temp;
				mHeapIndex[mQueue[i].getIndex()] = i;
				mHeapIndex[mQueue[floor(i/2)].getIndex()] = floor(i/2);
				i = floor(i/2);
				if (i==1) {
					break;
				}
			}
		}
	}
	else {
		while ((2*i) < mQueue.size()) {
			temp = mQueue[i];
			if ((2*i) < mQueue.size()) {
				if (mQueue[2*i] < mQueue[2*i] && mQueue[i] > mQueue[2*i]) {
					mQueue[i] = mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2 * i;
					mHeapIndex[mQueue[i].getIndex()] = i;
					i = 2 * i;
				}
				else if (mQueue[i-1]>mQueue[2*i]){
					mQueue[i]=mQueue[2*i];
					mQueue[2*i]=temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2*i;
					mHeapIndex[mQueue[i].getIndex()] = i;
					i=2*i+1;
				}
				else {
					break;
				}
			}
			else {
				if (mQueue[i]>mQueue[2*i]) {
					mQueue[i]=mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2*i;
					mHeapIndex[mQueue[i].getIndex()] = i;
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

/*
* Universidade Federal do Rio de Janeiro
* Teoria dos Grafos 2018.2
* Trabalho da Disciplina - Parte 2 (Grafos com pesos)
* Autores: Felipe Ferreira e Luis Fernando
* Implementação da classe grafo
*/

#include <cmath> //para a função floor
#include "headers/my-heap.h"

MyHeap::MyHeap (unsigned n) {
	for (unsigned i=0; i<n; i++) {
		mHeapIndex.push_back(-1);
	}
}
void MyHeap::push(Vertex vertex) {
	mQueue.push_back(vertex);
	unsigned heapSize=mQueue.size();
	mHeapIndex[vertex.getIndex()]=heapSize;
	if (heapSize != 1) {
		while (mQueue[heapSize] < mQueue[floor(heapSize/2)]) {
			Vertex temp = mQueue[floor(heapSize/2)];
			mQueue[floor(heapSize/2)]=mQueue[heapSize];
			mQueue[heapSize]=temp;
			mHeapIndex[mQueue[heapSize].getIndex()]=heapSize;
			mHeapIndex[mQueue[floor(heapSize/2)].getIndex()]=floor(heapSize/2);
			heapSize=floor(heapSize/2);
			if (heapSize==1) {
				break;
			}
		}
	}
}
Vertex MyHeap::pop() {
	Vertex ret=mQueue[1];
	mQueue[1]=mQueue.back();
	mQueue.pop_back();
	unsigned i=1;
	mHeapIndex[mQueue[1].getIndex()]=0;
	while ((2*i) < mQueue.size()) {
			Vertex temp = mQueue[i];
			if ((2*i) < mQueue.size()) {
				if (mQueue[2*i] < mQueue[2*i] && mQueue[i] > mQueue[2*i]) {
					mQueue[i-1] = mQueue[2*i];
					mQueue[2*i] = temp;
					mHeapIndex[mQueue[2*i].getIndex()] = 2*i;
					mHeapIndex[mQueue[i].getIndex()] = i;
					i = 2*i;
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
	return ret;
}
void MyHeap::update(unsigned vertex, float distance) {
	unsigned j=mHeapIndex[vertex];
	mQueue[j].setDistance(distance);
	unsigned i = j + 1;
	if (mQueue[i] < mQueue[floor(i/2)]) {
		if (i != 1) {
			while (mQueue[i] < mQueue[floor(i/2)]) {
				Vertex temp=mQueue[floor(i/2)];
				mQueue[floor(i/2)]=mQueue[i];
				mQueue[i]=temp;
				mHeapIndex[mQueue[i].getIndex()]=i;
				mHeapIndex[mQueue[floor(i/2)].getIndex()]=floor(i/2);
				i=floor(i/2);
				if (i==1) {break;}
			}
		}
	}
	else {
		while ((2*i) < mQueue.size()) {
			Vertex temp = mQueue[i];
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
void MyHeap::show() {
	for (unsigned i=0; i < mQueue.size(); i++) {
		cout << mQueue[i].getIndex() << " ";
	}
	cout << endl;
}
bool MyHeap::empty() {
	return mQueue.size()==0;
}

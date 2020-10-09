
#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H



// Cola de prioridad de máximos de tipo TDA
#include "Heap.h"
template<class T>
class ColaPrioridad {
private:
	heap<T>* heapD;
public:
	ColaPrioridad();
	~ColaPrioridad();
	ColaPrioridad(string n);
	ColaPrioridad(ColaPrioridad<T>&);
	void insertar(T*);
	T* eliminar();
	string toString();
	heap<T>* retornarHeap();
};
template<class T>
ColaPrioridad<T>::ColaPrioridad(){}
template<class T>
ColaPrioridad<T>::~ColaPrioridad() {
	delete heapD;
}
template<class T>
ColaPrioridad<T>::ColaPrioridad(string n) {
	heapD = new heap<T>(n);
}
template<class T>
ColaPrioridad<T>::ColaPrioridad(ColaPrioridad<T>& h) {
	if (h.heapD == nullptr)
	{
		this->heapD = nullptr;
	}
	else
	{
		delete heapD;
		heapD= h.heapD;
	}
}
template<class T>
void ColaPrioridad<T>::insertar(T* data) {
	heapD->AgregarleHeap(data);
}
template<class T>
T* ColaPrioridad<T>::eliminar() {
	return heapD->ElminardelHeap();
}

template<class T>
heap<T>* ColaPrioridad<T>::retornarHeap() {
	return heapD;
}

template<class T>
string  ColaPrioridad<T>::toString() {
	return heapD->getLista()->toString();
}
#endif
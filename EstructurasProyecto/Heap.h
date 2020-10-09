#pragma once
#include "ColaPrioridadListaDoble.h"
template<class T>
class heap {
private:
	ListaDobleColaPrioridad<T>* lista;
	string tipo;
public:
	heap();
	heap(string tipo);
	heap(const heap<T>&);
	ListaDobleColaPrioridad<T>* getLista();
	void crearHeap(string n);
	int getPadre(int i);//no se usa
	T* getLeft(int i);//no se usa
	T* getRight(int i);//no se usa
	void heapifyMax( int i);
	void heapifyMin( int i);
	void maxHeap(int i);
	void minHeap(int i);
	void AgregarleHeap(T*);
	T* ElminardelHeap();
	~heap();
};
//Constructor 
template<class T>
ListaDobleColaPrioridad<T>* heap<T>::getLista() {
	return lista;
}
template<class T>
heap<T>::~heap() {
	delete lista;
}
template<class T>
heap<T>::heap(const heap<T>& h) {
	if (h.lista== nullptr)
	{
		this->lista= nullptr;
	}
	else
	{
		delete lista;
		lista = h.lista;
		
	}
}
template<class T>
heap<T>::heap(){}
template<class T>
heap<T>::heap(string n) {
	tipo = n;
	lista = new ListaDobleColaPrioridad<T>;//mandar 
	crearHeap(tipo);
}
// Metods del HEAP--------------------------------------------------
template<class T>
void heap<T>::crearHeap(string n) {
	if (n == "max") {
		maxHeap(lista->getSimulaCantidad() - 1);
		tipo = "max";
	}
	else {
		if (n == "min") {
			minHeap(lista->getSimulaCantidad() - 1);
			tipo = "min";
		}
	}
}
template<class T>
int heap<T>::getPadre(int i)
{
	if (i < 0 || i > lista->getSimulaCantidad())
		return -1;

	return (i - 1) / 2;//probando
}

template<class T>
T* heap<T>::getLeft(int i)
{
	return lista->index((2 * i) + 1)->getDataTemplate();
}

template<class T>
T* heap<T>::getRight(int i)
{
	return lista->index((2 * i) + 2)->getDataTemplate();
}
//===========================================================================
template<class T>

void heap<T>::maxHeap(int i) {//esto aun no sirve siftup
	int tmp = getPadre(i);
	while (i >= 0 && ((*lista->index(tmp)->getTemplateData()) < (lista->index(i)->getTemplateData())))
	{
		lista->swap(i, tmp);
		i = tmp;
		tmp = getPadre(i);
	}
}
template<class T>
void heap<T>::heapifyMax(int i) {
	int mayor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;

	if (izq <  lista->getSimulaCantidad() && (*lista->index(izq)->getTemplateData()) > lista->index(mayor)->getTemplateData()) {//Se comparan con Sobrecarga
		mayor = izq;
	}

	if (der <  lista->getSimulaCantidad() && (*lista->index(der)->getTemplateData() )> lista->index(mayor)->getTemplateData()) {
		mayor = der;
	}

	if (mayor != i) {
		lista->swap(i, mayor);

		heapifyMax(mayor);
	}
}
template<class T>
void heap<T>::minHeap(int i) {

	int tmp = getPadre(i);
	
	while (i >= 0 && ((*lista->index(tmp)->getTemplateData()) > (lista->index(i)->getTemplateData())))
	{
		lista->swap(i, tmp);
		i = tmp;
		tmp = getPadre(i);
	}
}
template<class T>
void heap<T>::heapifyMin( int i) {
	int menor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;

	if (izq <( lista->getSimulaCantidad()) && (*lista->index(izq)->getTemplateData()) < lista->index(menor)->getTemplateData()) {//Se comparan con Sobrecarga
		menor = izq;
	}

	if (der < (lista->getSimulaCantidad() ) && (*lista->index(der)->getTemplateData() )< lista->index(menor)->getTemplateData()) {
		menor = der;
		
	}

	if (menor != i) {
		lista->swap(i, menor);

		heapifyMin(menor);
	}
}
template<class T>
void heap<T>::AgregarleHeap(T* newD) {
	lista->pushEnd2(newD);// modificar nombre 
	if (tipo == "max") {
		maxHeap(lista->getSimulaCantidad() - 1);
	}
	else {
		if (tipo == "min") {
			minHeap(lista->getSimulaCantidad()-1 );			
		}
	}

}
template<class T>
T* heap<T>::ElminardelHeap() {
	T* front = nullptr;
	 front =new T(*lista->index(0)->getTemplateData());
	lista->popfront();
	lista->push(lista->getTail()->getTemplateData());
	lista->popback();
	if (tipo == "max") {
		if (lista->getHead()!= nullptr) {
			heapifyMax(0);
			return front;
		}
		else {
			return front;
		}
	}
	else {
		if (tipo == "min") {
			if (lista->getHead() != nullptr){
				heapifyMin(0);
			return front;
		}
			else {
				return front;
			}
		}
	}
	return front;
}
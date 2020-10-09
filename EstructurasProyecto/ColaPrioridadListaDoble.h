#ifndef COLAPRIORIDADLISTADOBLE_H
#define COLAPRIORIDADLISTADOBLE_H

#include<sstream>
#include <iostream>
#include <string>
using namespace std;
//Nodo de La lista Doble-------------------------------------
template<class T>
class Nodo
{
private:
	T* dataTemplate;
	Nodo* sig;
	Nodo* prev;
	int SimulaPos;// simula posicion como en el array
public:
	Nodo(T*);
	Nodo(T*, int);
	T* getTemplateData();
	Nodo* getSig();
	Nodo* getPrev();
	int getSimulaPos();
	void setTemplateData(T*);
	void setSig(Nodo<T>*);
	void setPrev(Nodo<T>*);
	void setSimulaPos(int pos);
	virtual ~Nodo();
};

template<class T>
Nodo<T>::Nodo(T* data) :dataTemplate(data){}
template<class T>
Nodo<T>::Nodo(T* _data, int pos)
{
	this->data = _data;
	this->pos = pos;
}
template<class T>
void Nodo<T>::setTemplateData(T* dataTemplate)
{
	this->dataTemplate = dataTemplate;
}
template<class T>
T* Nodo<T>::getTemplateData()
{
	return dataTemplate;
}

template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}

template<class T>
Nodo<T>* Nodo<T>::getPrev()
{
	return prev;
}

template<class T>
int Nodo<T>::getSimulaPos()
{
	return SimulaPos;
}


template<class T>
void Nodo<T>::setSimulaPos(int pos)
{
	SimulaPos = pos;
}
template<class T>
void Nodo<T>::setSig(Nodo<T>* sig)
{
	this->sig = sig;
}

template<class T>
void Nodo<T>::setPrev(Nodo<T>* prev)
{
	this->prev = prev;
}
template<class T>
Nodo<T>::~Nodo()
{
	delete dataTemplate;
}



//Lista Doble de tipo Template Enlanzada------------------------------------------------------------------------------------------------------
template<class T>
class ListaDobleColaPrioridad
{
private:
	//
	Nodo<T>* head;
	Nodo<T>* tail;
	string tipo;
	int Simulacantidad;//simular una cantida conmo el array
public:
	//Metodos Basicos de la Lista Doble--------------------------------------------
	ListaDobleColaPrioridad();
	ListaDobleColaPrioridad(const ListaDobleColaPrioridad<T>&);
	int getSimulaCantidad();
	void setSimulaCantidad(int c);
	Nodo<T>* getHead();
	Nodo<T>* getTail();
	bool EsVacia();
	void push( T* TemplateData);
	void pushEnd2(T* TemplateData);
	void popfront();
	void popback();
	void swap(int x, int y);
	Nodo<T>* index(int x );
	string toString();
	virtual ~ListaDobleColaPrioridad();
	//Metodos del Heap----------------------------------------------------------------

	//void crearHeap(string n);
	//int getPadre(int i);//no se usa
	//T* getLeft(int i);//no se usa
	//T* getRight(int i);//no se usa
	//void heapifyMax( int cant, int i);
	//void heapifyMin( int cant, int i);
	//void maxHeap(int i);
	//void minHeap(int i);
	//void AgregarleHeap(T*);
	//void ElminardelHeap();

};
#endif
template<class T>
void ListaDobleColaPrioridad<T>::popback() {
	if (head == nullptr) {
		return;
	}
	if (tail != nullptr) {

		Nodo<T>* newtail = getTail()->getPrev();
		
		tail = nullptr;

		newtail->setSig(nullptr);
		tail = newtail;
	}
	else {
		head = nullptr;
	}
}
template<class T>
ListaDobleColaPrioridad<T>::ListaDobleColaPrioridad()
{
	head = nullptr;
	tail = nullptr;
	tipo = " ";
	Simulacantidad = 0;
}

template<class T>
ListaDobleColaPrioridad<T>::ListaDobleColaPrioridad(const ListaDobleColaPrioridad<T>& list2)//Revisar
{
	if (list2.head == nullptr)
	{
		this->head = nullptr;
	}
	else
	{
		head = new Nodo<T>(list2.head->data, list2.head->pos);
		Nodo<T>* aux = list2.head;
		while (aux->getSig != nullptr)
		{
			head->sig = new Nodo<T> * (aux->sig->data, aux->sig->pos);
			head->sig->prev = head;
			aux = aux->sig;
			head = head->sig;
		}
	}

}

template<class T>
void ListaDobleColaPrioridad<T>::setSimulaCantidad(int c)
{
	Simulacantidad = c;
}

template<class T>
int ListaDobleColaPrioridad<T>::getSimulaCantidad()
{
	return Simulacantidad;
}

template<class T>
Nodo<T>* ListaDobleColaPrioridad<T>::getHead()
{
	return head;
}


template<class T>
Nodo<T>* ListaDobleColaPrioridad<T>::getTail()
{
	return tail;
}
template<class T>
bool ListaDobleColaPrioridad<T>::EsVacia()
{
	return !head;
}

template<class T>
inline void ListaDobleColaPrioridad<T>::push( T* TemplateData)
{
	Nodo<T>* newH = new Nodo<T> (TemplateData);
	newH->setSig(head);
	newH->setPrev(nullptr);

	if (head != nullptr)
	{
		head->setPrev(newH);
	}
	head = newH;
	newH->setSimulaPos(0);//ultimo cambio 10/08/2020
}



template<class T>
void ListaDobleColaPrioridad<T>::pushEnd2(T* TemplateData)
{
	if (head == nullptr){
		head = new Nodo<T>(TemplateData);
	
		head->setSimulaPos(Simulacantidad);
		Simulacantidad = Simulacantidad+1;
		tail = head;
	}
	else{

		Nodo<T>* end = new Nodo<T>(TemplateData);
		Nodo<T>* tmp = head;
		while (tmp->getSig() != nullptr)
		{

			tmp = tmp->getSig();

		}
		tmp->setSig(end);
		end->setPrev(tmp);
		
		head->setSimulaPos(Simulacantidad);
		Simulacantidad = Simulacantidad+1;
		tail = end;

	}
}

template<class T>
void ListaDobleColaPrioridad<T>::popfront()//Sacar  el primero de la lista
{
	if (head == nullptr)
	{
		return;
	}
if (head->getSig()== nullptr) {
	delete head;
	head = nullptr;
	setSimulaCantidad(Simulacantidad - 1);
	return;
	}
	head = head->getSig();
	
		head->getPrev()->setSig(nullptr);
		delete head->getPrev();
		head->setPrev(nullptr);
		setSimulaCantidad(Simulacantidad - 1);


		Nodo<T>* aux = head;
		while (aux->getSig() != nullptr)
		{
			aux->setSimulaPos(aux->getSimulaPos() - 1);
			aux = aux->getSig();
		}

	
}
template<class T>
Nodo<T>* ListaDobleColaPrioridad<T>::index(int x)
{
	if (EsVacia()) {
		return nullptr;
	}
	if (x > Simulacantidad) {
		return nullptr;
	}
	Nodo<T>* tmp = head;
	if (x == 0) {
		return head;
	}
	int i = 1;
	while(i <= x && tmp->getSig()!= nullptr) {//for corregido
		tmp = tmp->getSig();

		i++;

	}
	if (tmp != nullptr)
		return tmp;
	else
		return nullptr;
}
template<class T>
void ListaDobleColaPrioridad<T>::swap(int x , int y)// Hacer cambios entres nodos como se hace en arrays
{
	T* tmp = index(x)->getTemplateData();
	index(x)->setTemplateData(index(y)->getTemplateData());

	index(y)->setTemplateData(tmp);

	tmp = nullptr;
}


//Imprimir Lista
template<class T>
string ListaDobleColaPrioridad<T>::toString()
{
	stringstream s;
	Nodo<T>* tmp = this->head;
	while (tmp){
		s << tmp->getTemplateData()->toString() << endl;
		tmp = tmp->getSig();
	}
	return s.str();

}
//Eliminar Lista
template<class T>
ListaDobleColaPrioridad<T>::~ListaDobleColaPrioridad()
{
	Nodo<T>* aux;
	while (head != nullptr)
	{
		aux = head;
		head = head->getSig();
		delete aux;
	}
}

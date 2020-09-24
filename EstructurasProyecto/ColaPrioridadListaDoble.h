#pragma once
#include <iostream>
using namespace std;
class ListaDoble {
private:
	struct Nodo {
		int valor;
		struct Nodo* prev;
		struct Nodo* next;
		Nodo(int v = 0, Nodo* n = nullptr, Nodo* n2 = nullptr) : valor{ v }, next{ n }, prev{ n2 } {}
	};

public:	Nodo* inicio;
	  typedef Nodo* iterador;
	  ListaDoble();
	  virtual ~ListaDoble();
	  void insertar(int val);
	  void insertarPos(int val, int pos);
	  void Borrar(int pos);
	  void eliminarLista();
	  iterador GetPrimerNodo() { return inicio; }
	  iterador GetPrimerNodo() const { return inicio; }
	  void toString();

	  void InvertirLista(Nodo*& actual);
	  void InvertirListaRecursivo(Nodo*& actual, Nodo* sig, Nodo* tmp);
};

ListaDoble::ListaDoble() { inicio = nullptr; }
void ListaDoble::eliminarLista() {
	Nodo* tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
}
ListaDoble::~ListaDoble() {
	eliminarLista();
}

void ListaDoble::insertar(int val) {
	Nodo* nuevo;

	nuevo = new Nodo(val);

	if (inicio == nullptr)
		inicio = nuevo;
	else {
		Nodo* tmp = inicio;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		tmp->next = nuevo;
		nuevo->prev = tmp;


	}

}


void ListaDoble::Borrar(int pos) {
	if (pos <= 0 || inicio == nullptr)
		return;


	Nodo* tmp2 = inicio;

	// Si es la primera posición
	if (pos == 1) {
		Nodo* tmp2 = inicio;
		inicio = inicio->next;
		delete tmp2;
		return;
	}

	// Para cualquier otro caso
	for (size_t i = 1; i < pos; ++i) {
		tmp2 = tmp2->next;;
	}

	if (tmp2 != nullptr) {
		tmp2->prev->next = tmp2->next;
		if (tmp2->next != nullptr)
			tmp2->next->prev = tmp2->prev;
		delete tmp2;
	}
}
void ListaDoble::toString() {
	if (GetPrimerNodo() != nullptr) {
		ListaDoble::iterador tmp = GetPrimerNodo();
		while (tmp != nullptr) {
			std::cout << tmp->valor << " ";
			tmp = tmp->next;
		}
	}
	std::cout << "\n\n";
}
void ListaDoble::InvertirLista(Nodo*& actual) {
	Nodo* head = actual;
	Nodo* sig = nullptr;
	Nodo* tmp = nullptr;
	while (head->next) {
		sig = head->next;
		head->next = tmp;
		if (head->next != nullptr) {
			head->next = tmp;
			tmp->prev = head;
		}
		tmp = head;
		head = sig;
		head->prev = nullptr;
	}
	head->next = tmp;
	tmp->prev = head;
	head->prev = nullptr;
	actual = head;
}
void ListaDoble::InvertirListaRecursivo(Nodo*& actual, Nodo* sig, Nodo* tmp) {
	if (actual->next == nullptr) {
		actual->next = tmp;
		tmp->prev = actual;
		actual->prev = nullptr;
		return;
	}
	else {
		sig = actual->next;
		actual->next = tmp;
		if (actual->next != nullptr) {
			actual->next = tmp;
			tmp->prev = actual;
		}
		tmp = actual;
		actual = sig;
		actual->prev = nullptr;
		InvertirListaRecursivo(actual, sig, tmp);
	}
}

void ListaDoble::insertarPos(int val, int pos) {
	Nodo* nuevo;
	Nodo* tmp2 = inicio;
	nuevo = new Nodo(val);

	if (pos == 1) {
		inicio->prev = nuevo;
		nuevo->next = inicio;
		inicio = nuevo;

	}
	for (size_t i = 1; i < pos; ++i) {
		tmp2 = tmp2->next;;
	}
	if (tmp2 != nullptr) {
		nuevo->prev = tmp2->prev;
		nuevo->next = tmp2;
		tmp2->prev = nuevo;
		nuevo->prev->next = nuevo;


	}
}
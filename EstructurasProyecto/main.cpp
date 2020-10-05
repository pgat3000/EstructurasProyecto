/*
Integrantes: 
	Pablo Jose Gatgens Chaves
	Joaquin Barrientos Monge
*/


#include <iostream>
#include "ColaPrioridadListaDoble.h"

#include "Tareas.h"

int main() {
	
	ListaDobleColaPrioridad<Tarea>* tmp = new ListaDobleColaPrioridad<Tarea>;
	//Tarea* t = new Tarea();
	
	Tarea* t1 = new Tarea(0,0,"M","D",20);
	Tarea* t2 = new Tarea(0, 0, "P", "D", 44);
	Tarea* t3 = new Tarea(0, 0, "C", "D", 55);
	Tarea* t5 = new Tarea(0, 0, "C", "D", 60);
	Tarea* t4 = new Tarea(0, 0, "A", "D", 25);
	Tarea* t6 = new Tarea(0, 0, "S", "D", 10);
	if ((*t5) > t4) {
		cout << "mas grande" << endl;
	}
	else {
		cout << "main pequeno" << endl;
	}
	tmp->crearHeap("min");
	tmp->AgregarleHeap(t5);
	tmp->AgregarleHeap(t4);
	//cout << tmp->toString() << endl;
	tmp->AgregarleHeap(t3);
	//cout << tmp->toString() << endl;
	tmp->AgregarleHeap(t1);
	//cout << tmp->toString() << endl;
	tmp->AgregarleHeap(t2);
	tmp->AgregarleHeap(t6);
	cout << tmp->toString() << endl;
	return 0;

}
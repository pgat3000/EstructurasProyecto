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
	tmp->crearHeap("min");
	tmp->AgregarleHeap(t3);
	tmp->AgregarleHeap(t2);
	//cout << tmp->toString() << endl;
	tmp->AgregarleHeap(t5);
	//cout << tmp->toString() << endl;
	tmp->AgregarleHeap(t1);
	//cout << tmp->toString() << endl;
	tmp->AgregarleHeap(t4);
	cout << tmp->toString() << endl;
	return 0;

}
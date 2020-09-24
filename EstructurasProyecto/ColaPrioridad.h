
#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#define CAPACIDAD_MIN	5
#include <list>
#include <iterator> 
#include "tarea.h"
// Cola de prioridad de máximos de tipo TDA


class ColaPrioridad {
public:
	ColaPrioridad() : capacidad{ 0 }, tam{ 0 } { colaPrioridad = new  list<Tarea*>; }
	//ColaPrioridad(int);
	ColaPrioridad(ColaPrioridad&);
	~ColaPrioridad();

	void Agregar(Tarea*);
	Tarea* GetMax();
	Tarea* ExtraerMax();
	void IncrementarLlave(int, int);



private:
	// Estructura para almacenar los elementos de la cola
	//int* cola;
	list<Tarea*>* colaPrioridad;
	int capacidad;
	int tam;

	// Funciones auxiliares
	int GetPadre(int);
	int GetHijoIzquierdo(int);
	int GetHijoDerecho(int);
	void Swap(int, int);
	void MaxHeapify(int);
	void SiftUp(int);
	void ReasignarMemoria();
};

#endif
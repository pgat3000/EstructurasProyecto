
#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#define CAPACIDAD_MIN	5
#include <list>

// Cola de prioridad de máximos de tipo TDA

// Valor mayor tiene mayor prioridad
class ColaPrioridad {
public:
	ColaPrioridad() : capacidad{ CAPACIDAD_MIN }, tam{ 0 } { cola = new int[capacidad]; }
	ColaPrioridad(int);
	ColaPrioridad(ColaPrioridad&);
	~ColaPrioridad();

	void Agregar(int);
	int GetMax();
	int ExtraerMax();
	void IncrementarLlave(int, int);



private:
	// Estructura para almacenar los elementos de la cola
	int* cola;
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
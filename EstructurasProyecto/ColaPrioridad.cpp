#include "ColaPrioridad.h"

// Constructor a partir de un tama�o definido por el usuario
ColaPrioridad::ColaPrioridad(int cantidad) : 
	cola{nullptr}, capacidad{cantidad}, tam{0} {
	cola = new int[capacidad];
}

// Constructor de copia
ColaPrioridad::ColaPrioridad(ColaPrioridad& c) : 
	cola{ nullptr }, capacidad{ c.capacidad }, tam{ c.tam } {

	if (tam > capacidad) {
		tam = 0;
		capacidad = 0;
	}
	else {
		cola = new int[capacidad];
		for (int i = 0; i < tam; ++i) {
			cola[i] = c.cola[i];
		}
	}
}

// Destructor - libera toda la memoria asignada a la cola de prioridad
ColaPrioridad::~ColaPrioridad() {
	delete[] cola;
	capacidad = 0;
	tam = 0;
}

void ColaPrioridad::Agregar(int key) {
	// Si ya se lleg� a la capacidad m�xima de la cola
	// se incrementa el tama�o - se reasigna la memoria
	if (tam == capacidad) {
		ReasignarMemoria();
	}

	// Insertamos en la �ltima posici�n del array y se incrementa el tama�o
	cola[tam++] = key;

	SiftUp(tam - 1);
}

// Retorna el valor con mayor prioridad de la cola
int ColaPrioridad::GetMax() {
	if (tam > 0) {
		return cola[0];
	}
	return -1;
}

// Retorna el valor con mayor prioridad de la cola y lo elimina
int ColaPrioridad::ExtraerMax() {
	if (tam < 0) {
		return -1;
	}

	// Intercambia el elemento con mayor prioridad de la cola con el �ltimo
	// y procede a realizar un bubble down para mantener la propiedad de heap
	int tmp = cola[0];
	cola[0] = cola[tam - 1];
	--tam;
	MaxHeapify(0);
	return tmp;
}

// Incrementa la prioridad de la llave para una posici�n dada
void ColaPrioridad::IncrementarLlave(int i, int key) {
	// Verificamos que no excede los l�mites del arreglo
	// ni que el nuevo valor sea menor que la prioridad actual de la llave
	if (i > tam - 1 || cola[i] > key) {
		return;
	}

	cola[i] = key;
	
	SiftUp(i);
}

// Obtiene el �ndice del nodo padre para la posici�n dada
int ColaPrioridad::GetPadre(int i) {
	if (i < 0 || i > tam)
		return -1;

	return (i - 1) / 2;
}

// Obtiene el �ndice del hijo izquierdo para la posici�n dada
int ColaPrioridad::GetHijoIzquierdo(int i) {
	if (i < 0 || i > tam)
		return -1;

	return 2 * i + 1;
}

// Obtiene el �ndice del hijo derecho para la posici�n dada
int ColaPrioridad::GetHijoDerecho(int i) {
	if (i < 0 || i > tam)
		return -1;

	return 2 * i + 2;
}

// Intercambia dos elementos de la cola
void ColaPrioridad::Swap(int x, int y) {
	int tmp = cola[x];
	cola[x] = cola[y];
	cola[y] = tmp;
}

// Mantiene la propiedad de Heap - movimiento hacia abajo "bubble down - sift down"
// Revisa que el nodo de la posici�n dada cumpla la propiedad de Heap. En caso contrario
// Intercambia las llaves para mantener la propiedad de Max Heap
void ColaPrioridad::MaxHeapify(int i) {
	int izq = GetHijoIzquierdo(i);
	int der = GetHijoDerecho(i);
	int tmp = 0;

	// Se comparan los hijos izquierdo y derecho con la posici�n dada
	// y se almacena el �ndice mayor
	if (izq < tam && cola[izq] > cola[i]) {
		tmp = izq;
	}
	else{
		tmp = i;
	}

	if (der < tam && cola[der] > cola[tmp]) {
		tmp = der;
	}

	// Si alguno de los hijos es m�s grande que la posici�n
	// se intercambia la posici�n con el hijo mayor. El proceso contin�a
	// hacia abajo (bubble down - sift down)
	if (tmp != i) {
		Swap(i, tmp);
		MaxHeapify(tmp);
	}
}

// Intercambia una llave de mayor prioridad con su nodo padre
// hasta que se mantenga la propiedad de Max Heap
void ColaPrioridad::SiftUp(int i) {
	int tmp = GetPadre(i);

	// Bubble up - sift up
	while (i > 0 && cola[tmp] < cola[i]) {
		Swap(i, tmp);
		i = tmp;
		tmp = GetPadre(i);
	}
}

void ColaPrioridad::ReasignarMemoria() {
	int* tmp = cola;
	
	capacidad += 5;
	cola = new int[capacidad];

	for (int i = 0; i < tam; ++i) {
		cola[i] = tmp[i];
	}
	delete[] tmp;
}
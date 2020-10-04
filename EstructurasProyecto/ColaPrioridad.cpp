#include "ColaPrioridad.h"

//
//
//// Constructor de copia
//ColaPrioridad::ColaPrioridad(ColaPrioridad& c) : 
//	colaPrioridad{ nullptr }, capacidad{ c.capacidad }, tam{ c.tam } {
//
//	if (colaPrioridad->empty()) {
//		tam = 0;
//		capacidad = 0;
//	}
//	else {
//		colaPrioridad = new  list<Tarea*>;
//		list <Tarea*> ::iterator it;
//		list<Tarea*>::iterator it2;
//		it2 = c.colaPrioridad->begin();
//		for (it = colaPrioridad->begin(); it != colaPrioridad->end(); ++it){
//			*it = *it2;
//		it2++;
//	}
//	}	
//	}
//
//
//// Destructor - libera toda la memoria asignada a la cola de prioridad
//ColaPrioridad::~ColaPrioridad() {
//	delete[] colaPrioridad;
//	capacidad = 0;
//	tam = 0;
//}
//
//void ColaPrioridad::Agregar(Tarea* t) {
//
//
//	// Insertamos en la última posición del array y se incrementa el tamaño
//	colaPrioridad->push_back(t);
//	
//
//	SiftUp(tam - 1);
//}
//
//// Retorna el valor con mayor prioridad de la cola
//Tarea* ColaPrioridad::GetMax() {
//	if (tam > 0) {
//		return colaPrioridad->front();
//	}
//	return nullptr;
//}
//
//// Retorna el valor con mayor prioridad de la cola y lo elimina
//Tarea* ColaPrioridad::ExtraerMax() {
//	if (tam < 0) {
//		return nullptr;
//	}
//
//	// Intercambia el elemento con mayor prioridad de la cola con el último
//	// y procede a realizar un bubble down para mantener la propiedad de heap
//	Tarea* tmp = colaPrioridad->front();
//	*colaPrioridad->begin() = *colaPrioridad->end();
//	colaPrioridad->pop_back;
//	
//	MaxHeapify(0);
//	return tmp;
//}
//
//// Incrementa la prioridad de la llave para una posición dada
//void ColaPrioridad::IncrementarLlave(int i, int key) {
//	// Verificamos que no excede los límites del arreglo
//	// ni que el nuevo valor sea menor que la prioridad actual de la llave
//	if (i > tam - 1 || cola[i] > key) {
//		return;
//	}
//
//	cola[i] = key;
//	
//	SiftUp(i);
//}
//
//// Obtiene el índice del nodo padre para la posición dada
//int ColaPrioridad::GetPadre(int i) {
//	if (i < 0 || i > tam)
//		return -1;
//
//	return (i - 1) / 2;
//}
//
//// Obtiene el índice del hijo izquierdo para la posición dada
//int ColaPrioridad::GetHijoIzquierdo(int i) {
//	if (i < 0 || i > tam)
//		return -1;
//
//	return 2 * i + 1;
//}
//
//// Obtiene el índice del hijo derecho para la posición dada
//int ColaPrioridad::GetHijoDerecho(int i) {
//	if (i < 0 || i > tam)
//		return -1;
//
//	return 2 * i + 2;
//}
//
//// Intercambia dos elementos de la cola
//void ColaPrioridad::Swap(int x, int y) {
//	int tmp = cola[x];
//	cola[x] = cola[y];
//	cola[y] = tmp;
//}
//
//// Mantiene la propiedad de Heap - movimiento hacia abajo "bubble down - sift down"
//// Revisa que el nodo de la posición dada cumpla la propiedad de Heap. En caso contrario
//// Intercambia las llaves para mantener la propiedad de Max Heap
//void ColaPrioridad::MaxHeapify(int i) {
//	int izq = GetHijoIzquierdo(i);
//	int der = GetHijoDerecho(i);
//	int tmp = 0;
//
//	// Se comparan los hijos izquierdo y derecho con la posición dada
//	// y se almacena el índice mayor
//	if (izq < tam && cola[izq] > cola[i]) {
//		tmp = izq;
//	}
//	else{
//		tmp = i;
//	}
//
//	if (der < tam && cola[der] > cola[tmp]) {
//		tmp = der;
//	}
//
//	// Si alguno de los hijos es más grande que la posición
//	// se intercambia la posición con el hijo mayor. El proceso continúa
//	// hacia abajo (bubble down - sift down)
//	if (tmp != i) {
//		Swap(i, tmp);
//		MaxHeapify(tmp);
//	}
//}
//
//// Intercambia una llave de mayor prioridad con su nodo padre
//// hasta que se mantenga la propiedad de Max Heap
//void ColaPrioridad::SiftUp(int i) {
//	int tmp = GetPadre(i);
//
//	// Bubble up - sift up
//	while (i > 0 && cola[tmp] < cola[i]) {
//		Swap(i, tmp);
//		i = tmp;
//		tmp = GetPadre(i);
//	}
//}
//
//void ColaPrioridad::ReasignarMemoria() {
//	int* tmp = cola;
//	
//	capacidad += 5;
//	cola = new int[capacidad];
//
//	for (int i = 0; i < tam; ++i) {
//		cola[i] = tmp[i];
//	}
//	delete[] tmp;
//}
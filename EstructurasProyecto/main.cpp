/*
Integrantes: 
	Pablo Jose Gatgens Chaves
	Joaquin Barrientos Monge
*/


#include <iostream>

#include "Control.h"

int main() {
	setlocale(LC_CTYPE, "Spanish");
	Control* c = new Control();

	return 0;
}

/*
https://www.faceprep.in/data-structures/applications-of-priority-queue/

Como bien se sabe los heaps, traducci�n de mont�culo al espa�ol, son estructuras de datos basadas en la figura de un �rbol.
Esta estructura resulta �til ya que representa la precedencia de los nodos de manera visual, donde se interpreta que entre m�s arriba del �rbol se
encuentre un nodo, m�s alta es su prioridad. Esto resulta muy �til ya que nos permite realizar algoritmos m�s eficientes que en el caso de que se manejara 
con una lista prioridad.

Dentro de los usos que se les puede dar a las colas de prioridad (que como requisito deber�an estar administradas por un heap) se encuentran lo que es el famoso
algoritmo de Dijkstra, por supuesto que tambi�n el los sistemas operativos para la administraci�n de tareas y procesos, y tambi�n en usos m�s ocultos como lo que son 
algoritmos de compresi�n basados en los c�digos de Huffman y en realidad hay much�simas aplicaciones m�s; se podr�a decir que todo lo que necesite alg�n tipo de 
prioirdad es partidadrio para ser administrado por un heap. 

Con todo este gran auge que est� teniendo la inteligencia artificial y el machine learning, conocer acerca de los heaps y las colas de prioridad es un fundamento b�sico que debe ser tomado
muy en cuenta. 
*/
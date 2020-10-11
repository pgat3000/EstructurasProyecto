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

Como bien se sabe los heaps, traducción de montículo al español, son estructuras de datos basadas en la figura de un árbol.
Esta estructura resulta útil ya que representa la precedencia de los nodos de manera visual, donde se interpreta que entre más arriba del árbol se
encuentre un nodo, más alta es su prioridad. Esto resulta muy útil ya que nos permite realizar algoritmos más eficientes que en el caso de que se manejara 
con una lista prioridad.

Dentro de los usos que se les puede dar a las colas de prioridad (que como requisito deberían estar administradas por un heap) se encuentran lo que es el famoso
algoritmo de Dijkstra, por supuesto que también el los sistemas operativos para la administración de tareas y procesos, y también en usos más ocultos como lo que son 
algoritmos de compresión basados en los códigos de Huffman y en realidad hay muchísimas aplicaciones más; se podría decir que todo lo que necesite algún tipo de 
prioirdad es partidadrio para ser administrado por un heap. 

Con todo este gran auge que está teniendo la inteligencia artificial y el machine learning, conocer acerca de los heaps y las colas de prioridad es un fundamento básico que debe ser tomado
muy en cuenta. 
*/
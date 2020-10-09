#pragma once
#include <iostream>
#include "Tareas.h"
#include "ColaPrioridad.h"
class Control {

private:
	ColaPrioridad<Tarea>* colaP;

public:
	Control();
	void menu();
	void crearTarea();
	void borrarTarea();
	void mostrarTareas();
};

Control::Control() {
	string type; bool flag = true; int op;
	cout << "\t\t.: HERRAMIENTA PARA ADMINISTRACIÓN DE TAREAS :.\n\n\n";
	cout << "\t ¿Cómo desea visualizar la lista de tareas? \n";
	cout << "\t Para: \n";
	cout << "\t   -> Orden ascendente, digite 1\n";
	cout << "\t   -> Orden descendente, digite 2\n";
	while (flag) {
		cout << "\n\t-> "; cin >> op;
		if (op == 1 || op == 2) {
			break;
		}
		else {
			cout << "\tDigite un valor correcto, por favor.";
		}
	}
	if (op == 1) {
		type = "min";
	}
	else {
		type = "max";
	}
	colaP = new ColaPrioridad<Tarea>(type);
	menu();
}

void Control::mostrarTareas() {
	system("cls");
	cout << "\t\t.: HERRAMIENTA PARA ADMINISTRACIÓN DE TAREAS :.\n\n\n";
	cout << "\t\t-> VISUALIZAR LISTA DE TAREAS\n\n";

	cout << colaP->toString() << "\n\n";
	cout << "\n\n\t\t Presione <ENTER> para regresar al menú\n";
	cin.get();
	cin.get();
	menu();


}
void Control::menu() {
	bool flag = true;
	int op;
	system("cls");
	cout << "\t\t.: HERRAMIENTA PARA ADMINISTRACIÓN DE TAREAS :.\n\n\n";
	cout << "\t\t-> MENÚ\n\n";
	cout << "\t\t1- Deseo crear e ingresar una tarea.\n\n";
	cout << "\t\t2- Eliminar una tarea ya entregada.\n\n";
	cout << "\t\t3- Visualizar la lista de tareas.\n\n";
	cout << "\t\t4- Salir del sistema.\n\n";

	cout << "\t\tDigite una opción\n";
	while (flag) {
		cout << "\n\t-> "; cin >> op;
		if (op > 0 && op < 5) {
			break;
		}
		else {
			cout << "\tDigite un valor correcto, por favor.";
		}
	}
	switch (op) {
		case 1: crearTarea(); break;
		case 2: borrarTarea(); break;
		case 3: mostrarTareas(); break;
		case 4: return;
	}
}

void Control::crearTarea() {
	string cur, desc;
	int d, m, val;
	system("cls");
	cout << "\t\t.: HERRAMIENTA PARA ADMINISTRACIÓN DE TAREAS :.\n\n\n";
	cout << "\t\t-> CREAR UNA TAREA\n\n";

	cout << "\t\t Digite el nombre del curso\n\t\t->";
	cin >> cur;
	cout << "\n\t\t Digite el una descripción de la tarea (ej. si es proyecto, tarea, quiz o examen)\n\t\t->";
	cin >> desc;
	cout << "\n\t\t Digite el valor que tiene esta evaluación en la nota final\n\t\t->";
	cin >> val;
	cout << "\n\t\t Escriba el número de mes de la entrga\n\t\t->";
	cin >> m;
	cout << "\n\t\t Escriba el número de día de la entrga\n\t\t->";
	cin >> d;
	Tarea* t = new Tarea(d, m, cur, desc, val);
	colaP->insertar(t);

	cout << "\t\tPuede consultar la lista de tareas actualizada en la opción 3 del menú.";
	cout << "\n\n\t\t Presione <ENTER> para regresar al menú\n";
	cin.get();
	cin.get();
	menu();
}

void Control::borrarTarea() {
	system("cls");
	cout << "\t\t.: HERRAMIENTA PARA ADMINISTRACIÓN DE TAREAS :.\n\n\n";
	cout << "\t\t-> BORRAR UNA TAREA\n\n";
	if(colaP->retornarHeap()->getLista()->EsVacia()){
		cout << "\t\tNo hay tareas para eliminar actualmente";
		cout << "\n\n\t\t Presione <ENTER> para regresar al menú\n";
		cin.get();
		cin.get();
		menu();
	}
	cout << "\t\tSe ha elimininado la tarea: " << colaP->eliminar()->toString() << " porque es la que tenía más prioridad\n\n";

	cout << "\t\tPuede, en la opción 3 del menú, ver la lista de tareas actualizada.";
	cout << "\n\n\t\t Presione <ENTER> para regresar al menú\n";
	cin.get();
	cin.get();
	menu();
}


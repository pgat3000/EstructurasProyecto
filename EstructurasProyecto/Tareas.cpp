#include "Tareas.h"
#include <sstream>
Tarea::Tarea() {
	dia = 0;
	mes = 0;
	nomb_curso = "";
	descrip = "";
	valor = 0.0;
}

Tarea::Tarea(int d, int m, string cur, string desc, double val) {
	this->dia = d;
	this->mes = m;
	this->nomb_curso = cur;
	this->descrip = desc;
	this->valor = val;
}

int Tarea::getDia() { return dia; }

int Tarea::getMes() { return mes; }

string Tarea::getCurso() { return nomb_curso; }

string Tarea::getDescrip() { return descrip; }
double Tarea::getValor() { return valor; }

void Tarea::setDia(int d) { dia = d; }
void Tarea::setMes(int m) { mes = m; }
void Tarea::setCurso(string c) { nomb_curso = c; }
void Tarea::setDescrip(string desc) { descrip = desc; }
void Tarea::setValor(double val) { valor = val; }
bool Tarea::operator==(Tarea& t) {
	return valor == t.getValor();

}
bool Tarea::operator>(Tarea& t) {
	return valor > t.getValor();
}
bool Tarea::operator<(Tarea& t) {
	return valor > t.getValor();
}
bool Tarea::operator>=(Tarea& t) {
	return valor >= t.getValor();
}
bool Tarea::operator<=(Tarea& t) {
	return valor <= t.getValor();
}

string Tarea::toString() {//mejor codigo
	stringstream s;
	s << getCurso() << endl;
	s << getValor() << endl;
	return s.str();
}
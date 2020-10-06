#include "Tareas.h"
#include <sstream>
Tarea::Tarea() {
	dia = 0;
	mes = 0;
	nomb_curso = "";
	descrip = "";
	valor = 0;
}

Tarea::Tarea(int d, int m, string cur, string desc, int val) {
	this->dia = d;
	this->mes = m;
	this->nomb_curso = cur;
	this->descrip = desc;
	this->valor = val;
}
Tarea::Tarea(const Tarea& t) {
	this->dia = t.dia;
	this->mes = t.mes;
	this->nomb_curso = t.nomb_curso;
	this->descrip = t.descrip;
	this->valor = t.valor;
}
int Tarea::getDia() { return dia; }

int Tarea::getMes() { return mes; }

string Tarea::getCurso() { return nomb_curso; }

string Tarea::getDescrip() { return descrip; }
int Tarea::getValor() { return valor; }

void Tarea::setDia(int d) { dia = d; }
void Tarea::setMes(int m) { mes = m; }
void Tarea::setCurso(string c) { nomb_curso = c; }
void Tarea::setDescrip(string desc) { descrip = desc; }
void Tarea::setValor(int val) { valor = val; }
bool Tarea::operator==(Tarea& t) {
	return valor == t.getValor();

}
bool Tarea::operator>(Tarea* t) {
	//cout << getValor() + "<" + t->getValor() << endl;
	if (valor >( t->getValor())) {
		return true;
	}
	else {
		return false;
	}
}
bool Tarea::operator<(Tarea* t) {
	return (valor < t->getValor());
}
bool Tarea::operator>=(Tarea& t) {
	return valor >= t.getValor();
}
bool Tarea::operator<=(Tarea& t) {
	return valor <= t.getValor();
}

string Tarea::toString() {//mejor codigo
	stringstream s;
	s << getCurso() << ": ";
	s << getValor() << endl;
	return s.str();
}
#include "tarea.h"

Tarea::Tarea() {
	this.dia = 0;
	this.mes = 0;
	this.nomb_curso = "";
	this.descrip = "";
	this.valor = 0.0
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

string getDescrip() { return }
double getValor();

void setDia(int);
void setMes(int);
void setCurso(string);
void setDescrip(string);
void setValor(double);
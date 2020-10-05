#pragma once
#include <string>
#include <iostream>
using namespace std;

class Tarea {
private:
	int dia;
	int mes;
	string nomb_curso;
	string descrip;
	int valor;
public:
	Tarea();
	Tarea(int, int, string, string, int);

	int getDia();
	int getMes();
	string getCurso();
	string getDescrip();
	int getValor();

	void setDia(int);
	void setMes(int);
	void setCurso(string);
	void setDescrip(string);
	void setValor(int);
	string toString();
	//operadores para comparar
	bool operator==(Tarea& t);
	bool operator>(Tarea*  );
	bool operator<(Tarea& t);
	bool operator>=(Tarea& t);
	bool operator<=(Tarea& t);
};
#include <string>

using namespace std;

class Tarea {
private:
	int dia;
	int mes;
	string nomb_curso;
	string descrip;
	double valor;
public:
	Tarea();
	Tarea(int, int string, string, double);

	int getDia();
	int getMes();
	string getCurso();
	string getDescrip();
	double getValor();

	void setDia(int);
	void setMes(int);
	void setCurso(string);
	void setDescrip(string);
	void setValor(double);

};
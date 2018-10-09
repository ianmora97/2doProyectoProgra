#ifndef TABLERO_H
#define TABLERO_H
#include "Herramientas.h"
using namespace std;
class Tablero : public Herramientas{
public:
	Tablero();
	void insertarFicha(int,char,string);
	void imprimeTablero();
	void imprimeScrabble();
	~Tablero();
protected:
	string **tablero;
	int fila, columna;
	int can, tam;
};
#endif // !TABLERO_H
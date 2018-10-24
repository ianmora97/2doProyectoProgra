#ifndef TABLERO_H
#define TABLERO_H
#include "Herramientas.h"
using namespace std;
class Tablero : public Herramientas{
public:
	Tablero();
	bool insertarFicha(int,char,string);
	void imprimeTablero();
	void imprimeScrabble();
	string getTablero();
	~Tablero();
private:
	string **tablero;
	bool matrizBoleana[15][15];
	int fila, columna;
	int can, tam;
};
#endif // !TABLERO_H
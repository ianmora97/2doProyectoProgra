#ifndef TABLERO_H
#define TABLERO_H
#include "Herramientas.h"
using namespace std;
class Tablero : public Herramientas{
public:
	Tablero();
	void insertarFicha(int,int,string);
	void imprimeTablero();
	void imprimeScrabble();
	bool verificaPosicion(string palabra);
	string getTablero();
	~Tablero();
private:
	string **tablero;
	int matrizValores[15][15];
	int fila, columna;
	int can, tam;
};
#endif // !TABLERO_H
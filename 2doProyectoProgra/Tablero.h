#ifndef TABLERO_H
#define TABLERO_H
#include "Herramientas.h"
using namespace std;
class Tablero{
public:
	Tablero();
	void insertarFicha(int,int,string);
	void imprimeTablero();
	void imprimeScrabble();
	bool verificaPosicion(int x, int y);
	bool verificarCruz(int i, int j);
	int valores(int f,int c);
	int bono(int f[],int c[], string l[], int cant);
	void imprimeTableroValores();
	string getTablero();
	~Tablero();
private:
	string **tablero;
	int matrizValores[15][15];
	int matrizBoleana[15][15];
	int fila, columna;
	int can, tam;
};
#endif // !TABLERO_H
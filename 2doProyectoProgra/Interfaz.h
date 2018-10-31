#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Herramientas.h"
using namespace std;
class Interfaz {
public:
	Interfaz();
	int menu();
	void imprime();
	int validar();
	void cuadros();
	~Interfaz();
};
#endif // !INTERFAZ_H
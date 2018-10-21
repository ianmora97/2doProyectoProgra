#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Herramientas.h"
using namespace std;
class Interfaz : public Herramientas{
public:
	Interfaz();
	int menu();
	void imprime();
	int validar();
	~Interfaz();
};
#endif // !INTERFAZ_H
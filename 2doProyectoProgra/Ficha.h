#ifndef FICHA_H
#define FICHA_H
#include "Herramientas.h"
using namespace std;

class Ficha : public Herramientas{
protected:
	string letra;
	int valor;
public:
	Ficha(string = "indef", int = 0);
	string getLetra();
	int getValor();
	void setLetra(string);
	void setValor(int);
	string toString();
	~Ficha();
};
#endif // !FICHA_H
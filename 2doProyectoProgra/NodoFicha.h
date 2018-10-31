#ifndef NODOFICHA_H
#define NODOFICHA_H
#include "Ficha.h"
using namespace std;

class NodoFicha{
private:
	Ficha *ficha;
	NodoFicha *sig;
public:
	NodoFicha(Ficha *ficha, NodoFicha *sig);
	Ficha *getFicha();
	NodoFicha *getSig();
	void setSig(NodoFicha* sig);
	void setFicha(Ficha* ficha);
	string toString();
	~NodoFicha();
};
#endif // !NODOFICHA_H
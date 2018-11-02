#ifndef NODODICCIONARIO_H
#define NODODICCIONARIO_H
#include "Herramientas.h"
using namespace std;
class NodoPalabra{
private:
	string palabra;
	NodoPalabra* sig;
public:
	NodoPalabra(string, NodoPalabra*);
	string getPalabra();
	NodoPalabra* getSig();
	void setSig(NodoPalabra*);
	void setPalabra(string);
	~NodoPalabra();
};
#endif // !NODODICCIONARIO_H
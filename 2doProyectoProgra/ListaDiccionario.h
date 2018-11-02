#ifndef LISTADICCIONARIO_H
#define LISTADICCIONARIO_H
#include "Herramientas.h"
#include "NodoDiccionario.h"
using namespace std;
class Diccionario {
private:
	NodoPalabra* primero;
	NodoPalabra* actual;
	int cant;
public:
	Diccionario();
	bool vacia();
	void insertar(string palabra);
	bool encontrada(string palabra);
	int getCant();
	void fillDicionario();
	string toString();
	~Diccionario();
};
#endif // !LISTADICCIONARIO_H
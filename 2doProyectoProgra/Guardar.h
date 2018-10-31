#ifndef LISTA_H
#define LISTA_H
#include "Jugador.h"
class nodo;
class lista{
private:
	nodo *primero;
	nodo * actual;
public:
	lista();
	void insertarOrdenado(Jugador*);
	bool eliminaInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	~lista();
};
class nodo{
private:
	Jugador*  info;
	nodo * sig;
public:
	nodo(Jugador*, nodo*);
	~nodo();
	void setInfo(Jugador*);
	Jugador* getInfo();
	void setSig(nodo*);
	nodo* getSig();
	string toStringNodo();
};
#endif
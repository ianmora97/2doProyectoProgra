#include "Guardar.h"

lista::lista() {
	primero = NULL;
	actual = NULL;

}

void lista::insertarOrdenado(Jugador* e) {
	actual = primero;

	if (primero == NULL || primero->getInfo()->getCantidadDeVictorias() < e->getCantidadDeVictorias())// si va al primero
	{
		primero = new nodo(e, primero);
	}
	else
	{      //Buscar el lugar que le corresponde al nodo
		while ((actual->getSig() != NULL) && (actual->getSig()->getInfo()->getCantidadDeVictorias() < e->getCantidadDeVictorias()))
		{
			actual = actual->getSig();
		}
		nodo * nuevo = new nodo(e, actual->getSig());
		actual->setSig(nuevo);
	}
}

string lista::toString() {
	actual = primero;
	stringstream s;
	while (actual != NULL)
	{
		s << actual->toStringNodo();
		actual = actual->getSig();
	}

	return s.str();
}

int lista::cuentaNodos() {
	actual = primero;
	int can = 0;
	while (actual != NULL)
	{
		can++;
		actual = actual->getSig();
	}
	return can;
}


bool lista::listaVacia() {
	return  (primero == NULL) ? true : false;
}

bool lista::eliminaInicio() {
	if (primero == NULL)  // caso 1: la lista esta vacia
	{
		return false;
	}
	else // caso 2: la lista no esta vacia
	{
		actual = primero;
		primero = primero->getSig();
		delete actual;
		return true;
	}
}

lista::~lista() {
	while (!listaVacia())
	{
		eliminaInicio();
	}
}


nodo::nodo(Jugador*  e, nodo* s) {
	info = e;
	sig = s;
}

nodo:: ~nodo() {}
void nodo::setInfo(Jugador* e) { info = e; }
Jugador*  nodo::getInfo() { return info; }
void nodo::setSig(nodo* s) { sig = s; }
nodo* nodo::getSig() { return sig; }

string nodo::toStringNodo() {
	return  info->toString();
}

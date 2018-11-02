#include "ListaDiccionario.h"
Diccionario::Diccionario() : primero(NULL),actual(NULL), cant(0){}
bool Diccionario::vacia() { return (primero == NULL); }
void Diccionario::insertar(string palabra){ //siempre inserta al principio
	palabra = toUpper(palabra);
	NodoPalabra* aux = new NodoPalabra(palabra, NULL);
	actual = primero;
	if (vacia()) {
		primero = aux;
		cant++;
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(aux);
		cant++;
	}
}
bool Diccionario::encontrada(string palabra){
	actual = primero;
	while (actual != NULL) {
		if (actual->getPalabra() == palabra) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}
int Diccionario::getCant() { return cant; }
void Diccionario::fillDicionario() {
}
string Diccionario::toString() {
	int cont = 1;
	stringstream p;
	actual = primero;
	while (actual != NULL) {
		p << "Palabra " << cont << " -> " << actual->getPalabra() << endl;
		actual = actual->getSig();
		cont++;
	}
	return p.str();
}
Diccionario::~Diccionario(){}

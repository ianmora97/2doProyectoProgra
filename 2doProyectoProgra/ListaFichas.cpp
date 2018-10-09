#include "ListaFichas.h"
ListaFichas::ListaFichas() : primero(NULL), actual(NULL){}
void ListaFichas::insertarFicha(Ficha * ficha){
	NodoFicha *aux = new NodoFicha(ficha, NULL);
	actual = primero;
	if (vacia()) {
		primero = aux;
	}
	else {
		while (actual->getSig() != NULL) { //recorre hasta null ( recorre hasta el ultimo nodo )
			actual = actual->getSig();
		}
		actual->setSig(aux);
	}
}
bool ListaFichas::sacarFicha(string letra){ //metodo como el de eliminar pero busca primero
	if (!vacia()) {
		NodoFicha *anterior = NULL;
		actual = primero;
		while ((actual != NULL) && (encotrada(letra) == true)) {
			anterior = actual;
			actual = actual->getSig();
		}
		if (actual == NULL) { //si la lista esta vacia
			color(12); cout << "La ficha no se encuentra en la bolsa de fichas" << endl; color(15);
			return false;
		}
		else if (anterior == NULL) { //si el elemento es el primero
			primero = primero->getSig();
			delete actual;
			return true;
		}
		else { //si el elemento se encuentra en la lista
			anterior->setSig(actual->getSig());
			delete actual;
			return true;
		}
	}
	else {
		return false;
	}
}
bool ListaFichas::encotrada(string letra){ //busca una ficha y retorna true si la encontro : false
	NodoFicha* aux = primero;
	aux = primero;
	while (aux != NULL) {
		if (aux->getFicha()->getLetra() == letra)
			return true;
		aux = aux->getSig();
	}
	return false;
}
bool ListaFichas::vacia() { return (primero == NULL); }
int ListaFichas::cantidadFichas(){
	int can = 0;
	actual = primero;
	while (actual != NULL) {
		can++;
		actual = actual->getSig();
	}
	return can;
}
string ListaFichas::toString() {
	stringstream p;
	actual = primero;
	while (actual != NULL) {
		p << actual->toString()<<endl;
		actual = actual->getSig();
	}
	return p.str();
}
ListaFichas::~ListaFichas(){}

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
		NodoFicha *aux = primero;
		actual = primero;
		while ((aux != NULL) && aux->getFicha()->getLetra() != letra ) {
			anterior = aux;
			aux = aux->getSig();
		}
		if (aux == NULL) { //si la lista esta vacia
			return false;
		}
		else if (anterior == NULL) { //si el elemento es el primero
			primero = primero->getSig();
			delete aux;
			return true;
		}
		else { //si el elemento se encuentra en la lista
			anterior->setSig(aux->getSig());
			delete aux;
			return true;
		}
	}
	else {
		return false;
	}
}
bool ListaFichas::encotrada(string letra){ //busca una ficha y retorna true si la encontro : false
	actual = primero;
	while (actual != NULL) {
		if (actual->getFicha()->getLetra() == letra) {
			return true;
		}
		actual = actual->getSig();
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
string ListaFichas::toStringLetra() {
	stringstream p;
	actual = primero;
	while (actual != NULL) {
		p << "  " << actual->getFicha()->getLetra() << "  ";
		actual = actual->getSig();
	}
	return p.str();
}
string ListaFichas::toStringValor() {
	stringstream p;
	actual = primero;
	while (actual != NULL) {
		p << "  " << actual->getFicha()->getValor() << "  ";
		actual = actual->getSig();
	}
	return p.str();
}
bool ListaFichas::limpiarLista() {
	actual = primero;
	if (vacia()) {
		return false;
	}
	else {
		if (primero->getSig() == NULL) {
			delete primero;
			primero = NULL;
		}
		else {
			while (actual->getSig()->getSig() != NULL) {
				actual = actual->getSig();
			}
			delete actual->getSig();
			actual->setSig(NULL);
		}
		return true;
	}
}
ListaFichas::~ListaFichas(){
	while (!(vacia())) {
		limpiarLista();
	}
}

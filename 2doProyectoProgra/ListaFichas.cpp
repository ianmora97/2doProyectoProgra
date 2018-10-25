#include "ListaFichas.h"
ListaFichas::ListaFichas() : primero(NULL), actual(NULL), cantidadNodos(0){}
void ListaFichas::insertarFicha(Ficha * ficha){
	NodoFicha *aux = new NodoFicha(ficha, NULL);
	actual = primero;
	if (vacia()) {
		primero = aux;
		sumaNodo();
	}
	else {
		while (actual->getSig() != NULL) { //recorre hasta null ( recorre hasta el ultimo nodo )
			actual = actual->getSig();
		}
		actual->setSig(aux);
		sumaNodo();
	}
}
bool ListaFichas::sacarFicha(string letra){ //metodo como el de eliminar pero busca primero
	if (!vacia()) {
		NodoFicha *anterior = NULL;
		NodoFicha *aux = primero;
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
void ListaFichas::getLetras() {
	string letra;
	color(34);
	gotoxy(9, 23); cout << "                                      ";
	gotoxy(9, 24); cout << "                                      ";
	gotoxy(9, 25); cout << "                                      ";
	gotoxy(9, 26); cout << "               "; color(47); cout << "Scrabble"; color(34);cout<<"               ";
	color(15);
	actual = primero;
	int cont = 0;
	while (actual != NULL) {
		letra = actual->getFicha()->getLetra();
		if (letra == "CH" || letra == "LL" || letra == "RR") {
			gotoxy(11 + (cont * 5), 24); color(243); cout << " " << actual->getFicha()->getLetra() << " ";
			gotoxy(11 + (cont * 5), 25); color(243); cout << " " << actual->getFicha()->getValor() << "  ";
		}
		else {
			gotoxy(11 + (cont * 5), 24); color(243); cout << " " << actual->getFicha()->getLetra() << "  ";
			gotoxy(11 + (cont * 5), 25); color(243); cout << " " << actual->getFicha()->getValor() << "  ";
		}
		
		actual = actual->getSig();
		cont++;
	}
	color(15);
}
int ListaFichas::getCantidadNodos() { return cantidadNodos; }
void ListaFichas::sumaNodo() {cantidadNodos++;}
ListaFichas::~ListaFichas(){
	while (!(vacia())) {
		limpiarLista();
	}
}

#include "NodoFicha.h"
NodoFicha::NodoFicha(Ficha * ficha, NodoFicha * sig) : ficha(ficha), sig(sig){}
Ficha * NodoFicha::getFicha() { return ficha; }
NodoFicha * NodoFicha::getSig() { return sig; }
void NodoFicha::setSig(NodoFicha * sig) { this->sig = sig; }
void NodoFicha::setFicha(Ficha * ficha) { this->ficha = ficha; }
string NodoFicha::toString(){
	stringstream p;
	p << ficha->toString() << endl;
	return p.str();
}
NodoFicha::~NodoFicha(){}

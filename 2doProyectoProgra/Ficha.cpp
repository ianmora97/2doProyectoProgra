#include "Ficha.h"
Ficha::Ficha(string letra, int valor) : letra(letra), valor(valor){}
string Ficha::getLetra() { return letra; }
int Ficha::getValor() { return valor; }
void Ficha::setLetra(string letra) { this->letra = letra; }
void Ficha::setValor(int valor) { this->valor = valor; }
string Ficha::toString(){
	stringstream p;
	p << "Letra: " << letra << endl;
	p << "Valor: " << valor << endl;
	return p.str();
}
Ficha::~Ficha(){}

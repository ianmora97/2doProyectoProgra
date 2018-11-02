#include "NodoDiccionario.h"
NodoPalabra::NodoPalabra(string palabra, NodoPalabra* sig) : palabra(palabra), sig(sig) {}
string NodoPalabra::getPalabra() { return palabra; }
NodoPalabra * NodoPalabra::getSig() { return sig; }
void NodoPalabra::setSig(NodoPalabra * sig) { this->sig = sig; }
void NodoPalabra::setPalabra(string palabra) { this->palabra = palabra; }
NodoPalabra::~NodoPalabra() {}

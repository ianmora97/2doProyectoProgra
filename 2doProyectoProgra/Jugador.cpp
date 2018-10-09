#include "Jugador.h"
Jugador::Jugador(string nombre) : nombreJugador(nombre), canFichas(0), puntajeJugador(0) { listaFichas = new ListaFichas; }
string Jugador::getNombre() {return nombreJugador;}
int Jugador::getPuntaje() {return puntajeJugador;}
int Jugador::getCanFichas(){return canFichas;}
void Jugador::setPuntaje(int p) {puntajeJugador = puntajeJugador + p;}
void Jugador::setNombre(string nombre) { nombreJugador = nombre; }
void Jugador::insertarficha(Ficha * ficha){listaFichas->insertarFicha(ficha);}
void Jugador::getFichas() {  cout << listaFichas->toString() << endl; }
string Jugador::toString() {
	stringstream s;
	s << "Nombre del Jugador: " << nombreJugador << endl;
	s << "Puntaje del Jugador: " << puntajeJugador << endl;
	s << "Cantidad de Fichas: " << canFichas << endl;
	return s.str();
}
void Jugador::guardarPuntaje() {
	string nombreArchivo;
	nombreArchivo = (nombreJugador + "Puntaje"+".txt");
	//seguir desde aqui
}
Jugador::~Jugador()
{
}

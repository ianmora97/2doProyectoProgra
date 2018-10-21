#include "Jugador.h"
Jugador::Jugador(string nombre) : nombreJugador(nombre), canFichas(0), puntajeJugador(0) { listaFichas = new ListaFichas; }
string Jugador::getNombre() {return nombreJugador;}
int Jugador::getPuntaje() {return puntajeJugador;}
int Jugador::getCanFichas(){return canFichas;}
void Jugador::setPuntaje(int p) {puntajeJugador = puntajeJugador + p;}
void Jugador::setNombre(string nombre) { nombreJugador = nombre; }
void Jugador::insertarficha(Ficha * ficha) { listaFichas->insertarFicha(ficha); canFichas++; }
void Jugador::cuadroFichas() {
	color(11); gotoxy(67, 4); cout << "Fichas:"; color(15);
	color(11); gotoxy(67, 6); cout << "Letra:"; color(15);
	color(243); gotoxy(74, 6); cout << listaFichas->toStringLetra(); color(15);
	color(11); gotoxy(67, 7); cout << "Valor:"; color(15);
	color(243); gotoxy(74, 7); cout << listaFichas->toStringValor(); color(15);
}
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
	ofstream archivo;
	archivo.open(nombreArchivo.c_str(), ios::out);
	if (archivo.is_open()) {
		archivo << "Puntaje del jugador:" << endl << getPuntaje() << endl;
	}
	else {
		color(12); cout << "Error al abrir el archivo!" << endl; color(12);
	}
	archivo.close();
}
string Jugador::sacarPuntaje() {
	string nombreArchivo;
	string texto;
	nombreArchivo = (nombreJugador + "Puntaje" + ".txt");
	ifstream archivo;
	archivo.open(nombreArchivo.c_str(), ios::in);
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			getline(archivo,texto);
		}
	}
	else {
		color(12); cout << "Error al abrir el archivo!" << endl; color(12);
	}
	return texto;
}
ListaFichas * Jugador::getLista() { return listaFichas; }
Jugador::~Jugador(){
	listaFichas->~ListaFichas();
	nombreJugador = "indef";
	puntajeJugador = 0;
	canFichas = 0;
}

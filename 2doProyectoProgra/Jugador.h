#ifndef JUGADOR_H
#define JUGADOR_H
#include "ListaFichas.h"
using namespace std;
class Jugador {
private:
	string nombreJugador;
	ListaFichas *listaFichas;
	int puntajeJugador;
	int canFichas;
	int cantidadDeVictorias;
public:
	Jugador(string);
	string getNombre();
	int getPuntaje();
	int getCanFichas();
	int getCantidadDeVictorias();
	void setCantidadDeVictorias(int);
	void setPuntaje(int);
	void setNombre(string);
	void insertarficha(Ficha *ficha);
	bool sacarFicha(string);
	void turnoJugador();
	ListaFichas *getLista();
	void cambiarFichas(ListaFichas*);
	string toString();
	string toStringLetras();
	void autoGuardar(ofstream&);
	~Jugador();
};

#endif // !JUGADOR_H
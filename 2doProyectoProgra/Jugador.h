#ifndef JUGADOR_H
#define JUGADOR_H
#include "ListaFichas.h"
using namespace std;
class Jugador : public Herramientas {
private:
	string nombreJugador;
	ListaFichas *listaFichas;
	int puntajeJugador;
	int canFichas;
public:
	Jugador(string);
	string getNombre();
	int getPuntaje();
	int getCanFichas();
	void setPuntaje(int);
	void setNombre(string);
	void insertarficha(Ficha *ficha);
	void sacarFicha(string);
	void guardarPuntaje();
	string sacarPuntaje();
	ListaFichas *getLista();
	string toString();
	~Jugador();
};

#endif // !JUGADOR_H
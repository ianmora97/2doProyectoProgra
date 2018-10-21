#include "Control.h"
Control::Control(){}
void Control::opciones() {
	color(15);
	Interfaz *interfaz = new Interfaz;
	ListaFichas *bolsaFichas = new ListaFichas;
	Tablero *tablero = new Tablero;
	ListaFichas *listaTablero = new ListaFichas;

	//---Variables de ciclos---
	bool menuCiclo = true;

	//---!Variables de ciclos---
	//---Variables de jugadores---
	string nombreJugador;
	Jugador *jugador1 = new Jugador("indef");
	Jugador *jugador2 = new Jugador("indef");
	Jugador *jugador3 = new Jugador("indef");
	Jugador *jugador4 = new Jugador("indef");
	Ficha *ficha;
	//---!Variables de jugadores---
	
	//--Variables contadores--
	


}
void Control::leeFichas() {}
Control::~Control(){}

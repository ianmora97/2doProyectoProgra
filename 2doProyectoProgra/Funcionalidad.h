#ifndef FUNCIONALIDAD_H
#include "Herramientas.h"
#include "ListaFichas.h"
#include "Jugador.h"
#include "Tablero.h"
using namespace std;
class Funcionalidad{
public:
	Funcionalidad();
	bool getPasar();
	bool getTerminar();
	void setPasar(bool);
	void setTerminar(bool);
	bool llenarLista(ListaFichas*);
	void setJugador(Jugador*,ListaFichas*,int);
	void setCantidadJugadores();
	int menu();
	void jugar(Jugador*, ListaFichas*, int, Tablero*, ListaFichas*);
	~Funcionalidad();
private:
	bool pasar;
	bool terminar;
};
#endif // !FUNCIONALIDAD_H
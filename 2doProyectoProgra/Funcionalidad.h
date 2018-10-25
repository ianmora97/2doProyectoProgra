#ifndef FUNCIONALIDAD_H
#include "Herramientas.h"
#include "ListaFichas.h"
#include "Jugador.h"
#include "Tablero.h"
#define END '\n'
#define TAB '\t'
using namespace std;
class Funcionalidad{
public:
	Funcionalidad();
	bool llenarLista(ListaFichas*);
	void setJugador(Jugador*,ListaFichas*,int);
	void setCantidadJugadores();
	bool verificaLetras(Jugador*,string);
	bool ingresarTableroFichas(Jugador*, ListaFichas*);
	int menu();
	~Funcionalidad();
};
#endif // !FUNCIONALIDAD_H
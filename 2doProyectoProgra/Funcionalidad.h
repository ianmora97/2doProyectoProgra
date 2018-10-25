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
	bool ingresarPalabra(Tablero*t ,string palabra, int f, char c, bool hv,Jugador *j, ListaFichas *l);
	bool horiVert();
	string pidePalabra();
	int menu();
	~Funcionalidad();
};
#endif // !FUNCIONALIDAD_H
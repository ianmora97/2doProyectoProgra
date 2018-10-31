#ifndef FUNCIONALIDAD_H
#include "Herramientas.h"
#include "ListaFichas.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Diccionario.h"
#include "Guardar.h"
#define END '\n'
#define TAB '\t'
using namespace std;
class Funcionalidad{
public:
	Funcionalidad();
	bool llenarLista(ListaFichas*);
	void setJugador(Jugador*,ListaFichas*,int);
	void setCantidadJugadores();
	bool meteFichas(Jugador*,ListaFichas*,int);
	bool verificaLetras(Jugador*,string);
	bool verificaDiccionario(Diccionario*, string palabra);
	bool ingresarPalabra(Tablero*t ,string palabra, int f, char c, bool hv,Jugador *j, ListaFichas *l);
	bool ingresarFichaXFicha(Tablero* t,ListaFichas* bolsa, ListaFichas *listaTablero, Jugador* j,Diccionario *dic);
	bool horiVert();
	bool verificaLetrasTablero(ListaFichas* l, string palabra);
	bool verificaCampoEMatriz(Tablero *tablero);
	void guardarPuntaje(Jugador*);
	void leerPuntaje();
	void ganador(Jugador* j1, Jugador* j2, Jugador* j3, Jugador* j4);
	string pidePalabra();
	int menu();
	~Funcionalidad();
};
#endif // !FUNCIONALIDAD_H
#ifndef CONTROL_H
#define CONTROL_H
#include "Herramientas.h"
#include "Interfaz.h"
#include "ListaFichas.h"
#include "Jugador.h"
#include "Tablero.h"
using namespace std;
class Control : public Herramientas{
public:
	Control();
	void opciones();
	void leeFichas();
	~Control();
};
#endif // !CONTROL_H
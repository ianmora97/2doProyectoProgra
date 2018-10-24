#ifndef CONTROL_H
#define CONTROL_H
#include "Herramientas.h"
#include "Funcionalidad.h"
#include "Interfaz.h"
using namespace std;
class Control : public Herramientas {
public:
	Control();
	void opciones();
	~Control();
};
#endif // !CONTROL_H
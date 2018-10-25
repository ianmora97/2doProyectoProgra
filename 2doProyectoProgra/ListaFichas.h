#ifndef LISTAFICHA_H
#define LISTAFICHA_H
#include "NodoFicha.h"
using namespace std;

class ListaFichas : public Herramientas{
private:
	NodoFicha *primero;
	NodoFicha *actual;
	int cantidadNodos;
public:
	ListaFichas();
	void insertarFicha(Ficha* ficha); //metodo de insertar al final
	bool sacarFicha(string letra); //metodo de eliminar
	bool encotrada(string letra);
	bool vacia();
	int cantidadFichas();
	int getCantidadNodos();
	void sumaNodo();
	string toString();
	void getLetras();
	bool limpiarLista();
	~ListaFichas();
};
#endif // !LISTAFICHA_H
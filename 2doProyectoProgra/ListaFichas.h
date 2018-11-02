#ifndef LISTAFICHA_H
#define LISTAFICHA_H
#include "NodoFicha.h"
using namespace std;

class ListaFichas{
private:
	NodoFicha *primero;
	NodoFicha *actual;
	int cantidadNodos;
public:
	ListaFichas();
	void insertarFicha(Ficha* ficha); //metodo de insertar al final
	bool sacarFicha(string letra);    //metodo de eliminar
	bool encotrada(string letra);
	bool vacia();
	int cantidadFichas();
	int getCantidadNodos();
	void sumaNodo();
	string toString();
	string letras();
	void getLetras();
	bool limpiarLista();
	~ListaFichas();
};
#endif // !LISTAFICHA_H
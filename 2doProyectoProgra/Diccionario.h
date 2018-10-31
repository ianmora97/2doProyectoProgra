#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#define FIN '/'
#define ENDL '\n'
#define TAB '\t'
#include "Herramientas.h"
class Diccionario{
private:
	string *palabra;
	int cont;
	int tam;
public:
	Diccionario();
	void readFile();
	string showVec();
	string getPalabra(int i);
	int getCantidadPalabras();
	~Diccionario();
};
#endif // !DICCIONARIO_H
#include "Tablero.h"
using namespace std;
int main() {
	Tablero * tablero = new Tablero;
	tablero->imprimeTablero();
	delete tablero;
	system("PAUSE");
	return 0;
};
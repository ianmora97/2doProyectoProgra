#include "Control.h"
using namespace std;
int main() {
	SetConsoleTitleA("Scrabble Game - Proyecto de Programacion 1");
	system("mode con: cols=110 lines=40");
	Control *c = new Control;
	c->opciones();
	cin.get();
	return 0;
};
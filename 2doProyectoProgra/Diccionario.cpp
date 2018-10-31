#include "Diccionario.h"
Diccionario::Diccionario(){
	tam = 100550;
	cont = 0;
	palabra = new string[tam];
	
}
void Diccionario::readFile() {
	color(15); gotoxy(46, 20); cout << "Cargando...";
	string w;
	ifstream file;
	file.open("Diccionario/diccionario.txt", ios::in);
	if (file.is_open()) {
		gotoxy(30, 21); color(255); cout << "     ";
		Sleep(500);
		while (!(file.eof())) {
			getline(file,w,FIN);
			palabra[cont] = toUpper(w);
			cont++;
		}
	}
	gotoxy(35, 21); color(255); cout << "  ";
	file.close();
	file.open("Diccionario/diccionario2.txt", ios::in);
	if (file.is_open()) {
		while (!(file.eof())) {
			getline(file, w, ENDL);
			palabra[cont] = w;
			cont++;
		}
	}
	gotoxy(37, 21); color(255); cout << "         ";
	file.close();
	file.open("Diccionario/diccionario3.txt", ios::in);
	if (file.is_open()) {
		while (!(file.eof())) {
			getline(file, w, ENDL);
			palabra[cont] = toUpper(w);
			cont++;
		}
	}
	gotoxy(46, 21); color(255); cout << "                 ";
	file.close();
	file.open("Diccionario/diccionarioVerbos.txt", ios::in);
	if (file.is_open()) {
		while (!(file.eof())) {
			getline(file, w, ENDL);
			palabra[cont] = toUpper(w);
			cont++;
		}
	}
	file.close();
	gotoxy(63, 21); color(255); cout << "           ";
	Sleep(500);
	color(15);
}
string Diccionario::showVec() {
	stringstream p;
	for (int i = 0; i < cont; i++) {
		p <<i<<" -> "<< palabra[i] << endl;
	}
	return p.str();
}
string Diccionario::getPalabra(int i) {
	return palabra[i];
}
int Diccionario::getCantidadPalabras() { return cont; }
Diccionario::~Diccionario(){}

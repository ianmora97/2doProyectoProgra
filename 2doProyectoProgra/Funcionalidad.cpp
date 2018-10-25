#include "Funcionalidad.h"
Funcionalidad::Funcionalidad(){}
bool Funcionalidad::llenarLista(ListaFichas *l) {
	ifstream archivo; //lectura
	string texto;
	string nombre("Fichas/fichas.txt");
	archivo.open(nombre.c_str(), ios::in);
	Ficha *ficha;
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			archivo >> texto;
			ficha = new Ficha(texto, Herramientas::valorFicha(texto));
			l->insertarFicha(ficha);
		}
		return true;
	}
	else {
		cout << "Error al abrir el archivo: " << nombre << endl;
		return false;
	}
	archivo.close();
}
void Funcionalidad::setJugador(Jugador *j, ListaFichas *l, int jugador) {
	string _letra;
	string _nombreJugador;
	Ficha *ficha;
	cout << "\n\n\tDigite el nombre del jugador " << jugador << " > ";
	Herramientas::color(11);
	getline(cin, _nombreJugador);
	Herramientas::color(15);
	j->setNombre(_nombreJugador);
	for (int i = 0; i < 7; i++) {
		_letra = Herramientas::randomFichas();
		if (l->sacarFicha(_letra)) {
			ficha = new Ficha(_letra, Herramientas::valorFicha(_letra));
			j->insertarficha(ficha);
		}
		else {
			i--;
		}
	}
	if (jugador == 1) {
		for (int i = 0; i < 4; i++) {
			Herramientas::gotoxy(55, 6 + i); Herramientas::color(15); cout << "|";
		}
		Herramientas::gotoxy(56, 6); Herramientas::color(13); cout << "Fichas:";
		Herramientas::gotoxy(56, 7); Herramientas::color(15); cout << "  " << j->getCanFichas();
		Herramientas::gotoxy(56, 8); Herramientas::color(13); cout << "Puntaje:";
		Herramientas::gotoxy(56, 9); Herramientas::color(15); cout << "  " << j->getPuntaje();
	}
	if (jugador == 2) {
		for (int i = 0; i < 4; i++) {
			Herramientas::gotoxy(55, 11 + i); Herramientas::color(15); cout << "|";
		}
		Herramientas::gotoxy(56, 11); Herramientas::color(13); cout << "Fichas:";
		Herramientas::gotoxy(56, 12); Herramientas::color(15); cout << "  " << j->getCanFichas();
		Herramientas::gotoxy(56, 13); Herramientas::color(13); cout << "Puntaje:";
		Herramientas::gotoxy(56, 14); Herramientas::color(15); cout << "  " << j->getPuntaje();
	}
	if (jugador == 3) {
		for (int i = 0; i < 4; i++) {
			Herramientas::gotoxy(55, 16 + i); Herramientas::color(15); cout << "|";
		}
		Herramientas::gotoxy(56, 16); Herramientas::color(13); cout << "Fichas:";
		Herramientas::gotoxy(56, 17); Herramientas::color(15); cout << "  " << j->getCanFichas();
		Herramientas::gotoxy(56, 18); Herramientas::color(13); cout << "Puntaje:";
		Herramientas::gotoxy(56, 19); Herramientas::color(15); cout << "  " << j->getPuntaje();
	}
	if (jugador == 4) {
		for (int i = 0; i < 4; i++) {
			Herramientas::gotoxy(55, 21 + i); Herramientas::color(15); cout << "|";
		}
		Herramientas::gotoxy(56, 21); Herramientas::color(13); cout << "Fichas:";
		Herramientas::gotoxy(56, 22); Herramientas::color(15); cout << "  " << j->getCanFichas();
		Herramientas::gotoxy(56, 23); Herramientas::color(13); cout << "Puntaje:";
		Herramientas::gotoxy(56, 24); Herramientas::color(15); cout << "  " << j->getPuntaje();
	}
}
void Funcionalidad::setCantidadJugadores() {
	system("cls");
	cout << "\n\n";
	cout << "\tCuantos jugadores desean jugar? ";
	Herramientas::color(11); cout << "[min -> 2 || max -> 4]"; Herramientas::color(15);
}
int Funcionalidad::menu() {
	Herramientas::gotoxy(74, 9); Herramientas::color(13); cout << "Que desea hacer?";
	Herramientas::gotoxy(74, 10); Herramientas::color(13); cout << "[1] Jugar";
	Herramientas::gotoxy(74, 11); Herramientas::color(13); cout << "[2] Pasar Turno";
	Herramientas::gotoxy(74, 12); Herramientas::color(13); cout << "[3] Terminar Juego";
	Herramientas::color(15);
	Herramientas::gotoxy(72, 7); cout << char(201); for (int i = 0; i < 20; i++) { cout << char(205); } cout << char(187);
	for (int i = 0; i < 8; i++) { Herramientas::gotoxy(72, 8 + i); cout << char(186); Herramientas::gotoxy(93, 8 + i); cout << char(186); }
	Herramientas::gotoxy(72, 16); cout << char(200); for (int i = 0; i < 20; i++) { cout << char(205); } cout << char(188);
	int opc;
	Herramientas::color(13); Herramientas::gotoxy(74, 14); opc = Herramientas::evaluarInt(3, 1);
	return opc;
}
bool Funcionalidad::verificaLetras(Jugador* j,string palabra) {
	int lenPalabra;
	lenPalabra = palabra.length();
	palabra = Herramientas::toUpper(palabra);
	int cont=0;
	char c;
	for (int i = 0; i < lenPalabra; i++) {
		c = palabra[i];
		if (j->getLista()->encotrada(Herramientas::convierteString(c))) {
			cont++;
		}
	}
	if (cont == lenPalabra) {
		return true;
	}
	else {
		return false;
	}
}
bool Funcionalidad::ingresarTableroFichas(Jugador *j, ListaFichas *l){

	return false;
}
Funcionalidad::~Funcionalidad(){}
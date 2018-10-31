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
			ficha = new Ficha(texto, valorFicha(texto));
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
	color(13);
	getline(cin, _nombreJugador);
	color(15);
	j->setNombre(_nombreJugador);
	for (int i = 0; i < 7; i++) {
		_letra = randomFichas();
		if (l->sacarFicha(_letra)) {
			ficha = new Ficha(_letra,valorFicha(_letra));
			j->insertarficha(ficha);
		}
		else {
			i--;
		}
	}
	if (jugador == 1) {
		for (int i = 0; i < 4; i++) {
			gotoxy(55, 6 + i); color(15); cout << "|";
		}
		gotoxy(56, 6); color(13); cout << "Fichas:";
		gotoxy(56, 7); color(15); cout << "  " << j->getCanFichas();
		gotoxy(56, 8); color(13); cout << "Puntaje:";
		gotoxy(56, 9); color(15); cout << "  " << j->getPuntaje();
		cout << "\n\tFichas -> " << j->toStringLetras();
	}
	if (jugador == 2) {
		for (int i = 0; i < 4; i++) {
			gotoxy(55, 11 + i); color(15); cout << "|";
		}
		gotoxy(56, 11); color(13); cout << "Fichas:";
		gotoxy(56, 12); color(15); cout << "  " << j->getCanFichas();
		gotoxy(56, 13); color(13); cout << "Puntaje:";
		gotoxy(56, 14); color(15); cout << "  " << j->getPuntaje();
		cout << "\n\tFichas -> " << j->toStringLetras();
	}
	if (jugador == 3) {
		for (int i = 0; i < 4; i++) {
			gotoxy(55, 16 + i); color(15); cout << "|";
		}
		gotoxy(56, 16); color(13); cout << "Fichas:";
		gotoxy(56, 17); color(15); cout << "  " << j->getCanFichas();
		gotoxy(56, 18); color(13); cout << "Puntaje:";
		gotoxy(56, 19); color(15); cout << "  " << j->getPuntaje();
		cout << "\n\tFichas -> " << j->toStringLetras();
	}
	if (jugador == 4) {
		for (int i = 0; i < 4; i++) {
			gotoxy(55, 21 + i); color(15); cout << "|";
		}
		gotoxy(56, 21); color(13); cout << "Fichas:";
		gotoxy(56, 22); color(15); cout << "  " << j->getCanFichas();
		gotoxy(56, 23); color(13); cout << "Puntaje:";
		gotoxy(56, 24); color(15); cout << "  " << j->getPuntaje();
		cout << "\n\tFichas -> " << j->toStringLetras();
	}
}
void Funcionalidad::setCantidadJugadores() {
	system("cls");
	cout << "\n\n";
	cout << "\tCuantos jugadores desean jugar? ";
	color(13); cout << "[min -> 2 || max -> 4]"; color(15);
}
bool Funcionalidad::meteFichas(Jugador *j, ListaFichas *l, int canFichas){
	string _letra;
	Ficha *ficha;
	int cont = 0;
	for (int i = 0; i < canFichas; i++) {
		_letra = randomFichas();
		if (l->sacarFicha(_letra)) {
			ficha = new Ficha(_letra, valorFicha(_letra));
			j->insertarficha(ficha);
			cont++;
		}
		else {
			i--;
		}
	}
	if (cont == canFichas) {
		return true;
	}
	return false;
}
int Funcionalidad::menu() {
	color(15);
	gotoxy(72, 7); cout << char(201); for (int i = 0; i < 20; i++) { cout << char(205); } cout << char(187);
	for (int i = 0; i < 8; i++) { gotoxy(72, 8 + i); cout << char(186); gotoxy(93, 8 + i); cout << char(186); }
	gotoxy(72, 16); cout << char(200); for (int i = 0; i < 20; i++) { cout << char(205); } cout << char(188);
	
	gotoxy(73, 9); for (int i = 0; i < 20; i++) { cout << char(205); }
	gotoxy(72, 9); cout << char(204); gotoxy(93, 9); cout << char(185);

	gotoxy(73, 14); for (int i = 0; i < 20; i++) { cout << char(205); }
	gotoxy(72, 14); cout << char(204); gotoxy(93, 14); cout << char(185);

	gotoxy(73, 8); color(15); cout << "       Menu         ";
	//linea								--------------------
	gotoxy(74, 10); color(11); cout << "[1] "; color(15); cout << "Jugar";
	gotoxy(74, 11); color(11); cout << "[2] "; color(15); cout << "Cambiar Fichas";
	gotoxy(74, 12); color(11); cout << "[3] "; color(15); cout << "Pasar Turno";
	gotoxy(74, 13); color(11); cout << "[4] "; color(15); cout << "Terminar Juego";
	int opc;
	color(59); gotoxy(74, 15); opc = evaluarInt(4, 1);
	return opc;
}
bool Funcionalidad::verificaLetras(Jugador* j,string palabra) {
	int lenPalabra;
	lenPalabra = palabra.length();
	palabra = toUpper(palabra);
	int cont=0;
	char c;
	for (int i = 0; i < lenPalabra; i++) {
		c = palabra[i];
		if (j->getLista()->encotrada(convierteString(c))) {
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
bool Funcionalidad::verificaDiccionario(Diccionario* dic,string palabra) {
	palabra = toUpper(palabra);
	for (int i = 0; i < dic->getCantidadPalabras(); i++) {
		if (palabra == dic->getPalabra(i)) {
			return true;
		}
	}
	return false;
}
bool Funcionalidad::ingresarPalabra(Tablero * t, string palabra, int f, char c, bool hv, Jugador *j, ListaFichas *l){ //coordenadas de inicio
	int lenPalabra;
	lenPalabra = palabra.length();
	palabra = toUpper(palabra);
	Ficha *ficha;
	int cont = 0;
	int puntaje = 0;
	char ch;
	int col = charXColumna(c);
	string letra;
	if (hv == true) { // horizontal
		for (int i = 0; i < lenPalabra; i++) {
			ch = palabra[i];
			letra = convierteString(ch);
			t->insertarFicha(f, (col + i), letra);
			if (j->sacarFicha(letra)) {
				ficha = new Ficha(letra, valorFicha(letra));
				l->insertarFicha(ficha);
				j->setPuntaje(valorFicha(letra));
			}
		}
		return true;
	}
	else { //vertical
		for (int i = 0; i < lenPalabra; i++) {
			ch = palabra[i];
			letra = convierteString(ch);
			t->insertarFicha(f + i, col, letra);
			if (j->sacarFicha(letra)) {
				ficha = new Ficha(letra, valorFicha(letra));
				l->insertarFicha(ficha);
				j->setPuntaje(valorFicha(letra));
			}
		}
		return true;
	}
	
	return false;
	
}
bool Funcionalidad::ingresarFichaXFicha(Tablero * t, ListaFichas *bolsa, ListaFichas* listaTablero, Jugador *j, Diccionario *dic) {
	int x[7];
	int y[7];
	string vec[7];
	int cant = 0;
	string palabra;
	Ficha *ficha;
	
	char _char; //guarda cada letra de la cadena de palabra
	string letra; //guarda el char convertido a string;
	do {
		gotoxy(72, 7); cout << "Digite la palabra > "; getline(cin, palabra);
	} while (!(verificaDiccionario(dic, palabra)));
	gotoxy(72, 9); cout << "Cuantas fichas utilizara?";
	int n = evaluarInt(7, 1);
	int f = 0;
	int c = 0;
	for (int i = 0; i < n; i++) {
		gotoxy(72, 13); cout << "                                       ";
		gotoxy(72, 15); cout << "                                       ";
		gotoxy(72, 16); cout << "                                       ";
		gotoxy(72, 17); cout << "                                       ";
		do {
			cin.clear();
			cin.ignore();
			gotoxy(72, 13); cout << "Digite la letra " << i + 1 << " "; getline(cin, letra, END);
			letra = toUpper(letra);
			gotoxy(102, 13); cout << letra;
		} while (!verificaLetras(j,letra));
		gotoxy(72, 15); cout << "Digite la Fila y la Columna:";
		gotoxy(72, 16); cout << "Fila(1,2,3...) "; f = evaluarInt(15, 1);
		gotoxy(102, 16); cout << f;
		gotoxy(72, 17); cout << "Columna(A,B,C...) "; c = charXColumna(evaluarChar());
		gotoxy(102, 17); cout << c;
		x[cant] = f;
		y[cant] = c;
		vec[cant] = letra;
		cant++;
	}
	bool checkPosition = false;
	for (int j = 0; j < cant; j++) {
		if (t->verificarCruz(x[j], y[j])) {
			checkPosition = true;
			break;
		}
	}
	if (checkPosition == true) {
		for (int i = 0; i < cant; i++) {
			if (j->sacarFicha(vec[i])) {
				ficha = new Ficha(vec[i], valorFicha(vec[i]));
				listaTablero->insertarFicha(ficha);
				meteFichas(j, bolsa, 1);
				t->insertarFicha(x[i], y[i], vec[i]);
				j->setPuntaje(valorFicha(vec[i]));
			}
		}
		gotoxy(72, 7); cout << "                                       ";
		gotoxy(72, 8); cout << "                                       ";
		gotoxy(72, 9); cout << "                                       ";
		gotoxy(72, 10); cout << "                                       ";
		gotoxy(72, 11); cout << "                                       ";
		gotoxy(72, 12); cout << "                                       ";
		gotoxy(72, 13); cout << "                                       ";
		gotoxy(72, 14); cout << "                                       ";
		gotoxy(72, 15); cout << "                                       ";
		gotoxy(72, 16); cout << "                                       ";
		gotoxy(72, 17); cout << "                                       ";
		gotoxy(72, 18); cout << "                                       ";
		gotoxy(72, 19); cout << "                                       ";
		gotoxy(72, 20); cout << "                                       ";
		gotoxy(72, 21); cout << "                                       ";
		gotoxy(72, 10); cout << "Palabra ingresada correctamente!";
		gotoxy(72, 11); cout << palabra;
		return true;
	}
	return false;
}
bool Funcionalidad::verificaLetrasTablero(ListaFichas*l, string palabra) {
	palabra = toUpper(palabra);
	char c;
	string letra;
	Ficha *ficha;
	for (int i = 0; i < palabra.length(); i++) {
		c = palabra[i];
		letra = convierteString(c);
		for (int j = 0; j < l->getCantidadNodos(); i++) {
			if (l->encotrada(letra)) {
				return true;
			}
		}
	}
	return false;
}
bool Funcionalidad::verificaCampoEMatriz(Tablero *tablero) {
	return true;
}
void Funcionalidad::guardarPuntaje(Jugador* j){
	system("cls");
	ofstream salida;
	gotoxy(10, 10);
	cout << char(201);
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	}
	cout << char(187);
	cout << endl;
	salida.open("PuntajeJugadores/puntaje.txt", ios::app);
	cout << char(186);
	cout << "  Nombre del Jugador:                   " << char(186);
	cout << "\t " << j->getNombre();
	cout << char(186);
	cout << "  Puntaje Maximo del Jugador:           " << char(186);
	cout << "\t " << j->getPuntaje();
	cout << char(186);
	cout << "  Cantidad de Victorias Obtenidads:     " << char(186);
	cout << "\t 1";
	cout << char(200);
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	}
	cout << char(188);
	cout << endl;
	j->setCantidadDeVictorias(1);
	j->autoGuardar(salida);
	salida.close();
	cin.get();
}
void Funcionalidad::leerPuntaje(){
	ifstream entrada;
	string texto;
	entrada.open("PuntajeJugadores/jugadores.txt", ios::in);
	if (entrada.is_open()) {
		while (!entrada.eof()) {
			getline(entrada, texto,END);
			cout << texto << endl;
		}
	}
	else {
		cout << "Error al abrir el archivo!" << endl;
	}
	entrada.close();
	system("PAUSE");
}
void Funcionalidad::ganador(Jugador * j1, Jugador * j2, Jugador * j3, Jugador * j4){
	Jugador **a = new Jugador*[4];
	a[0] = j1;
	a[1] = j2;
	a[2] = j3;
	a[3] = j4;
	Jugador *mayor = a[0];
	for (int i = 0; i < 3; i++) {
		if (a[i+1] >= mayor) {
			mayor = a[i+1];
		}
	}
	cout << "El ganador es: " << mayor->getNombre();
	cout << endl;
	cout << endl;
	guardarPuntaje(mayor);
	cout << endl << endl;
	system("PAUSE");
}
bool Funcionalidad::horiVert() {
	gotoxy(72, 9); color(15); cout << "Como desea ingresar la palabra";
	gotoxy(72, 10); color(13); cout << "[1] Horizontal || [2] Vertical";
	int opc = evaluarInt(2, 1);
	if (opc == 1) {
		return true;
	}
	return false;
}
string Funcionalidad::pidePalabra() {
	gotoxy(72, 7); cout << "Digite la palabra: ";
	string palabra;
	getline(cin, palabra, END);
	return palabra;
}
Funcionalidad::~Funcionalidad(){}
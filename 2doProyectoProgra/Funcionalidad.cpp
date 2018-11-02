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
void Funcionalidad::readFile(Diccionario* dic) {
	color(15); gotoxy(26, 18); cout << "Leyendo palabras del archivo \"Diccionario.txt\" ...";
	string w;
	ifstream file;
	file.open("Diccionario/diccionario.txt", ios::in);
	if (file.is_open()) {
		gotoxy(30, 21); color(255); cout << "     ";
		Sleep(500);
		while (!(file.eof())) {
			getline(file, w, FIN);
			dic->insertar(w);
			color(15);
			gotoxy(46, 19); cout << "Palabra -> "<<w;
			gotoxy(46, 19); cout << "                                                     ";
		}
	}
	else {
		cout << "No se pudo abrir el archivo";
	}
	gotoxy(35, 21); color(255); cout << "  ";
	file.close();
	file.open("Diccionario/diccionario2.txt", ios::in);
	if (file.is_open()) {
		while (!(file.eof())) {
			getline(file, w, END);
			dic->insertar(w);
			color(15);
			gotoxy(46, 19); cout << "Palabra -> " << w;
			gotoxy(46, 19); cout << "                                                     ";
		}
	}
	else {
		cout << "No se pudo abrir el archivo";
	}
	gotoxy(37, 21); color(255); cout << "         ";
	file.close();
	/*file.open("Diccionario/diccionario3.txt", ios::in);
	if (file.is_open()) {
		while (!(file.eof())) {
			getline(file, w, END);
			dic->insertar(w);
			color(15);
			gotoxy(46, 19); cout << "Palabra -> "<<w;
			gotoxy(46, 19); cout << "                                                     ";
		}
	}
	else {
		cout << "No se pudo abrir el archivo";
	}
	file.close();*/
	gotoxy(46, 21); color(255); cout << "                 ";
	
	file.open("Diccionario/diccionarioVerbos.txt", ios::in);
	if (file.is_open()) {
		while (!(file.eof())) {
			getline(file, w, END);
			dic->insertar(w);
			color(15);
			gotoxy(46, 19); cout << "Palabra -> " << w;
			gotoxy(46, 19); cout << "                                                     ";
		}
	}
	else {
		cout << "No se pudo abrir el archivo";
	}
	file.close();
	gotoxy(63, 21); color(255); cout << "           ";
	gotoxy(40, 23); color(10); cout << dic->getCant() << " palabras leidas."; color(15);
	pause();
	color(15);
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
	gotoxy(74, 10); color(13); cout << "[1] "; color(15); cout << "Jugar";
	gotoxy(74, 11); color(13); cout << "[2] "; color(15); cout << "Cambiar Fichas";
	gotoxy(74, 12); color(13); cout << "[3] "; color(15); cout << "Pasar Turno";
	gotoxy(74, 13); color(13); cout << "[4] "; color(15); cout << "Terminar Juego";
	int opc;
	gotoxy(74, 15); opc = evaluarInt(4, 1);
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
	if (dic->encontrada(palabra)) {
		return true;
	}
	return false;
}
bool Funcionalidad::ingresarPalabra(Tablero* t, ListaFichas* bolsa, ListaFichas *listaTablero, Jugador* j, Diccionario *dic){ //coordenadas de inicio
	int x[7];
	int y[7];
	string vec[7];
	int cant = 0;
	string palabra;
	Ficha *ficha;
	ofstream archivo;
	string letra; //guarda el char convertido a string;
	dibujaRectangulo(10, 30, 30, 35, 51);
	do {
		gotoxy(72, 7); cout << "Digite la palabra > "; getline(cin, palabra,END);
		if (!verificaDiccionario(dic,palabra)) {
			gotoxy(72, 9);  cout << "La palabra no esta en el diccionario";
		}
	} while (!(verificaDiccionario(dic, palabra)));
	gotoxy(72, 9); cout << "Palabra en el dicccionario!";
	int n = palabra.length();
	int f = 0;
	int c = 0;
	char change;
	bool checkPosition = false;
	do {
		for (int a = 0; a < 7; a++) {
			x[a] = NULL;
			y[a] = NULL;
		}
		cant = 0;
		for (int i = 0; i < n; i++) {
			gotoxy(72, 13); cout << "                                       ";
			gotoxy(72, 15); cout << "                                       ";
			gotoxy(72, 16); cout << "                                       ";
			gotoxy(72, 17); cout << "                                       ";
			do {
				cin.clear();
				cin.ignore();
				gotoxy(72, 13); cout << "Digite la letra " << i + 1 << "  > "; getline(cin, letra, END);
				if (letra == "-") {
					letra = cambiaComodin();
				}
				letra = toUpper(letra);
			} while (!verificaLetras(j, letra));
			gotoxy(14, 33); color(13); cout << letra; color(15);
			gotoxy(72, 15); cout << "Digite la Fila y la Columna:";
			gotoxy(72, 16); cout << "Fila(1,2,3...)    "; f = evaluarInt(15, 1);
			gotoxy(20, 33); color(14); cout << f; color(15);
			gotoxy(72, 17); cout << "Columna(A,B,C...) "; change = (evaluarChar());
			c = charXColumna(change);
			gotoxy(26, 33); color(11); cout << toUpper(convierteString(change)); color(15);
			x[cant] = f;
			y[cant] = c;
			if ((f - 1) == 7 && c == 7) {
				checkPosition = true;
			}
			vec[cant] = letra;
			cant++;
		}
		if (checkPosition == false) {
			gotoxy(72,19); cout << "Debe ingresar al menos una ficha que pase por el centro Coords: (8,H)";
		}
	} while (checkPosition == false);
	if (checkPosition == true) {
		for (int i = 0; i < cant; i++) {
			if (j->sacarFicha(vec[i])) {
				ficha = new Ficha(vec[i], valorFicha(vec[i]));
				listaTablero->insertarFicha(ficha);
				meteFichas(j, bolsa, 1);
				t->insertarFicha(x[i], y[i], vec[i]);
			}
		}
		j->setPuntaje(t->bono(x, y, vec, cant));
		for (int i = 0; i < 14; i++) {
			gotoxy(72, 7+i); cout << "                                       ";
		}
		gotoxy(72, 10); cout << "Palabra ingresada correctamente!";
		gotoxy(72, 11); cout << palabra;
		archivo.open("Palabra/palabrasCreadas.txt", ios::app);
		if (archivo.is_open()) {
			j->guardarPalabras(archivo,palabra);
		}
		archivo.close();
		pause();
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
	ofstream archivo;
	dibujaRectangulo(10, 30, 30, 35, 51);
	string letra; 
	do {
		gotoxy(72, 7); cout << "Digite la palabra > "; getline(cin, palabra);
		if (!verificaDiccionario(dic, palabra)) {
			gotoxy(72, 9);  cout << "La palabra no esta en el diccionario";
		}
	} while (!(verificaDiccionario(dic, palabra)));
	gotoxy(72, 10); cout << "Palabra en el dicccionario!";
	gotoxy(72, 9); cout << "Cuantas fichas utilizara? > ";
	int n = evaluarInt(7, 1);
	int f = 0;
	int c = 0;
	char cambia;
	for (int i = 0; i < n; i++) {
		gotoxy(72, 13); cout << "                                       ";
		gotoxy(72, 15); cout << "                                       ";
		gotoxy(72, 16); cout << "                                       ";
		gotoxy(72, 17); cout << "                                       ";
		do {
			
			gotoxy(72, 13); cout << "Digite la letra " << i + 1 << "  > "; getline(cin, letra, END);
			if (letra == "-") {
				letra = cambiaComodin();
			}
			letra = toUpper(letra);
			gotoxy(102, 13); cout << letra;
		} while (!verificaLetras(j,letra));
		gotoxy(14, 33); color(13); cout << letra; color(15);
		gotoxy(72, 15); cout << "Digite la Fila y la Columna:";
		gotoxy(72, 16); cout << "Fila(1,2,3...) "; f = evaluarInt(15, 1);
		gotoxy(20, 33); color(14); cout << f; color(15);
		gotoxy(72, 17); cout << "Columna(A,B,C...) "; cambia = evaluarChar();
		c = charXColumna(cambia);
		gotoxy(26, 33); color(11); cout << toUpper(convierteString(cambia)); color(15);
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
			}
		}
		j->setPuntaje(t->bono(x, y, vec, cant));
		for (int i = 0; i < 14; i++) {
			gotoxy(72, 7 + i); cout << "                                       ";
		}
		gotoxy(72, 10); cout << "Palabra ingresada correctamente!";
		gotoxy(72, 11); cout << palabra;
		archivo.open("Palabra/palabrasCreadas.txt", ios::app);
		if (archivo.is_open()) {
			j->guardarPalabras(archivo, palabra);
		}
		archivo.close();
		pause();
		return true;
	}
	return false;
}
string Funcionalidad::cambiaComodin() {
	for (int i = 0; i < 14; i++) {
		gotoxy(72, 7 + i); cout << "                                       ";
	}
	gotoxy(72, 10); cout << "Por que letra cambia el comodin?";
	string letra;
	getline(cin,letra);
	for (int i = 0; i < 14; i++) {
		gotoxy(72, 7 + i); cout << "                                       ";
	}
	return letra;
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
	ofstream archivo;
	cout << char(201);
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	}
	cout << char(187);
	cout << endl;
	cout << char(186);
	cout << "  Nombre del Jugador:                   " << char(186) << endl;;
	cout <<char(186)<< "\t " << j->getNombre() << endl;
	cout << char(186);
	cout << "  Puntaje Maximo del Jugador:           " << char(186) << endl;;
	cout << char(186) << "\t " << j->getPuntaje() << endl;
	cout << char(186);
	cout << "  Cantidad de Victorias Obtenidads:     " << char(186) << endl;;
	cout << char(186) << "\t 1" << endl;
	cout << char(200);
	for (int i = 0; i < 40; i++) {
		cout << char(205);
	}
	cout << char(188);
	cout << endl;
	j->setCantidadDeVictorias(1);
	archivo.open("PuntajeJugadores/puntaje.txt", ios::app);
	if (archivo.is_open()) {
		j->autoGuardar(archivo);
	}
	archivo.close();
	cin.get();
}
void Funcionalidad::leerPuntaje(){
	ifstream entrada;
	string texto;
	entrada.open("PuntajeJugadores/puntaje.txt", ios::in);
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
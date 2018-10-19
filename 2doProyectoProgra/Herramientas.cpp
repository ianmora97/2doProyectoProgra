#include "Herramientas.h"
void Herramientas::gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void Herramientas::color(int color) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);}
int Herramientas::evaluarInt(int max, int min) {
	int valor;
	bool ciclo = true;
	while (ciclo == true) {
		cout << " > ";
		color(11);
		if (!(cin >> valor)) {
			cin.clear();
			cin.ignore(1024, '\n');
			ciclo = true;
		}
		else {
			if ((valor >= min) && (valor <= max)) {
				cin.clear();
				cin.ignore(1024, '\n');
				ciclo = false;
			}
			else {
				cin.clear();
				cin.ignore(1024, '\n');
				ciclo = true;
			}
		}
		color(15);
	}
	return valor;
}
char Herramientas::evaluarChar() {
	char valor;
	bool ciclo = true;
	while (ciclo == true) {
		cout << " > ";
		color(11);
		if (!(cin >> valor)) {
			cerr << "Error!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			ciclo = true;
		}
		else {
			ciclo = false;
		}
		color(15);
	}
	return valor;
}
string Herramientas::toUpper(string palabra) {
	string upperWord;
	for (int i = 0; palabra[i]; i++) {
		upperWord = toupper(palabra[i]);
	}
	return upperWord;
}
int Herramientas::charXColumna(char col) {
	int num;
	if (col == 'A' || col == 'a') {num = 0;}
	else if (col == 'B' || col == 'b') {num = 1;}
	else if (col == 'C' || col == 'c') {num = 2;}
	else if (col == 'D' || col == 'd') {num = 3;}
	else if (col == 'E' || col == 'e') {num = 4;}
	else if (col == 'F' || col == 'f') {num = 5;}
	else if (col == 'G' || col == 'g') {num = 6;}
	else if (col == 'H' || col == 'h') {num = 7;}
	else if (col == 'I' || col == 'i') {num = 8;}
	else if (col == 'J' || col == 'j') {num = 9;}
	else if (col == 'K' || col == 'k') {num = 10;}
	else if (col == 'L' || col == 'l') {num = 11;}
	else if (col == 'M' || col == 'm') {num = 12;}
	else if (col == 'N' || col == 'n') {num = 13;}
	else if (col == 'O' || col == 'o') {num = 14;}
	return num;
}
int Herramientas::valorFicha(string f) {
	int num;
	f = toUpper(f);
	if (f == "A" || f == "I" || f == "O" || f == "R" || f == "S" || f == "T" || f == "U") {
		num = 1;
	}
	else if (f == "B" || f == "C" || f == "M" || f == "P") {
		num = 3;
	}
	else if (f == "CH" || f == "Q") {
		num = 5;
	}
	else if (f == "D" || f == "E" || f == "G" || f == "N") {
		num = 2;
	}
	else if (f == "F" || f == "H" || f == "V" || f == "Y") {
		num = 4;
	}
	else if (f == "L") {
		num = 6;
	}
	else if (f == "J" || f == "LL" || f == "Ñ" || f == "RR" || f == "X") {
		num = 8;
	}
	else if (f == "Z") {
		num = 9;
	}
	else {
		num = 0;
	}
	return num;
}
void Herramientas::turnoJugador(int t,string n) {
	color(15);
	cout << "\t" << char(201);
	for (int i = 0; i < 40; i++) { cout << char(205); }
	cout << char(187);
	cout << "\n\t" << char(186);
	color(11);
	cout << " Jugador " << t << "  "<<n;
	color(15);
	gotoxy(49,1); cout << char(186);
	color(15);
	cout << "\n\t" << char(200);
	for (int i = 0; i < 40; i++) { cout << char(205); }
	cout << char(188) << endl;
}
void Herramientas::leerFichero(string nombre) {
	string texto;
	ifstream archivo;
	nombre = (nombre + ".txt");
	archivo.open(nombre.c_str(), ios::in);
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			getline(archivo,texto);
			cout << texto;
		}
	}
	else {
		cout << "Error al abrir el archivo!" << endl;
	}
	archivo.close();
}
void Herramientas::escribirFichero(string nombre, string texto) {
	ofstream archivo;
	nombre = (nombre + ".txt");
	archivo.open(nombre.c_str(), ios::out);
	if (archivo.is_open()) {
		archivo << texto;
	}
	else {
		cout << "Error al abrir el archivo!"<<endl;
	}
	archivo.close();
}
void Herramientas::appendFichero(string nombre,string texto) {
	ofstream archivo;
	nombre = (nombre + ".txt");
	archivo.open(nombre.c_str(), ios::app);
	if (archivo.is_open()) {
		archivo << texto;
	}
	else {
		cout << "Error al abrir el archivo!" << endl;
	}
	archivo.close();
}
string Herramientas::randomFichas() {
	string ficha;
	stringstream p;
	int random;
	random = rand() % 27;
	if (random == 22) {
		p << char(165);
	}
	else if (random == 26) {
		p << "-";
	}
	else {
		p << char(65 + random);
	}
	ficha = p.str();
	return ficha;
}
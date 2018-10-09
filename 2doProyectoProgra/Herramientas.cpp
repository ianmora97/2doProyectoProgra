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
		cout << "\t> ";
		color(11);
		if (!(cin >> valor)) {
			color(12); cerr << "Error!" << endl; color(15);
			cin.clear();
			cin.ignore(1024, '\n');
			ciclo = true;
		}
		else {
			if ((valor > min) && (valor < max)) {
				ciclo = false;
			}
			else {
				color(15); cerr << "Error!" << endl;
				cerr << "Debe digitar numeros entre " << min << "-" << max << endl; color(15);
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
		if (!(cin >> valor)) {
			cerr << "Error!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			ciclo = true;
		}
		else {
			ciclo = false;
		}
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
void Herramientas::leerFichero(string nombre) {
	string texto;
	ifstream archivo;
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
void Herramientas::escribirFichero(string nombre) {
	ofstream archivo;
	string texto;
	archivo.open(nombre.c_str() , ios::out);
	if (archivo.is_open()) {
		getline(cin,texto);
		archivo << texto;
	}
	else {
		cout << "Error al abrir el archivo!" << endl;
	}
	archivo.close();
}
void Herramientas::escribirFichero(string nombre, string texto) {
	ofstream archivo;
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
	archivo.open(nombre.c_str(), ios::app);
	if (archivo.is_open()) {
		archivo << texto;
	}
	else {
		cout << "Error al abrir el archivo!" << endl;
	}
	archivo.close();
}

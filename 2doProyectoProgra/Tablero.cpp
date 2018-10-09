#include "Tablero.h"
Tablero::Tablero(){
	fila = 15;
	columna = 15;
	can = 0;
	tam = 225;
	tablero = new string*[fila]; // una matriz dinamica con objetos automaticos de tipo string
	for (int i = 0; i < fila; i++) {
		tablero[i] = new string[columna];
	}
	for (int i = 0; i < 15; i++) { // esto es para definir los valores predeterminados
		for (int j = 0; j < 15; j++) {
			if ((i + j) == 14) { //diagonal invertida
				if ((i == 0 && j == 14) || (j == 0 && i == 14)) {tablero[i][j] = " 3P ";}
				else if (i == 7 && j == 7) { tablero[i][j] = " XX ";}
				else if ((i == 5 || j == 5) && (i == 9 || j == 9)) {tablero[i][j] = " 3L ";}
				else if ((i == 6 || j == 6) && (i == 8 || j == 8)) {tablero[i][j] = " 2L ";}
				else {tablero[i][j] = " 2P ";}
			}
			else if (i == j) { //diagonal normal
				if ((i == 0) || (i == 14)) {tablero[i][j] = " 3P ";}
				else if (i == 7 && j == 7) {tablero[i][j] = " XX ";}
				else if (i == 5 || i == 9) {tablero[i][j] = " 3L ";}
				else if (i == 6 || i == 8) {tablero[i][j] = " 2L ";}
				else {tablero[i][j] = " 2P ";}
			}
			else if (i == 0 || i == 14) {
				if (j == 3 || j == 11) {tablero[i][j] = " 2L ";}
				else if (j == 7) {tablero[i][j] = " 3P ";}
				else {tablero[i][j] = "    ";}
			}
			else if (i == 1 || i == 13) {
				if (j == 5 || j == 9) {tablero[i][j] = " 3L ";}
				else {tablero[i][j] = "    ";	}
			}
			else if (i == 2 || i == 12) {
				if (j == 6 || j == 8) {tablero[i][j] = " 2L ";}
				else {tablero[i][j] = "    ";}
			}
			else if (i == 3 || i == 11) {
				if (j == 0 || j == 14 || j == 7) {tablero[i][j] = " 2L ";}
				else {tablero[i][j] = "    ";}
			}
			else if (i == 5 || i == 9) {
				if (j == 1 || j == 13) {tablero[i][j] = " 3L ";}
				else {tablero[i][j] = "    ";}
			}
			else if (i == 6 || i == 8) {
				if (j == 2 || j == 12) {tablero[i][j] = " 2L ";}
				else {tablero[i][j] = "    ";}
			}
			else if (i == 7) {
				if (j == 0 || j == 14) {tablero[i][j] = " 3P ";}
				else if (j == 3 || j == 11) {tablero[i][j] = " 2L ";}
				else {tablero[i][j] = "    ";}
			}else {tablero[i][j] = "    ";}
		}
	}
}
void Tablero::insertarFicha(int f,char c,string letra) {
	if (can < tam) {
		string le;
		if (letra == "CH" || letra == "LL" || letra == "NY" || letra == "RR") {
			le = " " + toUpper(letra) + " ";
		}
		else {
			le = " " + toUpper(letra) + "  ";
		}
		tablero[f-1][charXColumna(c)] = le;
		can++;
	}
}
void Tablero::imprimeTablero(){
	cout << "\n";
	color(119);
	for (int e = 0; e < 90; e++) {cout << " ";}
	color(127);	cout << "\n          A    B    C    D    E    F    G    H    I    J    K    L    M    N    O         \n";
	for (int o = 0; o < 90; o++) {cout << " ";}
	cout << "\n";
	for (int i = 0; i < 15; i++) { //no me pregunte como lo hice, solo lo hice
		color(127);
		if (i >= 9) {cout << "   " << i + 1 << "    ";}
		else {cout << "    " << i + 1 << "    ";}
		for (int j = 0; j < 15; j++) {
			if ((i + j) == 14) {  
				if ((i == 0 && j == 14) || (j == 0 && i == 14)) { color(191);cout << tablero[i][j];color(15); }//esquinas
				else if (i == 7 && j == 7) { color(95);cout << tablero[i][j]; }//centro
				else if ((i == 5 || j == 5) && (i == 9 || j == 9)) { color(224);cout << tablero[i][j]; }//arriba
				else if ((i == 6 || j == 6) && (i == 8 || j == 8)) { color(223);cout << tablero[i][j]; }
				else { color(47);cout << tablero[i][j]; }//diagonal
			}
			else if (i == j) { //diagonal
				if ((i == 0) || (i == 14)) { color(191); cout << tablero[i][j]; color(15); }
				else if (i == 7 && j == 7) { color(95); cout << tablero[i][j]; } //centro
				else if (i == 5 || i == 9) { color(224); cout << tablero[i][j]; }
				else if (i == 6 || i == 8) { color(223); cout << tablero[i][j]; }
				else { color(47); cout << tablero[i][j]; }
			}
			else if (i == 0 || i == 14) {
				if (j == 3 || j == 11) { color(223); cout << tablero[i][j]; }
				else if (j == 7) { color(191);cout << tablero[i][j]; }
				else { color(55);cout << tablero[i][j]; }
			}
			else if (i == 1 || i == 13) {
				if (j == 5 || j == 9) { color(224);cout << tablero[i][j]; }
				else { color(55);cout << tablero[i][j]; }
			}
			else if (i == 2 || i == 12) {
				if (j == 6 || j == 8) { color(223);cout << tablero[i][j]; }
				else { color(55); cout << tablero[i][j]; }
			}
			else if (i == 3 || i == 11) {
				if (j == 0 || j == 14 || j == 7) { color(223); cout << tablero[i][j]; }
				else { color(55); cout << tablero[i][j]; }
			}
			else if (i == 5 || i == 9) {
				if (j == 1 || j == 13) { color(224); cout << tablero[i][j]; }
				else { color(55); cout << tablero[i][j]; }
			}
			else if (i == 6 || i == 8) {
				if (j == 2 || j == 12) { color(223); cout << tablero[i][j]; }
				else { color(55); cout << tablero[i][j]; }
			}
			else if (i == 7) {
				if (j == 0 || j == 14) { color(191); cout << tablero[i][j]; }
				else if (j == 3 || j == 11) { color(223); cout << tablero[i][j]; }
				else { color(55); cout << tablero[i][j]; }
			}
			else {color(55); cout << tablero[i][j];	}
			color(119); cout << " ";
		}
		cout << "      ";
		color(119); cout << "\n";
		for (int s = 0; s < 90; s++) { cout << " "; }
		cout << "\n";
	}
	color(15);
}
void Tablero::imprimeScrabble() {
	cout << "\t _______    ______    ________     _______    ______    ______     __       _______ " << endl;
	cout << "\t|  _____|  |   ___|  |   __   )   |  ___  |  |      |  |      |   |  |     |   ____|" << endl;
	cout << "\t| |_____   |  |      |  |__|  |   | |___| |  |  []  /  |  []  /   |  |     |  |___  " << endl;
	cout << "\t|_____  |  |  |      |  ___   /   |  ___  |  | ----/_  | ----/_   |  |     |   ___| " << endl;
	cout << "\t _____| |  |  |___   |  |  |  |   | |   | |  |  []   | |  []   |  |  |___  |  |____ " << endl;
	cout << "\t|_______|  |______|  |__|  |__|   |_|   |_|  |_______/ |_______/  |______| |_______|" << endl;
}
Tablero::~Tablero()
{
}

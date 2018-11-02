#include "Tablero.h"
Tablero::Tablero(){
	fila = 15;
	columna = 15;
	can = 0;
	tam = 225;
	tablero = new string*[fila];
	for (int i = 0; i < fila; i++) {
		tablero[i] = new string[columna];
	}
	for (int a = 0; a < fila; a++)
		for (int b = 0; b < columna; b++)
			matrizBoleana[a][b] = false;

	//for (int i = 0; i < 15; i++) { // esto es para definir los valores predeterminados
	//	for (int j = 0; j < 15; j++) {
	//		if ((i + j) == 14) { //diagonal invertida
	//			if ((i == 0 && j == 14) || (j == 0 && i == 14)) {tablero[i][j] = " 3P ";}
	//			else if (i == 7 && j == 7) { tablero[i][j] = "[  ]";}
	//			else if ((i == 5 || j == 5) && (i == 9 || j == 9)) {tablero[i][j] = " 3L ";}
	//			else if ((i == 6 || j == 6) && (i == 8 || j == 8)) {tablero[i][j] = " 2L ";}
	//			else {tablero[i][j] = " 2P ";}
	//		}
	//		else if (i == j) { //diagonal normal
	//			if ((i == 0) || (i == 14)) {tablero[i][j] = " 3P ";}
	//			else if (i == 7 && j == 7) {tablero[i][j] = "[  ]";}
	//			else if (i == 5 || i == 9) {tablero[i][j] = " 3L ";}
	//			else if (i == 6 || i == 8) {tablero[i][j] = " 2L ";}
	//			else {tablero[i][j] = " 2P ";}
	//		}
	//		else if (i == 0 || i == 14) {
	//			if (j == 3 || j == 11) {tablero[i][j] = " 2L ";}
	//			else if (j == 7) {tablero[i][j] = " 3P ";}
	//			else {tablero[i][j] = "    ";}
	//		}
	//		else if (i == 1 || i == 13) {
	//			if (j == 5 || j == 9) {tablero[i][j] = " 3L ";}
	//			else {tablero[i][j] = "    ";	}
	//		}
	//		else if (i == 2 || i == 12) {
	//			if (j == 6 || j == 8) {tablero[i][j] = " 2L ";}
	//			else {tablero[i][j] = "    ";}
	//		}
	//		else if (i == 3 || i == 11) {
	//			if (j == 0 || j == 14 || j == 7) {tablero[i][j] = " 2L ";}
	//			else {tablero[i][j] = "    ";}
	//		}
	//		else if (i == 5 || i == 9) {
	//			if (j == 1 || j == 13) {tablero[i][j] = " 3L ";}
	//			else {tablero[i][j] = "    ";}
	//		}
	//		else if (i == 6 || i == 8) {
	//			if (j == 2 || j == 12) {tablero[i][j] = " 2L ";}
	//			else {tablero[i][j] = "    ";}
	//		}
	//		else if (i == 7) {
	//			if (j == 0 || j == 14) {tablero[i][j] = " 3P ";}
	//			else if (j == 3 || j == 11) {tablero[i][j] = " 2L ";}
	//			else {tablero[i][j] = "    ";}
	//		}else {tablero[i][j] = "    ";}
	//	}
	//}
	for (int i = 0; i < 15; i++) { // esto es para definir los valores predeterminados
		for (int j = 0; j < 15; j++) {
			if ((i + j) == 14) { //diagonal invertida
				if ((i == 0 && j == 14) || (j == 0 && i == 14)) { tablero[i][j] = "3P"; }
				else if (i == 7 && j == 7) { tablero[i][j] = "**"; }
				else if ((i == 5 || j == 5) && (i == 9 || j == 9)) { tablero[i][j] = "3L"; }
				else if ((i == 6 || j == 6) && (i == 8 || j == 8)) { tablero[i][j] = "2L"; }
				else { tablero[i][j] = "2P"; }
			}
			else if (i == j) { //diagonal normal
				if ((i == 0) || (i == 14)) { tablero[i][j] = "3P"; }
				else if (i == 7 && j == 7) { tablero[i][j] = "**"; }
				else if (i == 5 || i == 9) { tablero[i][j] = "3L"; }
				else if (i == 6 || i == 8) { tablero[i][j] = "2L"; }
				else { tablero[i][j] = "2P"; }
			}
			else if (i == 0 || i == 14) {
				if (j == 3 || j == 11) { tablero[i][j] = "2L"; }
				else if (j == 7) { tablero[i][j] = "3P"; }
				else { tablero[i][j] = "  "; }
			}
			else if (i == 1 || i == 13) {
				if (j == 5 || j == 9) { tablero[i][j] = "3L"; }
				else { tablero[i][j] = "  "; }
			}
			else if (i == 2 || i == 12) {
				if (j == 6 || j == 8) { tablero[i][j] = "2L"; }
				else { tablero[i][j] = "  "; }
			}
			else if (i == 3 || i == 11) {
				if (j == 0 || j == 14 || j == 7) { tablero[i][j] = "2L"; }
				else { tablero[i][j] = "  "; }
			}
			else if (i == 5 || i == 9) {
				if (j == 1 || j == 13) { tablero[i][j] = "3L"; }
				else { tablero[i][j] = "  "; }
			}
			else if (i == 6 || i == 8) {
				if (j == 2 || j == 12) { tablero[i][j] = "2L"; }
				else { tablero[i][j] = "  "; }
			}
			else if (i == 7) {
				if (j == 0 || j == 14) { tablero[i][j] = "3P"; }
				else if (j == 3 || j == 11) { tablero[i][j] = "2L"; }
				else { tablero[i][j] = "  "; }
			}
			else { tablero[i][j] = "  "; }
		}
	}
	for (int i = 0; i < 15; i++) { //matriz de valores
		for (int j = 0; j < 15; j++) {
			if ((i + j) == 14) { //diagonal invertida
				if ((i == 0 && j == 14) || (j == 0 && i == 14)) { matrizValores[i][j] = 1; } //triple palabra
				else if (i == 7 && j == 7) { matrizValores[i][j] = 0; }
				else if ((i == 5 || j == 5) && (i == 9 || j == 9)) { matrizValores[i][j] = 2; } //triple letra
				else if ((i == 6 || j == 6) && (i == 8 || j == 8)) { matrizValores[i][j] = 4; } //doble letra
				else { matrizValores[i][j] = 3; } //doble palabra
			}
			else if (i == j) { //diagonal normal
				if ((i == 0) || (i == 14)) { matrizValores[i][j] = 1; }
				else if (i == 7 && j == 7) { matrizValores[i][j] = 0; }
				else if (i == 5 || i == 9) { matrizValores[i][j] = 2; }
				else if (i == 6 || i == 8) { matrizValores[i][j] = 4; }
				else { matrizValores[i][j] = 3; }
			}
			else if (i == 0 || i == 14) {
				if (j == 3 || j == 11) { matrizValores[i][j] = 4; }
				else if (j == 7) { matrizValores[i][j] = 1; }
			}
			else if (i == 1 || i == 13) {
				if (j == 5 || j == 9) { matrizValores[i][j] = 2; }
			}
			else if (i == 2 || i == 12) {
				if (j == 6 || j == 8) { matrizValores[i][j] = 4; }
			}
			else if (i == 3 || i == 11) {
				if (j == 0 || j == 14 || j == 7) { matrizValores[i][j] = 4; }
			}
			else if (i == 5 || i == 9) {
				if (j == 1 || j == 13) { matrizValores[i][j] = 2; }
			}
			else if (i == 6 || i == 8) {
				if (j == 2 || j == 12) { matrizValores[i][j] = 4; }
			}
			else if (i == 7) {
				if (j == 0 || j == 14) { matrizValores[i][j] = 1; }
				else if (j == 3 || j == 11) { matrizValores[i][j] = 4; }
			}
		}
	}
}
void Tablero::insertarFicha(int f,int c,string letra) {
	if (can < tam) {
		string le;
		le = toUpper(letra) + " ";
		tablero[f - 1][c] = le;
		matrizBoleana[f - 1][c] = true;
		can++;
	}
}
void Tablero::imprimeTablero() {
	cout << "\n\n\n";
	color(14); cout << "\n          A  B  C  D  E  F  G  H  I  J  K  L  M  N  O   \n";
	color(15); cout << "  ";
	for (int o = 0; o < 64; o++) { color(15); cout << " "; }
	cout << "\n";
	for (int i = 0; i < 15; i++) {
		if (i >= 9) { color(13); cout << "     " << i + 1; color(15); cout << "  "; }
		else { color(13); cout << "      " << i + 1; color(15); cout << "  "; }
		for (int j = 0; j < 15; j++) {
			if (tablero[i][j] == "3P") {
				color(32); cout << char(179); color(204); cout << tablero[i][j];
			}
			else if (tablero[i][j] == "3L") {
				color(32); cout << char(179); color(17); cout << tablero[i][j];
			}
			else if (tablero[i][j] == "2L") {
				color(32); cout << char(179); color(187); cout << tablero[i][j];
			}
			else if (tablero[i][j] == "2P") {
				color(32); cout << char(179); color(221); cout << tablero[i][j];
			}
			else if (tablero[i][j] == "**") {
				color(32); cout << char(179); color(255); cout << tablero[i][j];
			}
			else if (tablero[i][j] == "  ") { 
				color(32); cout << char(179); color(47); cout << tablero[i][j];
			}
			else {
				color(32); cout << char(179); color(243); cout << tablero[i][j];
			}
		}
		color(32); cout << char(179);
		color(15); cout << "  ";
		cout << "\n";
	}
	color(15); cout << "  ";
	for (int o = 0; o < 64; o++) { color(15); cout << " "; }
	color(15);
	cout << endl;
}
void Tablero::imprimeScrabble() {
	cout << "\t _______    ______    _______      _______    ______    ______     __       _______ " << endl;
	cout << "\t|  _____|  |   ___|  |   __  \\    |  ___  |  |      |  |      |   |  |     |   ____|" << endl;
	cout << "\t| |_____   |  |      |  |__|  |   | |___| |  |  []  /  |  []  /   |  |     |  |___  " << endl;
	cout << "\t|_____  |  |  |      |  ___   /   |  ___  |  | ----/_  | ----/_   |  |     |   ___| " << endl;
	cout << "\t _____| |  |  |___   |  |  | |    | |   | |  |  []   | |  []   |  |  |___  |  |____ " << endl;
	cout << "\t|_______|  |______|  |__|  |_|    |_|   |_|  |_______/ |_______/  |______| |_______|" << endl;
}
bool Tablero::verificaPosicion(int x,int y){
	if (matrizBoleana[x][y] == true) {
		return true;
	}
	return false;
}
bool Tablero::verificarCruz(int i, int j) {
	i--;
	if (matrizBoleana[i - 1][j] == true ||
		matrizBoleana[i + 1][j] == true ||
		matrizBoleana[i][j - 1] == true ||
		matrizBoleana[i][j + 1] == true ) {
		return true;
	}
	return false;
}
int Tablero::bono(int f[], int c[], string l[], int cant) {
	int puntaje=0;
	bool verDoble = false, verTriple = false;
	for (int i = 0; i < cant; i++) {
		if (valores(f[i],c[i]) == 1) { // Hay una casilla con triple de palabra 3P
			verTriple = true;
		}
		else if (valores(f[i], c[i]) == 3) { // Hay una casilla con doble de palabra 2P
			verDoble = true;
		}
		if (valores(f[i], c[i]) == 2) { // Hay una casilla con 3 veces la letra
			puntaje += (valorFicha(l[i]) * 3);
		}
		else if (valores(f[i], c[i]) == 4) { // Hay una casilla con 2 veces la letra
			puntaje += (valorFicha(l[i]) * 2);
		}
		else {
			puntaje += valorFicha(l[i]);
		}
	}
	if (verDoble == true) { // multiplica por 2 el puntaje
		puntaje = puntaje * 2;
	}
	else if (verTriple == true) { // multiplica por 3 el puntaje
		puntaje = puntaje * 3;
	}
	return puntaje;
}
void Tablero::imprimeTableroValores() {
	for (int i = 0; i < 15; i++) {
		for (int a = 0; a < 15; a++) {
			if(matrizValores[i][a] == 1){
				color(12); cout << "[" << matrizValores[i][a] << "]";
			}
			else if (matrizValores[i][a] == 2) {
				color(10); cout << "[" << matrizValores[i][a] << "]";
			}
			else if (matrizValores[i][a] == 3) {
				color(14); cout << "[" << matrizValores[i][a] << "]";
			}
			else if (matrizValores[i][a] == 4) {
				color(11); cout << "[" << matrizValores[i][a] << "]";
			}
			else {
				color(3); cout << "[" << matrizValores[i][a] << "]";
			}
		}
		cout << endl;
	}
}
int Tablero::valores(int f, int c) {
	return matrizValores[f-1][c];
}
string Tablero::getTablero() {
	return **tablero;
}
Tablero::~Tablero(){}

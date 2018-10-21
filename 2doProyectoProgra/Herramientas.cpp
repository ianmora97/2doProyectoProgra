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
bool Herramientas::verificaMatriz(string m[100][100]) {
	
	
	return true;
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
void Herramientas::instrucciones2() {

	system("CLS");
	color(15);
	cout << "\t\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(187);
	cout << "\n\t\t\t\t\t" << char(186);
	color(11);
	cout << "         Instrucciones        ";
	color(15);
	cout << char(186) << endl;
	color(15);
	cout << "\t\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 63; i++) { cout << char(205); }
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186);
	cout << "\t\t     Istrucciones del scrabble" << "                  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Al iniciar el juego, se debe asignar en forma aleatoria " << "      " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " 7 fichas a cada jugador estas se deben mostrar en pantalla " << "   " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " mientras sea el turno del jugador al que estas fichas " << "        " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " corresponden.El primero en  jugar combina dos o mas letras" << "    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " para formar una palabra (máximo 7 letras), colocandola en " << "    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " linea central del tablero(vertical u horizontal,no diagonal). " << "" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Las palabras deben poderse leer de izquierda a derecha " << "       " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " y de arriba hacia abajo." << "                                      " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "- Terminado cada turno se debe sumar al jugador la " << "            " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " puntuación obtenida por la palabra formada, recordar que " << "     " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " cada letra tiene un puntaje. " << "                                 " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "- Una vez que el jugador ha creado la palabra, puede " << "          " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " solicitar al sistema la misma cantidad de  letras o fichas " << "   " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " ya utilizadas, esto para iniciar cada turno siempre con " << "      " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " 7 letras o fichas (las fichas son asignadas  aleatoriamente). " << "" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "- Cada vez que el jugador termine su turno, en pantalla " << "       " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " se debe mostrar las fichas que le quedaron,  la palabra " << "      " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " formada, la puntuación de cada una de ellas y las fichas " << "     " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " aun disponibles en el juego." << "                                  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Las nuevas palabras formadas deben ser buscadas " << "              " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " y corroboradas  en el diccionario previamente creado " << "         " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                                                               " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                            Pag 2 de 3" << "                         " << char(186) << endl;
	cout << "\t\t\t" << char(200);
	for (int i = 0; i < 63; i++) { cout << char(205); }
	cout << char(188);

	cin.get();
}
void Herramientas::instrucciones3() {

	system("CLS");
	color(15);
	cout << "\t\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(187);
	cout << "\n\t\t\t\t\t" << char(186);
	color(11);
	cout << "         Instrucciones        ";
	color(15);
	cout << char(186) << endl;
	color(15);
	cout << "\t\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 63; i++) { cout << char(205); }
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186);
	cout << "\t\t     Istrucciones del scrabble" << "                  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " si la palabra no se encuentra en el diccionario se dara  " << "     " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " por no valida. Este diccionario debera ser un archivo." << "        " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " En el momento en el que uno de los jugadores crea una palabra " << "" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "  con las 7 letras logra un scrabble, por lo que obtiene " << "      " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " 100 puntos extra." << "                                             " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " El juego finaliza cuando alguno de los jugadores ha utilizado" << " " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " todas sus letras y no queden mas letras disponibles o cuando" << "  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " ninguno de los jugadores NO puede colocar mas letras para " << "    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "formar nuevas palabras " << "                                        " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                                                               " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                            Pag 3 de 3" << "                         " << char(186) << endl;
	cout << "\t\t\t" << char(200);
	for (int i = 0; i < 63; i++) { cout << char(205); }
	cout << char(188);
	cout << endl;
	cin.get();
}
void Herramientas::instrucciones1() {

	system("CLS");
	color(15);
	cout << "\t\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(187);
	cout << "\n\t\t\t\t\t" << char(186);
	color(11);
	cout << "         Instrucciones        ";
	color(15);
	cout << char(186) << endl;
	color(15);
	cout << "\t\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 63; i++) { cout << char(205); }
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186);
	cout << "\t\t     Istrucciones del scrabble" << "                  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "- De las 100 fichas 98 son letras y 2 dos son fichas en blanco" << " " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " blanco que se utilizan como comodines las cuales pueden" << "       " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " ser utilizadas en sustitución de cualquier letra y no tienen" << "  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " ningun valor. " << "                                                " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " En caso de hacer uso de una de las fichas comodin, el jugador " << "" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " debe indicar la letra que está sustituyendo, la cual no puede " << "" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " ser modificada en el transcurso de la partida (las fichas " << "    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " comodin tienen un valor de cero). " << "                            " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "-El tablero consta de 13 por 13 casillas, de las cuales la " << "    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " mayoria son grises y las otras  de los colores: amarillo, " << "    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " rosado, azul y verde. Los diferentes colores indican un premio" << "" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " o aumento en el valor de  la palabra segun corresponda" << "        " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Casilla amarillo: triplica el valor de la letra" << "               " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Casilla rosada: duplica el valor de la letra " << "                 " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Casilla azul: triplica el valor de la palabra" << "                 " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Casilla verde: duplica el valor de la palabra " << "                " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " Los premios para las letras y las palabras se aplican solo  " << "  " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " la primera vez que se utiliza la casilla. " << "                    " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << " " << "                                                              " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "  " << "                                                             " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                              " << "                                 " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                                                               " << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "                            Pag 1 de 3" << "                         " << char(186) << endl;
	cout << "\t\t\t" << char(200);
	for (int i = 0; i < 63; i++) { cout << char(205); }
	cout << char(188);
	cin.clear();
	cin.ignore();
	cin.get();
}

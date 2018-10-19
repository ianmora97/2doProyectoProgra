#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include <fstream>

using namespace std;
class Herramientas {
public:
	 void gotoxy(int, int);
	 void color(int);
	 int evaluarInt(int,int);
	 char evaluarChar();
	 string toUpper(string);
	 int charXColumna(char);
	 int valorFicha(string = "letra");
	 void turnoJugador(int t,string n);
	 void leerFichero(string = "nombre del archivo");
	 void escribirFichero(string = "nombre del archivo",string = "texto");
	 void appendFichero(string = "nombre del archivo",string = "texto");
	 string randomFichas();
};

#endif // !HERRAMIENTAS_H

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
	 void leerFichero(string);
	 void escribirFichero(string);
	 void escribirFichero(string,string);
	 void appendFichero(string,string);
};

#endif // !HERRAMIENTAS_H

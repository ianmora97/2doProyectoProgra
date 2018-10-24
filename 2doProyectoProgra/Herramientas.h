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
	 static void gotoxy(int, int);
	 static void color(int);
	 static int evaluarInt(int,int);
	 static char evaluarChar();
	 static string toUpper(string);
	 static int charXColumna(char);
	 static int valorFicha(string = "letra");
	 static void turnoJugador(int t,string n);
	 static bool verificaMatriz(string m[100][100]);
	 static void instrucciones1();
	 static void instrucciones2();
	 static void instrucciones3();
	 static void leerFichero(string = "nombre del archivo");
	 static void escribirFichero(string = "nombre del archivo",string = "texto");
	 static void appendFichero(string = "nombre del archivo",string = "texto");
	 static string randomFichas();
	 static void borrarFichero(string = "nombre del archivo");
};

#endif // !HERRAMIENTAS_H

#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H
#define END '\n'
#define TAB '\t'
#define FIN '/'
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <cctype>
#include <Windows.h>
#include <fstream>

using namespace std;
void gotoxy(int, int);
void color(int);
int evaluarInt(int,int);
char evaluarChar();
string toUpper(string);
int charXColumna(char);
int valorFicha(string = "letra");
void dibujaRectangulo(int,int,int,int,int); //(Sup.Izq , Sup.Der , Inf.Izq , Inf.Der, color)
void instrucciones1();
void instrucciones2();
void instrucciones3();
void leerFichero(string = "nombre del archivo");
void escribirFichero(string = "nombre del archivo",string = "texto");
void appendFichero(string = "nombre del archivo",string = "texto");
string randomFichas();
string convierteString(char);
void borrarFichero(string = "nombre del archivo");
void pause();

#endif // !HERRAMIENTAS_H

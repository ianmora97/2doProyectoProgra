#include "Interfaz.h"
Interfaz::Interfaz(){}
int Interfaz::menu(){
	int opc;
	opc = validar();
	return opc;
}
void Interfaz::imprime(){
	color(15);
	cout << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 46; i++) { cout << char(205); }
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186) << endl;

	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [1]";
	color(15);
	cout << "   Jugar\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [2]";
	color(15);
	cout << "   Instrucciones\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [3]";
	color(15);
	cout << "   Mostrar Puntajes\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [4]";
	color(15);
	cout << "   Mostrar Palabras Creadas\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(13);
	cout << "  [0]";
	color(15);
	cout << "   Salir del programa\n";
	cout << "\t\t\t";
	cout << char(186);

	cout << "\n\t\t\t" << char(204);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(185) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186) << endl;
	cout << "\t\t\t" << char(186);
	cout << "\n\t\t\t" << char(200);
	for (int i = 0; i < 46; i++) { cout << char(205); } //imprime una linea de =
	cout << char(188) << endl;
	for (int i = 0; i < 11; i++) {
		gotoxy(71, 13 + i); cout << char(186);
	}
	gotoxy(71, 19+6); cout << char(186);
	gotoxy(71, 20+6); cout << char(186);
	gotoxy(71, 21+6); cout << char(186);
}
int Interfaz::validar(){
	int opc;
	bool c = true;
	while (c) {
		gotoxy(35, 26); cout << "Opcion > ";
		color(13);
		if (!(cin >> opc)) {
			color(15);
			gotoxy(44, 26); cout << "                           " << char(186) << "            "; 
			color(12);
			gotoxy(55, 26); cout << "Error!";
			color(15);
			Sleep(700);
			gotoxy(44, 26); cout << "                           "; 
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (opc < 0 || opc >4) { 
			color(15);
			gotoxy(44, 26); cout << "                           " << char(186) << "            ";
			color(12);
			gotoxy(55, 26); cout << "Error!";
			color(15);
			Sleep(700);
			gotoxy(44, 26); cout << "                           ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else { c = false; }
		color(15);
	}
	return opc;
}
void Interfaz::cuadros() {
	int col;
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 110; j++) {
			col = rand() % 110;
			if ((i+j)%2 == 0) {
				gotoxy(col, i); color(221); cout << " ";
			}
			else {
				gotoxy(col, i); color(15); cout << " ";
			}
		}
	}
	color(15);
}
Interfaz::~Interfaz(){}

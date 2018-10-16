#include "Interfaz.h"
Interfaz::Interfaz(){}
int Interfaz::menu(){
	int opc;
	opc = validar();
	return opc;
}
void Interfaz::imprime(){
	system("cls");
	color(15);
	cout << endl << endl << endl;
	cout << "\t\t\t\t" << char(201);
	for (int i = 0; i < 30; i++) { cout << char(205); } 
	cout << char(187);
	cout << "\n\t\t\t\t" << char(186);
	color(11);
	cout << "        MENU PRINCIPAL        ";
	color(15);
	cout << char(186) << endl;
	color(15);
	cout << "\t\t\t\t" << char(200);
	for (int i = 0; i < 30; i++) { cout << char(205); }
	cout << char(188) << endl;

	cout << "\t\t\t" << char(201);
	for (int i = 0; i < 46; i++) { cout << char(205); }
	cout << char(187);
	cout << endl;
	cout << "\t\t\t";
	cout << char(186) << endl;

	cout << "\t\t\t";
	cout << char(186);
	color(10);
	cout << "  [1]";
	color(15);
	cout << "   Jugar\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(10);
	cout << "  [2]";
	color(15);
	cout << "   Instrucciones\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(10);
	cout << "  [3]";
	color(15);
	cout << "   Mostrar Puntajes\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(10);
	cout << "  [4]";
	color(15);
	cout << "   Mostrar Palabras Creadas\n";
	cout << "\t\t\t";
	cout << char(186) << endl;
	cout << "\t\t\t";
	cout << char(186);
	color(10);
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
		gotoxy(71, 7 + i); cout << char(186);
	}
	gotoxy(71, 19); cout << char(186);
	gotoxy(71, 20); cout << char(186);
	gotoxy(71, 21); cout << char(186);
}

int Interfaz::validar(){
	int opc;
	bool c = true;
	while (c) {
		gotoxy(35, 20); cout << "Opcion > ";
		color(10);
		if (!(cin >> opc)) {
			color(15);
			gotoxy(44, 20); cout << "                           " << char(186) << "            "; 
			color(12);
			gotoxy(55, 20); cout << "Error!";
			color(15);
			Sleep(700);
			gotoxy(44, 20); cout << "                           "; 
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (opc < 0 || opc >4) { 
			color(15);
			gotoxy(44, 20); cout << "                           " << char(186) << "            ";
			color(12);
			gotoxy(55, 20); cout << "Error!";
			color(15);
			Sleep(700);
			gotoxy(44, 20); cout << "                           ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else { c = false; }
		color(15);
	}
	return opc;
}
Interfaz::~Interfaz(){}

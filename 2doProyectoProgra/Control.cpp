#include "Control.h"
Control::Control(){}
void Control::opciones() {
	color(15);
	Interfaz *interfaz = new Interfaz;
	ListaFichas *bolsaFichas = new ListaFichas;
	Tablero *tablero = new Tablero;
	ListaFichas *listaTablero = new ListaFichas;

	//---Variables de ciclos---
	bool menuCiclo = true;

	//---!Variables de ciclos---
	//---Variables de jugadores---
	string nombreJugador;
	Jugador *jugador1 = new Jugador("indef");
	Jugador *jugador2 = new Jugador("indef");
	Jugador *jugador3 = new Jugador("indef");
	Jugador *jugador4 = new Jugador("indef");
	Ficha *fichaJugador = new Ficha("indef",0);
	//---!Variables de jugadores---
	
	//--Variables contadores--
	int cantidadJugadores;
	srand(time(NULL));
	string fichasacada;
	string letraEligida;
	char col;
	int fil;
	string letrasSacadas[100];
	int cantLetrasSacadas = 0;
	string letraElegida;
	int valor; //la suma de valores de los jugadores -> el puntaje y guardarlo
	//--!Variables contadores--
	
	while (menuCiclo == true) {
		//--------------------Ingresar las fichas en la lista------------------------
		ifstream archivo;
		string texto;
		string nombre("Fichas/fichas.txt");
		archivo.open(nombre.c_str(), ios::in);
		Ficha *ficha;
		if (archivo.is_open()) {
			while (!archivo.eof()) {
				archivo >> texto;
				ficha = new Ficha(texto, valorFicha(texto));
				bolsaFichas->insertarFicha(ficha);
			}
		}
		else {
			cout << "Error al abrir el archivo!" << endl;
		}
		archivo.close();
		//----------------------!Ingresar las fichas en la lista-------------------------
		system("cls");
		interfaz->imprime();
		int paso = 0;
		switch (interfaz->menu()){
		case 1:
			system("cls");
			cout << "Cuantos jugadores desean Jugar?";
			color(11); cout << " ( Min: 2 <-> Max: 4)" << endl; color(15);
			cantidadJugadores = evaluarInt(4,2);
			if (cantidadJugadores == 2) {
				cout << "Digite el nombre del jugador 1: ";
				getline(cin, nombreJugador);
				jugador1->setNombre(nombreJugador);
				cout << "Digite el nombre del jugador 2: ";
				getline(cin, nombreJugador);
				jugador2->setNombre(nombreJugador);
				for (int i = 0; i < 7; i++) {
					fichasacada = randomFichas();
					fichaJugador = new Ficha(fichasacada, valorFicha(fichasacada));
					bolsaFichas->sacarFicha(fichasacada);
					jugador1->insertarficha(fichaJugador);
					letrasSacadas[cantLetrasSacadas] = fichasacada;
					cantLetrasSacadas++;
				}
				
				
				for (int i = 0; i < 7; i++) {
					for (int a = 0; a < cantLetrasSacadas; a++) {
						fichasacada = randomFichas();
						if (letrasSacadas[a] != fichasacada) {
							letraElegida = fichasacada;
						}
					}
					fichaJugador = new Ficha(letraElegida, valorFicha(letraElegida));
					bolsaFichas->sacarFicha(letraElegida);
					jugador2->insertarficha(fichaJugador);
					letrasSacadas[cantLetrasSacadas] = letraElegida;
					cantLetrasSacadas++;
				}
				system("cls");
				int cont = 0;
				while ( (!(bolsaFichas->vacia())) && (!(jugador1->getLista()->vacia()) || !(jugador2->getLista()->vacia())) && (paso != 2)) {
					if (cont % 2 == 0) {
						system("cls");
						turnoJugador(cont+1, jugador1->getNombre());
						tablero->imprimeTablero();
						jugador1->cuadroFichas();
						gotoxy(1,24); 
						cout << "Que desea hacer?"<<endl;
						int opc;
						color(10); cout << "[1] Jugar -- [2] Pasar -- [0] Terminar Juego" << endl; color(15);
						opc = evaluarInt(2,0);
						switch (opc){
						case 1:
							gotoxy(67,9); cout << "Cuantas fichas desea insertar al tablero?";
							int cantFichasIngresar;
							cantFichasIngresar = evaluarInt(7,2);
							for (int i = 0; i < cantFichasIngresar; i++) {
								gotoxy(67, 10); cout << "Digite la letra: ";
								bool verifica = true;
								while (verifica) {
									if (!(cin>>letraEligida)) {
										cin.clear();
										cin.ignore();
									}
									else {
										if (letraEligida.length() == 1 && jugador1->getLista()->encotrada(toUpper(letraEligida))) {
											cin.clear();
											cin.ignore();
											verifica = false;
										}
										else {
											cin.clear();
											cin.ignore();
										}
									}
								}
								letraEligida = toUpper(letraEligida);
								gotoxy(83,10); cout << letraEligida;
								gotoxy(67,12);
								cout << "Digite la columna: (A,B,C,...)";
								col = evaluarChar();
								gotoxy(67,13);
								cout << "Digite la fila: (1,2,3,...)";
								fil = evaluarInt(15,1);
								tablero->insertarFicha(fil,col,letraEligida);
								jugador1->getLista()->sacarFicha(letraEligida);
								ficha = new Ficha(letraEligida,valorFicha(letraEligida));
								listaTablero->insertarFicha(ficha);
								system("cls");
								turnoJugador(cont + 1, jugador1->getNombre());
								tablero->imprimeTablero();
								jugador1->cuadroFichas();
							}
							break;
						case 2:
							cout << "Pasar Turno!" << endl;
							paso = 0;
							paso++;
							break;
						case 0:
							cout << "Juego Terminado!" << endl;
							paso = 2;
							break;
						default:
							break;
						}
						system("PAUSE");
						cont++;
					}
					else {
						system("cls");
						turnoJugador(cont + 1, jugador2->getNombre());
						tablero->imprimeTablero();
						jugador2->cuadroFichas();
						gotoxy(1, 24);
						cout << "Que desea hacer?" << endl;
						int opc;
						color(10); cout << "[1] Jugar -- [2] Pasar -- [0] Terminar Juego" << endl; color(15);
						opc = evaluarInt(2, 0);
						switch (opc) {
						case 1:
							gotoxy(67, 9); cout << "Cuantas fichas desea insertar al tablero?";
							int cantFichasIngresar;
							cantFichasIngresar = evaluarInt(7, 2);
							for (int i = 0; i < cantFichasIngresar; i++) {
								gotoxy(67, 10); cout << "Digite la letra: ";
								bool verifica = true;
								while (verifica) {
									if (!(cin >> letraEligida)) {
										cin.clear();
										cin.ignore();
									}
									else {
										if (letraEligida.length() == 1 && jugador2->getLista()->encotrada(toUpper(letraEligida))) {
											cin.clear();
											cin.ignore();
											verifica = false;
										}
										else {
											cin.clear();
											cin.ignore();
										}
									}
								}
								letraEligida = toUpper(letraEligida);
								gotoxy(83, 10); cout << letraEligida;
								gotoxy(67, 12);
								cout << "Digite la columna: (A,B,C,...)";
								col = evaluarChar();
								gotoxy(67, 13);
								cout << "Digite la fila: (1,2,3,...)";
								fil = evaluarInt(15, 1);
								tablero->insertarFicha(fil, col, letraEligida);
								jugador2->getLista()->sacarFicha(letraEligida);
								ficha = new Ficha(letraEligida, valorFicha(letraEligida));
								listaTablero->insertarFicha(ficha);
								system("cls");
								turnoJugador(cont + 1, jugador2->getNombre());
								tablero->imprimeTablero();
								jugador2->cuadroFichas();
							}
							break;
						case 2:
							cout << "Pasar Turno!" << endl;
							if (paso = 1) {
								paso++;
								cout << "Juego Terminado!" << endl;
							}
							else {
								paso = 0;
							}
							break;
						case 0:
							cout << "Juego Terminado!" << endl;
							paso = 2;
							break;
						default:
							break;
						}


						gotoxy(1, 24); 
						
						system("PAUSE");
						cont = 0;
					}
				}
				cout << "Ganador: ";

			}
			if (cantidadJugadores == 3) {
				cout << "Digite el nombre del jugador 1: ";
				getline(cin, nombreJugador);
				jugador1->setNombre(nombreJugador);
				cout << "Digite el nombre del jugador 2: ";
				getline(cin, nombreJugador);
				jugador2->setNombre(nombreJugador);
				cout << "Digite el nombre del jugador 3: ";
				getline(cin, nombreJugador);
				jugador3->setNombre(nombreJugador);
			}
			if (cantidadJugadores == 4) {
				cout << "Digite el nombre del jugador 1: ";
				getline(cin, nombreJugador);
				jugador1->setNombre(nombreJugador);
				cout << "Digite el nombre del jugador 2: ";
				getline(cin, nombreJugador);
				jugador2->setNombre(nombreJugador);
				cout << "Digite el nombre del jugador 3: ";
				getline(cin, nombreJugador);
				jugador3->setNombre(nombreJugador);
				cout << "Digite el nombre del jugador 4: ";
				getline(cin, nombreJugador);
				jugador4->setNombre(nombreJugador);
			}
			delete jugador1;
			delete jugador2;
			delete jugador3;
			delete jugador4;
			delete listaTablero;
			delete bolsaFichas;
			cout << bolsaFichas->cantidadFichas() << endl;
			break;
		case 2:
			system("cls");
			
			system("PAUSE");
			break;
		case 3:
			system("cls");

			break;
		case 4:
			system("cls");

			break;
		case 0:
			system("cls");
			menuCiclo = false;
			break;
		default:
			system("cls");
			break;
		}
	}



}
void Control::leeFichas() {}
Control::~Control(){}

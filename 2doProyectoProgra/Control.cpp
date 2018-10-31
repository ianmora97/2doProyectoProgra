#include "Control.h"
Control::Control(){}
void Control::opciones() {
	color(15);
	//---Variables de ciclos---
	srand(time(NULL));
	Diccionario *dic = new Diccionario;
	dic->readFile();

	bool _cicloMenu = true;
	while (_cicloMenu == true) {
		Interfaz *interfaz = new Interfaz;
		ListaFichas *bolsaFichas = new ListaFichas;
		ListaFichas *listaTablero = new ListaFichas;
		Tablero *tablero = new Tablero;
		Funcionalidad *game = new Funcionalidad;
		Ficha *ficha;
		Jugador *jugador1 = new Jugador("indef");
		Jugador *jugador2 = new Jugador("indef");
		Jugador *jugador3 = new Jugador("indef");
		Jugador *jugador4 = new Jugador("indef");

		system("cls");
		game->llenarLista(bolsaFichas); // llena la lista
		color(13);
		tablero->imprimeScrabble();
		color(15);
		interfaz->imprime();
		int opc;
		opc = interfaz->menu();
		//interfaz->cuadros();
		system("cls");
		if (opc == 1) {
			game->setCantidadJugadores();
			int _cantidadJugadores = evaluarInt(4, 2);
			if (_cantidadJugadores == 2) {
				cout << "\t___________________________________________________________\n";
				game->setJugador(jugador1, bolsaFichas, 1);
				game->setJugador(jugador2, bolsaFichas, 2);
				cin.get();
				system("cls");
				int turno = 0;
				int pasar = 0;
				string palabra;
				string _letra;
				
				while (!(bolsaFichas->vacia()) && !(jugador1->getLista()->vacia()) && !(jugador2->getLista()->vacia()) && pasar != 2) {
					if (turno % 2 == 0) {
						system("cls");
						jugador1->turnoJugador();
						tablero->imprimeTablero();
						jugador1->getLista()->getLetras();
						int opcGame = game->menu();
						if (opcGame == 1) {
							system("cls");
							jugador1->turnoJugador();
							tablero->imprimeTablero();
							jugador1->getLista()->getLetras();

							//nuevo
							if (!(tablero->verificaPosicion(7,7))) {
								bool hv;
								bool cicloLetra = true;
								while (cicloLetra) {
									do {
										palabra = game->pidePalabra();
									} while (!game->verificaDiccionario(dic, palabra));
									if (game->verificaLetras(jugador1, palabra)) {
										hv = game->horiVert();
										gotoxy(72, 20);
										if (game->ingresarPalabra(tablero, palabra, 8, 'H', hv, jugador1, listaTablero)) {
											system("cls");
											jugador1->turnoJugador();
											tablero->imprimeTablero();
											game->meteFichas(jugador1, bolsaFichas, palabra.length());
											jugador1->getLista()->getLetras();
											cicloLetra = false;
											gotoxy(72, 10);
											cout << "Palabra ingresada correctamente!";
											gotoxy(72, 11); 
											cout << toUpper(palabra);
											gotoxy(72, 12); cin.get();
										}
									}
								}
							}
							else {
								//metodo para ingresar ficha por ficha
								cout<<game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador1, dic);
								cin.get();
								cin.get();
							}
							

							//!nuevo
							turno++;
						}
						else if (opcGame == 2) {
							system("cls");
							jugador1->turnoJugador();
							tablero->imprimeTablero();
							jugador1->cambiarFichas(bolsaFichas);
							cin.get();
							turno++;
						}
						else if (opcGame == 3) {
							turno++;
							pasar++;
						}
						else if (opcGame == 4) {
							pasar = 2;
						}
						
					}
					else {
						system("cls");
						jugador2->turnoJugador();
						tablero->imprimeTablero();
						jugador2->getLista()->getLetras();
						int opcGame = game->menu();
						if (opcGame == 1) {
							system("cls");
							jugador2->turnoJugador();
							tablero->imprimeTablero();
							jugador2->getLista()->getLetras();
							//nuevo
							if (!(tablero->verificaPosicion(7, 7))) {
								bool hv;
								bool cicloLetra = true;
								while (cicloLetra) {
									do {
										palabra = game->pidePalabra();
									} while (!game->verificaDiccionario(dic, palabra));
									if (game->verificaLetras(jugador2, palabra)) {
										hv = game->horiVert();
										gotoxy(72, 20);
										if (game->ingresarPalabra(tablero, palabra, 8, 'H', hv, jugador2, listaTablero)) {
											system("cls");
											jugador2->turnoJugador();
											tablero->imprimeTablero();
											game->meteFichas(jugador2, bolsaFichas, palabra.length());
											jugador2->getLista()->getLetras();
											cicloLetra = false;
											gotoxy(72, 10);
											cout << "Palabra ingresada correctamente!";
											gotoxy(72, 11);
											cout << toUpper(palabra);
											gotoxy(72, 12); cin.get();
										}
									}
								}
							}
							else {
								//metodo para ingresar ficha por ficha
								cout << game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador2, dic);
								cin.get();
								cin.get();
							}
							//!nuevo
							turno++;
						}
						else if (opcGame == 2) {
							system("cls");
							jugador1->turnoJugador();
							tablero->imprimeTablero();
							jugador2->cambiarFichas(bolsaFichas);
							turno++;
						}
						else if (opcGame == 3) {
							turno++;
							pasar == 1 ? pasar++ : pasar = 0;
						}
						else if (opcGame == 4) {
							pasar = 2;
						}
						
					}
				}
			}
			else if (_cantidadJugadores == 3) {

			}
			else if (_cantidadJugadores == 4) {

			}
			system("cls");
			cout << "El ganador es: " << endl;
			game->guardarPuntaje(jugador1);
			cout << endl;
			cin.get();
		}
		else if (opc == 2) {
			system("cls");
			instrucciones1();
			instrucciones2();
			instrucciones3();
		}
		else if (opc == 3) {
			game->leerPuntaje();
		}
		else if (opc == 4) {

		}
		else if (opc == 0) {
			_cicloMenu = false;
		}
		else {
			_cicloMenu = true;
		}
		delete bolsaFichas;
		delete tablero;
		delete jugador1;
		delete jugador2;
		delete jugador3;
		delete jugador4;
		delete listaTablero;
	}
	delete dic;
}
Control::~Control(){}

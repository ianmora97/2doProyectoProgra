#include "Control.h"
Control::Control(){}
void Control::opciones() {
	color(15);
	//---Variables de ciclos---
	srand(time(NULL));
	Funcionalidad *game = new Funcionalidad;
	Diccionario *dic = new Diccionario;
	game->readFile(dic);
	bool _cicloMenu = true;
	while (_cicloMenu == true) {
		Interfaz *interfaz = new Interfaz;
		ListaFichas *bolsaFichas = new ListaFichas;
		ListaFichas *listaTablero = new ListaFichas;
		Tablero *tablero = new Tablero;
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
				pause();
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
								if (game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador1, dic)) {
									system("cls");
									jugador1->turnoJugador();
									tablero->imprimeTablero();
									jugador1->getLista()->getLetras();
									cin.get();
									turno++;
								}
							}
							else {
								if (game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador1, dic)) {
									system("cls");
									jugador1->turnoJugador();
									tablero->imprimeTablero();
									jugador1->getLista()->getLetras();
									cin.get();
									turno++;
								}
							}
							//!nuevo
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
							if (!(tablero->verificaPosicion(7, 7))) {
								if (game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador2, dic)) {
									system("cls");
									jugador2->turnoJugador();
									tablero->imprimeTablero();
									jugador2->getLista()->getLetras();
									cin.get();
									turno++;
								}
							}
							else {
								if (game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador2, dic)) {
									system("cls");
									jugador2->turnoJugador();
									tablero->imprimeTablero();
									jugador2->getLista()->getLetras();
									cin.get();
									turno++;
								}
							}
						}
						else if (opcGame == 2) {
							system("cls");
							jugador2->turnoJugador();
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
				cout << "\t___________________________________________________________\n";
				game->setJugador(jugador1, bolsaFichas, 1);
				game->setJugador(jugador2, bolsaFichas, 2);
				game->setJugador(jugador3, bolsaFichas, 3);
				pause();
				system("cls");
				int turno = 1;
				int pasar = 0;
				string palabra;
				while (!(bolsaFichas->vacia()) && !(jugador1->getLista()->vacia()) && !(jugador2->getLista()->vacia()) && !(jugador3->getLista()->vacia()) && pasar != 3) {
					if (turno == 1) {
						system("cls");
						jugador1->turnoJugador();
						tablero->imprimeTablero();
						jugador1->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador1->turnoJugador();
								tablero->imprimeTablero();
								jugador1->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador1, dic);
								
								turno++;
							}
							else {
								system("cls");
								jugador1->turnoJugador();
								tablero->imprimeTablero();
								jugador1->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador1, dic);

								turno++;
							}
							break;
						case 2:
							system("cls");
							jugador1->turnoJugador();
							tablero->imprimeTablero();
							jugador1->cambiarFichas(bolsaFichas);
							turno++;
							break;
						case 3:
							system("cls");
							turno++;
							pasar++;
							break;
						case 4:
							pasar = 3;
						default:
							break;
						}
					}
					if (turno == 2) {
						system("cls");
						jugador2->turnoJugador();
						tablero->imprimeTablero();
						jugador2->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador2->turnoJugador();
								tablero->imprimeTablero();
								jugador2->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador2, dic);
								
								turno++;
							}
							else {
								system("cls");
								jugador2->turnoJugador();
								tablero->imprimeTablero();
								jugador2->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador2, dic);
								turno++;
							}
							break;
						case 2:
							system("cls");
							jugador2->turnoJugador();
							tablero->imprimeTablero();
							jugador2->cambiarFichas(bolsaFichas);
							turno++;
							break;
						case 3:
							system("cls");
							turno++;
							pasar++;
							break;
						case 4:
							pasar = 3;
						default:
							break;
						}
					}
					if (turno == 3) {
						system("cls");
						jugador3->turnoJugador();
						tablero->imprimeTablero();
						jugador3->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador3->turnoJugador();
								tablero->imprimeTablero();
								jugador3->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador3, dic);
								
								turno = 1;
							}
							else {
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador3, dic);
								system("cls");
								jugador3->turnoJugador();
								tablero->imprimeTablero();
								jugador3->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador3, dic);
								turno = 1;
							}
							break;
						case 2:
							system("cls");
							jugador3->turnoJugador();
							tablero->imprimeTablero();
							jugador3->cambiarFichas(bolsaFichas);
							turno = 1;
							break;
						case 3:
							system("cls");
							turno = 1;
							pasar == 2 ? pasar++ : pasar = 0;
							break;
						case 4:
							pasar = 3;
						default:
							break;
						}
					}
				}
			}
			else if (_cantidadJugadores == 4) {
				cout << "\t___________________________________________________________\n";
				game->setJugador(jugador1, bolsaFichas, 1);
				game->setJugador(jugador2, bolsaFichas, 2);
				game->setJugador(jugador3, bolsaFichas, 3);
				game->setJugador(jugador4, bolsaFichas, 4);
				pause();
				system("cls");
				int turno = 0;
				int pasar = 0;
				string palabra;
				while (!(bolsaFichas->vacia()) && !(jugador1->getLista()->vacia()) && !(jugador2->getLista()->vacia()) && !(jugador3->getLista()->vacia()) && !(jugador4->getLista()->vacia()) && pasar != 4) {
					if (turno == 1) {
						system("cls");
						jugador1->turnoJugador();
						tablero->imprimeTablero();
						jugador1->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador1->turnoJugador();
								tablero->imprimeTablero();
								jugador1->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador1, dic);
								
								turno++;
							}
							else {
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador1, dic);
								system("cls");
								jugador1->turnoJugador();
								tablero->imprimeTablero();
								jugador1->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador1, dic);
								turno++;
							}
							break;
						case 2:
							system("cls");
							jugador2->turnoJugador();
							tablero->imprimeTablero();
							jugador1->cambiarFichas(bolsaFichas);
							turno++;
							break;
						case 3:
							system("cls");
							turno++;
							pasar++;
							break;
						case 4:
							pasar = 4;
						default:
							break;
						}
					}
					if (turno == 2) {
						system("cls");
						jugador2->turnoJugador();
						tablero->imprimeTablero();
						jugador2->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador2->turnoJugador();
								tablero->imprimeTablero();
								jugador2->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador2, dic);
								
								turno++;
							}
							else {
								
								system("cls");
								jugador2->turnoJugador();
								tablero->imprimeTablero();
								jugador2->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador2, dic);
								turno++;
							}
							break;
						case 2:
							system("cls");
							jugador2->turnoJugador();
							tablero->imprimeTablero();
							jugador2->cambiarFichas(bolsaFichas);
							turno++;
							break;
						case 3:
							system("cls");
							turno++;
							pasar++;
							break;
						case 4:
							pasar = 4;
						default:
							break;
						}
					}
					if (turno == 3) {
						system("cls");
						jugador3->turnoJugador();
						tablero->imprimeTablero();
						jugador3->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador3->turnoJugador();
								tablero->imprimeTablero();
								jugador3->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador3, dic);
								
								turno++;
							}
							else {
								
								system("cls");
								jugador3->turnoJugador();
								tablero->imprimeTablero();
								jugador3->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador3, dic);
								turno++;
							}
							break;
						case 2:
							system("cls");
							jugador3->turnoJugador();
							tablero->imprimeTablero();
							jugador3->cambiarFichas(bolsaFichas);
							turno++;
							break;
						case 3:
							system("cls");
							turno++;
							pasar++;
							break;
						case 4:
							pasar = 4;
						default:
							break;
						}
					}
					if (turno == 4) {
						system("cls");
						jugador4->turnoJugador();
						tablero->imprimeTablero();
						jugador4->getLista()->getLetras();
						int opc = game->menu();
						switch (opc) {
						case 1:
							if (!(tablero->verificaPosicion(7, 7))) {
								system("cls");
								jugador4->turnoJugador();
								tablero->imprimeTablero();
								jugador4->getLista()->getLetras();
								game->ingresarPalabra(tablero, bolsaFichas, listaTablero, jugador4, dic);
								
								turno = 1;
							}
							else {
								
								system("cls");
								jugador4->turnoJugador();
								tablero->imprimeTablero();
								jugador4->getLista()->getLetras();
								game->ingresarFichaXFicha(tablero, bolsaFichas, listaTablero, jugador4, dic);
								turno = 1;
							}
							break;
						case 2:
							system("cls");
							jugador4->turnoJugador();
							tablero->imprimeTablero();
							jugador4->cambiarFichas(bolsaFichas);
							turno = 1;
							break;
						case 3:
							system("cls");
							turno = 1;
							pasar == 3 ? pasar++ : pasar = 0;
							break;
						case 4:
							pasar = 4;
						default:
							break;
						}
					}
				}
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
		system("cls");
		leerFichero("Palabra/palabrasCreadas.txt");
		pause();
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

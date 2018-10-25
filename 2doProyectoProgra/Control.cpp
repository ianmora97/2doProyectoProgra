#include "Control.h"
Control::Control(){}
void Control::opciones() {
	Herramientas::color(15);
	//---Variables de ciclos---
	srand(time(NULL));
	bool _cicloMenu = true;
	while (_cicloMenu == true) {
		
		Interfaz *interfaz = new Interfaz;
		ListaFichas *bolsaFichas = new ListaFichas;
		ListaFichas *listaTablero = new ListaFichas;
		Tablero *tablero = new Tablero;
		Funcionalidad *game = new Funcionalidad;

		Jugador *jugador1 = new Jugador("indef");
		Jugador *jugador2 = new Jugador("indef");
		Jugador *jugador3 = new Jugador("indef");
		Jugador *jugador4 = new Jugador("indef");
		Ficha *ficha;

		system("cls");
		game->llenarLista(bolsaFichas); // llena la lista
		Herramientas::color(13);
		tablero->imprimeScrabble();
		Herramientas::color(15);
		interfaz->imprime();
		int opc;
		opc = interfaz->menu();
		//interfaz->cuadros();
		system("cls");
		if (opc == 1) {
			game->setCantidadJugadores();
			int _cantidadJugadores = Herramientas::evaluarInt(4, 2);
			if (_cantidadJugadores == 2) {
				cout << "\t___________________________________________________________\n";
				game->setJugador(jugador1, bolsaFichas, 1);
				game->setJugador(jugador2, bolsaFichas, 2);
				system("cls");
				int turno = 0;
				int pasar = 0;
				
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
							string palabra;
							getline(cin, palabra, END);
							if (game->verificaLetras(jugador1, palabra)) {

							}
							
							cin.get();

							//!nuevo
							turno++;
						}
						else if (opcGame == 2) {
							turno++;
							pasar == 1 ? pasar++ : pasar = 0;
						}
						else if (opcGame == 3) {
							pasar = 2;
						}
						
					}
					else {
						system("cls");
						jugador2->turnoJugador();
						tablero->imprimeTablero();
						jugador1->getLista()->getLetras();
						int opcGame = game->menu();
						if (opcGame == 1) {
							system("cls");
							jugador2->turnoJugador();
							tablero->imprimeTablero();
							jugador2->getLista()->getLetras();
							
							turno++;
						}
						else if (opcGame == 2) {
							turno++;
							pasar == 1 ? pasar++ : pasar = 0;
						}
						else if (opcGame == 3) {
							pasar = 2;
						}
						
					}
				}
				system("cls");
				cout << "El ganador es: "<<endl;
				cout << endl;
				Herramientas::gotoxy(1,105); system("PAUSE");
				
			}
			else if (_cantidadJugadores == 3) {

			}
			else if (_cantidadJugadores == 4) {

			}
		
		}
		else if (opc == 2) {
			system("cls");
			Herramientas::instrucciones1();
			Herramientas::instrucciones2();
			Herramientas::instrucciones3();
		}
		else if (opc == 3) {

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
}
Control::~Control(){}

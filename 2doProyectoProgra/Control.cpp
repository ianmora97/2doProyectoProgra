#include "Control.h"
Control::Control(){}
void Control::opciones() {
	Herramientas::color(15);
	Interfaz *interfaz = new Interfaz;
	ListaFichas *bolsaFichas = new ListaFichas;
	ListaFichas *listaTablero = new ListaFichas;
	Tablero *tablero = new Tablero;
	Funcionalidad *game = new Funcionalidad;

	//---Variables de ciclos---
	bool menuCiclo = true;
	srand(time(NULL));
	//---Variables de jugadores---
	Jugador *jugador1 = new Jugador("indef");
	Jugador *jugador2 = new Jugador("indef");
	Jugador *jugador3 = new Jugador("indef");
	Jugador *jugador4 = new Jugador("indef");
	Ficha *ficha;
	//---!Variables de jugadores---
	bool _cicloMenu = true;
	while (_cicloMenu == true) {
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
				while (!(bolsaFichas->vacia()) || !(jugador1->getLista()->vacia()) || !(jugador2->getLista()->vacia()) || pasar != 2) {
					if (turno % 2 == 0) {
						system("cls");
						turnoJugador(1,jugador1->getNombre());
						tablero->imprimeTablero();
						int opcGame = game->menu();
						if (opcGame == 1) {
							system("cls");
							turnoJugador(1, jugador1->getNombre());
							tablero->imprimeTablero();
							jugador1->getLista();
							
						}

					}
					else {

					}
				}
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
	}
}
Control::~Control(){}

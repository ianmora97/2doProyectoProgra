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
	Ficha *ficha;
	//---!Variables de jugadores---
	
	//--Variables contadores--
	int cantidadJugadores;
	srand(time(NULL));
	string fichasacada;
	string letraElegida;
	char col;
	int fil;
	string letrasSacadas[100];
	int cantLetrasSacadas = 0;
	int filAnterior, colAnterior;
	int valor;
	string matrizRevisa[15][15];
	//--!Variables contadores--
	while (menuCiclo == true) {
		//--------------------Ingresar las fichas en la lista------------------------
		bolsaFichas->llenarLista();
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
				for (int i = 0; i < 7; i++) { //reparte las fichas al jugador
					fichasacada = randomFichas(); //llama al metodo de random para sacar un numero en especifico
					fichaJugador = new Ficha(fichasacada, valorFicha(fichasacada)); //hace una ficha y con su letra y valor
					bolsaFichas->sacarFicha(fichasacada); //saca las fichas de la bolsa de fichas
					jugador1->insertarficha(fichaJugador); //ingresa la ficha en la lista de fichas del jugador
					letrasSacadas[cantLetrasSacadas] = fichasacada; //guarda en un vector las fichas que fueron sacadas de la bolsa
					cantLetrasSacadas++; //contador para saber cuantas fichas hay
				}
				for (int i = 0; i < 7; i++) { //reparte las fichas al jugador 2
					for (int a = 0; a < cantLetrasSacadas; a++) { //un ciclo que verifique si las fichas repartidas ya estan repetidas
						fichasacada = randomFichas(); //llama al metodo random 
						if (letrasSacadas[a] != fichasacada) { //verifia que la ficha no este repartida y llama de nuevo al metodo random
							letraElegida = fichasacada; //la letraElegida va a ser la letra que se va a ingresar
						}
					}
					fichaJugador = new Ficha(letraElegida, valorFicha(letraElegida)); //hace un objeto tipo ficha
					bolsaFichas->sacarFicha(letraElegida); //saca la ficha de la bolsa de fichas
					jugador2->insertarficha(fichaJugador); //se le da la ficha al jugador 2
					letrasSacadas[cantLetrasSacadas] = letraElegida; //ingresa la letra en el vector de letras sacadas de la bolsa
					cantLetrasSacadas++; //contador para saber cuantas fichas hay
				}
				system("cls");
				int cont = 0; //contador para el turno del jugador
				while ( (!(bolsaFichas->vacia())) && (!(jugador1->getLista()->vacia()) || !(jugador2->getLista()->vacia())) && (paso != 2)) { //verifica que hayan fichas en la bolsa
					if (cont % 2 == 0) {//si el contador es par el jugador 1 va primero													//en que los jugadores tengan fichas, y que no hayan pasado mas de 2 veces
						system("cls");
						turnoJugador(cont+1, jugador1->getNombre()); //muestra el turno del jugador
						tablero->imprimeTablero(); //imprime el tablero
						jugador1->cuadroFichas(); //muestra las fichas del jugador
						gotoxy(1,24); 
						cout << "Que desea hacer?"<<endl;
						int opc;
						bool _revisa; //devuelve true si es correcto en la matriz : false
						color(10); cout << "[1] Jugar -- [2] Pasar -- [0] Terminar Juego" << endl; color(15); //opcion del jugador
						opc = evaluarInt(2,0); //evalua el int
						switch (opc){
						case 1:
							gotoxy(67,9); cout << "Cuantas fichas desea insertar al tablero?"; //mueve el cursor a una segunda columna de la pantalla
							int cantFichasIngresar;
							cantFichasIngresar = evaluarInt(7,2);
							for (int i = 0; i < cantFichasIngresar; i++) { //ingresa fichas hasta que termine la cantidad de fichas por ingresar
								if (listaTablero->vacia()) { //si es la primer jugada debe ingresar la letra en el centro
									gotoxy(67, 10); cout << "Digite la letra: "; //digita la columna del tablero
									bool verifica = true;
									while (verifica) {
										if (!(cin >> letraElegida)) {
											cin.clear();
											cin.ignore();
										}
										else {
											if (letraElegida.length() == 1 && jugador1->getLista()->encotrada(toUpper(letraElegida))) {
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
									letraElegida = toUpper(letraElegida); //pasa la letra a mayuscula
									gotoxy(84, 10); cout << letraElegida;
									gotoxy(67, 12);
									cout << "La primer letra es en el centro";
									
									col = 'H';
									fil = 8;
									matrizRevisa[fil][charXColumna(col)] = letraElegida;
									filAnterior = 8;
									colAnterior = charXColumna(col);
									_revisa = true;
								}
								else {
									gotoxy(67, 10); cout << "Digite la letra: "; //digita la columna del tablero
									bool verifica = true;
									while (verifica) {
										if (!(cin >> letraElegida)) {
											cin.clear();
											cin.ignore();
										}
										else {
											if (letraElegida.length() == 1 && jugador1->getLista()->encotrada(toUpper(letraElegida))) {
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
									letraElegida = toUpper(letraElegida); //pasa la letra a mayuscula
									gotoxy(84, 10); cout << letraElegida;
									gotoxy(67, 12);
									cin.clear();
									cin.ignore();
									cout << "Digite la columna: (A,B,C,...)";
									col = evaluarChar();
									gotoxy(67, 13);
									cout << "Digite la fila: (1,2,3,...)";
									
									fil = evaluarInt(15, 1);
									if (matrizRevisa[filAnterior + 1][colAnterior] == letraElegida || matrizRevisa[filAnterior][colAnterior + 1] == letraElegida) {
										_revisa = true;
										filAnterior = fil;
										colAnterior = charXColumna(col);
									}
									else {
										_revisa = false;
									}									
								}
								if (_revisa == true) {
									tablero->insertarFicha(fil, col, letraElegida); //inserta la ficha en el tablero
									jugador1->getLista()->sacarFicha(letraElegida); //saca la ficha del jugador 
									jugador1->setPuntaje(valorFicha(letraElegida)); //se suma al puntaje del jugador la ficha
									ficha = new Ficha(letraElegida, valorFicha(letraElegida)); //se hace un objeto tipo ficha con la letra y el puntaje
									listaTablero->insertarFicha(ficha); //inserta la ficha en la lista del tablero
									system("cls");
									turnoJugador(cont + 1, jugador1->getNombre()); //muestra por pantalla el nombre del jugador
									tablero->imprimeTablero(); //imprime el tablero
									jugador1->cuadroFichas(); //mustra las fichas restantes
								}
								else {
									cantFichasIngresar--;
								}
							}
							break;
						case 2:
							cout << "Pasar Turno!" << endl; //si pasa el turno al paso se le suma uno
							paso = 0;
							paso++;
							break;
						case 0:
							cout << "Juego Terminado!" << endl; //si se termina el juego el paso es 2
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
						bool _revisa;
						switch (opc) {
						case 1:
							gotoxy(67, 9); cout << "Cuantas fichas desea insertar al tablero?";
							int cantFichasIngresar;
							cantFichasIngresar = evaluarInt(7, 2);
							for (int i = 0; i < cantFichasIngresar; i++) {
								if (listaTablero->vacia()) {
									gotoxy(67, 10); cout << "Digite la letra: ";
									bool verifica = true;
									while (verifica) {
										if (!(cin >> letraElegida)) {
											cin.clear();
											cin.ignore();
										}
										else {
											if (letraElegida.length() == 1 && jugador2->getLista()->encotrada(toUpper(letraElegida))) {
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
									letraElegida = toUpper(letraElegida);
									gotoxy(83, 10); cout << letraElegida;
									gotoxy(67, 12);
									cin.clear();
									cin.ignore();
									cout << "Digite la columna: (A,B,C,...)";
									gotoxy(67, 13);
									cout << "Digite la fila: (1,2,3,...)";
									col = 'H';
									fil = 8;
									_revisa = true;
									
								}
								else {
									gotoxy(67, 10); cout << "Digite la letra: ";
									bool verifica = true;
									while (verifica) {
										if (!(cin >> letraElegida)) {
											cin.clear();
											cin.ignore();
										}
										else {
											if (letraElegida.length() == 1 && jugador2->getLista()->encotrada(toUpper(letraElegida))) {
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
									letraElegida = toUpper(letraElegida);
									gotoxy(83, 10); cout << letraElegida;
									gotoxy(67, 12);
									cout << "Digite la columna: (A,B,C,...)";
									col = evaluarChar();
									gotoxy(67, 13);
									cout << "Digite la fila: (1,2,3,...)";
									fil = evaluarInt(15, 1);
									if (matrizRevisa[filAnterior + 1][colAnterior] == letraElegida || matrizRevisa[filAnterior][colAnterior + 1] == letraElegida) {
										_revisa = true;
										filAnterior = fil;
										colAnterior = charXColumna(col);
									}
									else {
										_revisa = false;
									}
								}
								if (_revisa == true) {
									tablero->insertarFicha(fil, col, letraElegida);
									jugador2->getLista()->sacarFicha(letraElegida);
									ficha = new Ficha(letraElegida, valorFicha(letraElegida));
									listaTablero->insertarFicha(ficha);
									system("cls");
									turnoJugador(cont + 1, jugador2->getNombre());
									tablero->imprimeTablero();
									jugador2->cuadroFichas();
								}
								else {
									cantFichasIngresar--;
								}
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
			instrucciones1();
			instrucciones2();
			instrucciones3();
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

#include "Jugador.h"
Jugador::Jugador(string nombre) : nombreJugador(nombre), canFichas(0), puntajeJugador(0) { listaFichas = new ListaFichas; }
string Jugador::getNombre() {return nombreJugador;}
int Jugador::getPuntaje() {return puntajeJugador;}
int Jugador::getCanFichas(){return canFichas;}
void Jugador::setCantidadDeVictorias(int cantvic) { cantidadDeVictorias = cantvic; }
int Jugador::getCantidadDeVictorias() { return cantidadDeVictorias; }
void Jugador::setPuntaje(int p) {puntajeJugador = puntajeJugador + p;}
void Jugador::setNombre(string nombre) { nombreJugador = nombre; }
void Jugador::insertarficha(Ficha * ficha) { 
	listaFichas->insertarFicha(ficha);
	canFichas++;
}
bool Jugador::sacarFicha(string l) {
	if (listaFichas->sacarFicha(l)) {
		canFichas--;
		return true;
	}
	return false;
}
void Jugador::turnoJugador() {
	//cout << "\n\tTurno de:";
	dibujaRectangulo(8,50,1,6,15);
	color(15); gotoxy(9, 2); color(13); cout << " Turno del Jugador   : "; color(15); cout << nombreJugador;
	color(15); gotoxy(9, 3); color(13); cout << " Puntaje del Jugador : "; color(15); cout << puntajeJugador;
	color(15); gotoxy(9, 4); color(13); cout << " Cantidad de Fichas  : "; color(15); cout << listaFichas->getCantidadNodos();
}
string Jugador::toString() {
	stringstream s;
	s << "Nombre del Jugador: " << nombreJugador << endl;
	s << "Puntaje del Jugador: " << puntajeJugador << endl;
	s << "Cantidad de Fichas: " << canFichas << endl;
	return s.str();
}
string Jugador::toStringLetras() {
	stringstream p;
	p <<listaFichas->letras()<<endl;
	return p.str();
}
ListaFichas * Jugador::getLista() { return listaFichas; }
void Jugador::cambiarFichas(ListaFichas *lista) {
	string letraSacada;
	string letra;
	Ficha *ficha;
	Ficha *fichaSacada;
	int opc = 0;
	int cont = 0;
	bool ciclo = true;
	do {
		listaFichas->getLetras();
		gotoxy(72, 11); cout << "                                          ";
		gotoxy(72, 13); cout << "                                          ";
		gotoxy(72, 15); cout << "                                          ";
		gotoxy(72, 16); cout << "                                          ";
		gotoxy(72, 17); cout << "                                          ";
		gotoxy(72, 11); cout << "Que letra desea cambiar? > ";
		color(13); getline(cin, letraSacada, END);
		letraSacada = toUpper(letraSacada);
		if (listaFichas->sacarFicha(letraSacada)) { //saco la letra de la lista del jugador
			for (int i = 0; i < 1; i++) {
				letra = randomFichas();
				if ((lista->sacarFicha(letra))) { //saco una ficha de la bolsa de fichas
					ficha = new Ficha(letra, valorFicha(letra));
					listaFichas->insertarFicha(ficha); //se la asigno a la lista de fichas del jugador
					fichaSacada = new Ficha(letraSacada, valorFicha(letraSacada));
					lista->insertarFicha(fichaSacada); //meto una ficha en la bolsa de fichas
					cont++;
					ciclo = false;
				}
				else { //la letra no esta en la lista
					i--;
				}
			}
		}
		else {
			gotoxy(72, 13); color(12); cout << "La letra no se encuentra!";
		}
		listaFichas->getLetras();
		gotoxy(72, 15); cout << "Desea cambiar otra letra?" << endl;
		gotoxy(72, 16); color(13); cout << "[1]"; color(15); cout << " Si  ||  "; color(13); cout << "[2]"; color(15); cout<< " No";
		gotoxy(72, 17); opc = evaluarInt(2, 1);
	} while (opc == 1 && cont < 7);
}
void Jugador::autoGuardar(ofstream& archivo) {
	archivo << "  " << nombreJugador << "               " << puntajeJugador << "             " << cantidadDeVictorias << endl << endl;
}
void Jugador::guardarPalabras(ofstream &archivo, string palabra){
	archivo << " " << nombreJugador << "                 " << palabra << endl;
}
Jugador::~Jugador(){
	listaFichas->~ListaFichas();
	nombreJugador = "indef";
	puntajeJugador = 0;
	canFichas = 0;
}

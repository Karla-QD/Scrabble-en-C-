#include"Juego.h"


Juego::Juego() {
	this->scrabble = new Scrabble();
}

Juego::~Juego() {
	this->jugadores.clear();
}

void Juego::insertarJugador(Jugador* jugador) {
	this->jugadores.push_back(jugador);
}


//devuelve el ganador segun 2 condiciones, que haya empate entonces verifica quien tiene menor valor de letras 
// de lo contrario verifica quien tiene menor cantidad de letras.
Jugador* Juego::ganador() {  
	Jugador* gana = nullptr;
	for (int i = 0; i < this->jugadores.size(); i++) {
		{
			if (gana == nullptr) {
				gana = this->jugadores[i];
			}
			else {
				int j1 = gana->valorLetras();
				int j2 = this->jugadores[i]->valorLetras();
				if (gana->cantidadLetras() == this->jugadores[i]->cantidadLetras()) {
					if (j1 > j2) {
						gana = this->jugadores[i];
					}
				}
				if (gana->cantidadLetras() > this->jugadores[i]->cantidadLetras()) {
					gana = this->jugadores[i];
				}
			}
		}
	}
	return gana;
}

Jugador* Juego::jugadorRandom()
{
	srand((unsigned)time(nullptr));
	int numeroAleatorio = rand() % this->jugadores.size();
	return jugadores[numeroAleatorio];
}


Jugador* Juego::obtenerJugador(int pos) {
	return this->jugadores[pos];
}



std::vector<Jugador*> Juego::getJugadores()
{
	return std::vector<Jugador*>();
}

int Juego::devolverPosicion(std::string nombre)
{
	for (int i = 0; i < jugadores.size(); i++) {
		if (jugadores[i]->getNombre() == nombre)
			return i;
	}
	return 0;
}

int Juego::devolverCantidad()
{
	return jugadores.size();
}


void Juego::eliminarLetras(std::string palabra, Jugador* jugador)
{
	for (int i = 0; i < palabra.size(); i++) {
		if (jugador->buscarLetra(palabra[i])) {
			jugador->eliminarLetras(palabra[i]);
		}
	}
}

bool Juego::pasarTurno() {
	return true;
}

bool Juego::verificar(std::string palabra) {
	std::ifstream archivo("Palabras.txt");
	std::string texto = "";
	if (archivo) {
		while (std::getline(archivo, texto)) {
			if (texto != "") {
				if (texto == palabra) {
					return true;
				}
			}
		}
		archivo.close();
		return false;
	}
}






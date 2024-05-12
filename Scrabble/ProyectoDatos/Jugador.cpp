#include "Jugador.h"
#include<Windows.h>
#include"Colores.h"
//by vero
Jugador::Jugador(std::string nombre) {
	this->nombre = nombre ;
	this->vec = BancoLetras::getInstancia()->enviarLetras();
}

Jugador::~Jugador(){}

std::string Jugador::toString() {
	std::stringstream s;
	s << CYAN "Nombre jugador   : " << this->nombre << std::endl;
	s << CYAN "Letras del jugador  : ";
	for (int i = 0; i < this->vec.size(); i++) {
		s << this->vec[i] << " ";
	}
	return s.str();
}

int Jugador::cantidadLetras() {
	return this->vec.size();
}

bool Jugador::eliminarLetras(char c) {
	for (int i = 0; i < this->vec.size(); i++) {
		if (this->vec[i] == c) {
			this->vec.erase(this->vec.begin() + i);
			return true;
		}
	}
	return false;
}

bool Jugador::buscarLetra(char letra) {
	for (int i = 0; i < this->vec.size(); i++) {
		if (this->vec[i] == letra)
			return true;
	}
	return false;
}

int Jugador::valorLetras()
{
	int valor = 0;
	for (int i = 0; i < this->vec.size();i++) {
		valor += this->vec[i];
	}
	return valor;
}

std::string Jugador::getNombre()
{
	return this->nombre;
}

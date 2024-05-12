
#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

#include"BancoLetras.h"

class Jugador {
private:
	std::string nombre;
	std::vector<char> vec; //vector para almacenar las letras que le son asignadas. 
public:
	Jugador(std::string);
	virtual~Jugador();
	std::string toString();
	int cantidadLetras(); //cantidad de letras que tiene el jugador
	bool eliminarLetras(char); // eliminar una especifica. 
	bool buscarLetra(char); //Buscar una letra en especifico dentro de el vector de letras. 
	int valorLetras(); //valor de las letras que tiene el jugador segun tabla ASCII. 
	std::string getNombre();
};


#pragma once
#include"NodoL.h"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

class ListaL
{
private:
	NodoL* primer;
	std::vector<std::pair<int, int>> coordenadas;
	int x;//coordenada
	int y;//coordeanda
public:
	ListaL();
	int getY();
	int getX();
	void setCoordenadas(char); //metodo para setear las coordenadas de la palabra. 
	void setCoordenadasPlantilla(char,int tam); //metodo para el funcionamiento de las coordenadas.
	std::vector<std::pair<int, int>> getCoordenadas();  //metodo para almacenar las coordenadas que ocupa una palabra. 
	virtual~ListaL();
	bool insertar(char); //metodo para insertar una letra en un nodo de la lista de forma horizontal
	NodoL* buscar(char); //devolver un nodo con una letra en especifico. 
	NodoL* getPrimer(); // obtiene el primer elemento de la lista. 
	bool esVacia();
	bool ingresarPorNodo(NodoL*); //metodo para ingresar a una lista por nodo horizontalmente
	bool ingresarPorNodoVertical(NodoL*);  //metodo para ingresar a una lista por nodo de forma vertical
	bool ingresarPorLetraVertical(char); // metodo para ingresar una letra a un nodo de la lista de forma vertical. 
	std::string toString();
	bool verificarPalabra(std::string palabra, char letra); //metod para verificar que las palabras sean iguales. 
	bool buscarPorLetra(char); 
	void setX(int x);
	void setY(int y);
	NodoL* coordenadaExistente(int x,int y); //metodo para ver si dos coordenadas son iguales. 
	std::string toStringLis();
};


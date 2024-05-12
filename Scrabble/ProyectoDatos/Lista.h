#pragma once
#include"Nodo.h"
#include<sstream>
//by vero
// tiene almacenadas todas las listas(palabras)
class Lista
{
private:
	Nodo* primero;
public:
	Lista();
	virtual ~Lista();
	Nodo* getPrimero();
	bool ingresar(ListaL*); //metodo para ingresar una lista de nodos que almacenan chars(palabras)
	std::string toString();
	bool esVacio();
	int cuentaNodos();
	NodoL* buscarPorCoordenada(int, int, char); //metodo para buscar una Lista en especifico por coordenadas
	std::string toStringLista(); //Imprime las listas con direccion de memoria en horizontal y vertical. 
};



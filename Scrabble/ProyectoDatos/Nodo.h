#pragma once
#ifndef NODO_CASILLA_H
#define NODO_CASILLA_H

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include"ListaL.h"


class Nodo
{
private:
	ListaL* dato;
	Nodo* siguiente; //enlaces  en horizontal
	Nodo* abajo;  //enlaces en vertical
public:
	Nodo(ListaL*, Nodo*, Nodo*);
	Nodo(ListaL*, Nodo*);
	virtual ~Nodo();
	ListaL* getDato();
	Nodo* getSiguiente();
	void setDato(ListaL*);
	void setSiguiente(Nodo*);
	Nodo* getAbajo();
	void setAbajo(Nodo*);
};


#endif

#pragma once
#include <iostream>
#include <sstream>

class NodoL
{
private:
	char letra;
	NodoL* siguiente;
	NodoL* abajo;
public:
	NodoL();
	NodoL(char, NodoL*, NodoL*);
	NodoL(char, NodoL*);

	virtual ~NodoL();
	char getLetra();
	NodoL* getSiguiente();
	void setLetra(char);
	void setSiguiente(NodoL*);
	NodoL* getAbajo();
	void setAbajo(NodoL*);
};


#pragma once
#include"NodoL.h"
#include "Colores.h"
#include"ListaL.h"
#include"Lista.h"
#include<sstream>

class Scrabble
{
private:
	NodoL* scrabble[11][11];
    Lista* lis;// lista que tenga listas de nodos que tengan char
public:
	Scrabble();
	virtual~Scrabble();
	std::string imprimir(); //imprime el scrabble
	bool insertar(int, int, char,char);
	NodoL* buscar(int x, int y); //buscar lista por coordenadas X y Y. 
	bool insertarPalabraLis(int x, int y, std::string palabra, char direccion); //metodo que maneja la insercion de palabras. 
	bool agregarNodoAListaExistente(int x, int y,std::string palabra,char direccion); //permite que no se duplique una lista si solamente hay una letra de diferencia. 
	//le agrega un nodo a la lista existente. 
	Lista* getLista();
	char ultimoCaracter(std::string palabra); //devuelve el ultimo caracter de un string. 
	bool palabraUnida(int x, int y, std::string palabra, char direccion);  //verificar que la palabra este enlazada a otra, de lo contrario no ingresa. 
	bool insertarPalabraSegunExistencia(int x, int y, std::string palabra, char direccion); //metodo que maneja la insercion de palabras.
};


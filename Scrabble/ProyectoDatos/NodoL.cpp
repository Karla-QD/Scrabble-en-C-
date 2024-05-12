#include "NodoL.h"

NodoL::NodoL() {
	this->siguiente = nullptr;
	this->abajo = nullptr;
	this->letra = ' ';
}

NodoL::NodoL(char l, NodoL* s) {
	this->letra = l;
	this->siguiente = s;
	this->abajo = nullptr;
}

NodoL::NodoL(char l, NodoL* s, NodoL* a) {
	this->letra = l;
	this->siguiente = s;
	this->abajo = a;
}

NodoL:: ~NodoL() {}

char NodoL:: getLetra() {
	return this->letra;	
}

NodoL* NodoL:: getSiguiente() {
	return this->siguiente;
}

void NodoL::setLetra(char l) {
	this->letra = l;
}

void NodoL::setSiguiente(NodoL* s) {
	this->siguiente = s;
}

NodoL* NodoL::getAbajo() {
	return this->abajo;
}

void NodoL::setAbajo(NodoL* a) {
	this->abajo = a;
}

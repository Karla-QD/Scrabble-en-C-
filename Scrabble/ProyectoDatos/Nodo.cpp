#include "Nodo.h"

Nodo::Nodo(ListaL* lis, Nodo* siguiente, Nodo* abajo) {
	this->dato = lis;
	this->siguiente = siguiente;
	this->abajo = abajo;

}

Nodo::~Nodo() {}

ListaL* Nodo::getDato() {
	return this->dato;
}

Nodo::Nodo(ListaL* l, Nodo* s) {
	this->dato = l;
	this->siguiente = s;
}

Nodo* Nodo::getSiguiente() {
	return this->siguiente;
}

void Nodo::setDato(ListaL* l) {
	this->dato = l;
}

Nodo* Nodo::getAbajo() {
	return this->abajo;
}

void Nodo::setAbajo(Nodo* abajo) {
	this->abajo = abajo;
}

void Nodo::setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}

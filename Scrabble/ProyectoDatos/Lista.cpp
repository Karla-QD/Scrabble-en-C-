#include"Lista.h"
//by veronica
Lista::Lista() {
	this->primero = nullptr;
}

Lista:: ~Lista() {
	Nodo* aux = this->primero;
	while (aux != nullptr) {
		this->primero = primero->getSiguiente();
		delete aux;
		aux = primero;
	}
}

Nodo* Lista::getPrimero() {
	return this->primero;
}

bool Lista::ingresar(ListaL* l) {
	Nodo* p = this->primero;
	Nodo* nuevo = new Nodo(l, nullptr, nullptr);
	if (this->primero == nullptr) {
		this->primero = nuevo;
		return true;
	}
	else {
		while (p->getSiguiente() != nullptr) {
			p = p->getSiguiente();
		}
		p->setSiguiente(nuevo);
		return true;
	}
}


std::string Lista::toString() {
	std::stringstream s;
	Nodo* aux = this->primero;
	int i = 0;
	while (aux != nullptr) {
		s << aux->getDato()->toString() << i << std::endl;
		aux = aux->getSiguiente();
		s << std::endl;
		i++;
	}
	return s.str();
}

bool Lista::esVacio() {
	return this->primero == nullptr;
}

int Lista::cuentaNodos() {
	int contador = 0;
	Nodo* aux = primero;
	while (aux != nullptr) {
		contador++;
		aux = aux->getSiguiente();
	}
	return contador;
}

//verifica la existencia de una coordenada en las listas. 
NodoL* Lista::buscarPorCoordenada(int x, int y, char dir)
{
	Nodo* aux = this->primero;
	if (dir == 'h') {
		while (aux != nullptr) {
			if (aux->getDato() != nullptr) { 
				if (aux->getDato()->coordenadaExistente(x, y) != nullptr) {
					return aux->getDato()->coordenadaExistente(x, y);
				}
			}
			aux = aux->getSiguiente();
		}
	}
	else if (dir == 'v'){
		while (aux != nullptr) {
			if (aux->getDato() != nullptr) { 
				if (aux->getDato()->coordenadaExistente(x, y) != nullptr) {
					return aux->getDato()->coordenadaExistente(x, y);
				}
			}
			aux = aux->getAbajo();
		}
	}

	return nullptr;
}


std::string Lista::toStringLista()
{
	std::stringstream s;
	Nodo* aux = this->primero;
	while (aux != nullptr) {
		s << aux->getDato()->toStringLis()<< std::endl << std::endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}

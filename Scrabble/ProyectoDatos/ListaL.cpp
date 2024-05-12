#include "ListaL.h"
//by veronica

ListaL::ListaL() {
	this->primer = nullptr;
	this->y = 0;
	this->x = 0;
	this->coordenadas = std::vector<std::pair<int, int>>();
}

ListaL::~ListaL() {
	NodoL* aux = this->primer;
	while (aux != nullptr) {
		this->primer = this->primer->getSiguiente();
		delete aux;
		aux = this->primer;
	}
}

bool ListaL::insertar(char l) {
	NodoL* nuevo = new NodoL(l, nullptr, nullptr);
	if (this->primer == nullptr) {
		this->primer = nuevo;
		return true;
	}
	else {
		NodoL* aux = this->primer;
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
		return true;
	}
}

NodoL* ListaL::buscar(char l) {
	NodoL* aux = this->primer;
	while (aux != nullptr) {
		if (aux->getLetra() == l) {
			return aux;
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
}



NodoL* ListaL::getPrimer() {
	return this->primer;
}

bool ListaL::esVacia() {
	return this->primer == nullptr;
}



int ListaL::getY() {
	return this->y;
}

int ListaL::getX() {
	return this->x;
}

void ListaL::setCoordenadas(char l)
{
	if (!coordenadas.empty()) coordenadas.clear();
	NodoL* p = primer;
	int auxX = x;
	int auxY = y;
	while (p != nullptr) {
		if (l == 'v') {
			coordenadas.push_back(std::make_pair(x, y++));
		}
		else if (l == 'h')
			coordenadas.push_back(std::make_pair(x++, y)); {
		}
		p = p->getSiguiente();
	}
}

void ListaL::setCoordenadasPlantilla(char l, int tam)
{
	if (!coordenadas.empty()) coordenadas.clear();
	int auxX = x;
	int auxY = y;

	if (l == 'v') {
		for (int i = 0; i < tam; i++) {
			coordenadas.push_back(std::make_pair(auxX, auxY++));
		}
	}
	else if (l == 'h') {
		for (int i = 0; i < tam; i++) {
			coordenadas.push_back(std::make_pair(auxX++, auxY));
		}
	}
}



std::vector<std::pair<int, int>> ListaL::getCoordenadas()
{
	return coordenadas;
}

bool ListaL::ingresarPorNodo(NodoL* h) {
	NodoL* nuevo = h;
	if (this->primer == nullptr) {
		this->primer = nuevo;
		return true;
	}
	else {
		NodoL* aux = this->primer;
		while (aux->getSiguiente() != nullptr) {
			aux = aux->getSiguiente();
		}
		aux->setSiguiente(nuevo);
		return true;
	}
}

bool ListaL::ingresarPorNodoVertical(NodoL* l)
{
	NodoL* nuevo = l;
	if (this->primer == nullptr) {
		this->primer = nuevo;
		return true;
	}
	else {
		NodoL* aux = this->primer;
		while (aux->getAbajo() != nullptr) {
			aux = aux->getAbajo();
		}
		aux->setAbajo(nuevo);
		return true;
	}
}

bool ListaL::ingresarPorLetraVertical(char l)
{
	NodoL* nuevo = new NodoL(l, nullptr, nullptr);
	if (this->primer == nullptr) {
		this->primer = nuevo;
		return true;
	}
	else {
		NodoL* aux = this->primer;
		while (aux->getAbajo() != nullptr) {
			aux = aux->getAbajo();
		}
		aux->setAbajo(nuevo);
		return true;
	}
}

std::string ListaL::toString() {
	NodoL* aux = this->primer;
	std::stringstream s;
	while (aux != nullptr) {
		s << "Direcion de memoria " << aux << " " << aux->getLetra() << std::endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}

bool  ListaL::verificarPalabra(std::string palabra, char letra) {
	NodoL* p = this->primer;
	if (letra == 'v') {
		if (p->getAbajo() == nullptr) {
			return false;
		}
	}
	if (letra == 'h') {
		if (p->getSiguiente() == nullptr) {
			return false;
		}
	}
	else {
		for (int i = 0; i < palabra.length() - 1; i++) {
			if (letra == 'v') {
				if (p->getLetra() != palabra[i]) {
					return false;
				}
				p = p->getAbajo();
			}
			else if (letra == 'h') {
				if (p->getLetra() != palabra[i]) {
					return false;
				}
				p = p->getSiguiente();
			}
		}
		return true;
	}
}

bool ListaL::buscarPorLetra(char letra) {
	NodoL* aux = this->primer;
	while (aux != nullptr) {
		if (aux->getLetra() == letra) {
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

void ListaL::setX(int x) {
	this->x = x;
}

void ListaL::setY(int y) {
	this->y = y;
}

NodoL* ListaL::coordenadaExistente(int x, int y)
{
	NodoL* aux = this->primer;
	for (int i = 0; i < coordenadas.size(); i++) {
		int j = 0;
		if (coordenadas.at(i).first == x && coordenadas.at(i).second == y) {
			while (j < i) {
				aux = aux->getSiguiente();

				j++;
			}
			return aux;
		}
	}
	return nullptr;
}

std::string ListaL::toStringLis()
{
	std::stringstream s;
	NodoL* aux = this->primer;
	while (aux != nullptr && primer->getAbajo() != nullptr) {
		s << aux->getLetra() << " Direccion " << aux << std::endl;
		aux = aux->getAbajo();
	}
	aux = this->primer;
	while (aux != nullptr && primer->getSiguiente() != nullptr) {
		s << aux->getLetra() << " Direccion " << aux << " ";
		aux = aux->getSiguiente();
	}
	return s.str();
}

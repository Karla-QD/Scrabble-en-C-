#include "Scrabble.h"
#include <iostream>
//by veronica

Scrabble::Scrabble() {

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            this->scrabble[i][j] = new NodoL(' ', this->scrabble[i][j]);
        }
    }
    this->lis = new Lista();
}

Scrabble::~Scrabble() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (this->scrabble[i][j] != nullptr) delete this->scrabble[i][j];
        }
    }
    delete[]this->scrabble;
}

std::string Scrabble::imprimir() {
    std::stringstream s;
    s << "  ";
    for (int cantCol = 0; cantCol < 11; cantCol++) {
        s << " " << BOLDCYAN << cantCol << " ";
    }
    s << std::endl;
    for (int fila = 0; fila < 11; fila++) {
        for (int colum = 0; colum < 11; colum++) {
            if (colum == 0) {
                if (fila < 10)
                    s << BOLDCYAN << fila << " ";
                if (fila == 10) {
                    s << BOLDCYAN << fila;
                }
                s << BOLDYELLOW << "|" << BOLDCYAN << this->scrabble[fila][colum]->getLetra() << BLUE << "|";
            }
            else {
                s << BOLDYELLOW << "|" << BOLDCYAN << this->scrabble[fila][colum]->getLetra() << BLUE << "|";
            }
        }
        s << WHITE << std::endl;
    }
    return s.str();
}
bool Scrabble::insertar(int x, int y, char letra, char direc) {
    if (this->scrabble[x][y]->getLetra() == ' ') {
        this->scrabble[x][y]->setLetra(letra);
        return true;
    }
    return false;
}

NodoL* Scrabble::buscar(int x, int y) {
    return this->scrabble[x][y];
}



bool Scrabble::palabraUnida(int x, int y, std::string palabra, char direccion)
{
    int contador = 0;
    if (direccion == 'h') {
        for (int i = 0; i < palabra.length(); i++) {
            if (this->scrabble[y][x]->getLetra() != ' ') {
                contador++;
            }
            x += 1;
        }
        if (contador == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    if (direccion == 'v') {
        for (int i = 0; i < palabra.length(); i++) {
            if (this->scrabble[y][x]->getLetra() != ' ')
                contador++;
            y += 1;
        }
        if (contador == 0) {
            return false;
        }
        else {
            return true;
        }
    }
}

bool Scrabble::insertarPalabraLis(int x, int y, std::string palabra, char direccion) {
    
    NodoL* Nodoinicio = this->scrabble[y][x];
    int X = x;
    int Y = y;

    if (agregarNodoAListaExistente(X, Y, palabra, direccion)) {
        return true;
    }
    if (insertarPalabraSegunExistencia(X,Y,palabra,direccion)) {
        if (direccion == 'h') {
            if (Nodoinicio->getSiguiente() == nullptr) {
                NodoL* temporal = nullptr;
                for (int i = 0; i < palabra.length(); i++) {
                    temporal = scrabble[Y][X+=1];
                    Nodoinicio->setLetra(palabra[i]);
                    Nodoinicio->setSiguiente(temporal);
                    Nodoinicio = Nodoinicio->getSiguiente();
                  
                }
            }
        }
        if (direccion == 'v') {
            if (Nodoinicio->getAbajo() == nullptr) {
                NodoL* temporal;
                for (int i = 0; i < palabra.length(); i++) {
                    temporal = scrabble[Y+=1][X];
                    Nodoinicio->setLetra(palabra[i]);
                    Nodoinicio->setAbajo(temporal);
                    Nodoinicio = Nodoinicio->getAbajo();
                  
                }
            }
        }

        return true;
    }
    return false;
}

Lista* Scrabble::getLista() {
    return this->lis;
}
char Scrabble::ultimoCaracter(std::string palabra) {
    int c = 0;
    for (int i = 1; i < palabra.length(); i++) {
        c++;
    }
    return palabra[c];
}

bool Scrabble::insertarPalabraSegunExistencia(int x, int y, std::string palabra, char direccion)
{
    ListaL* list = new ListaL();
    list->setX(x);
    list->setY(y);
    list->setCoordenadasPlantilla(direccion, palabra.size());
    for (int i = 0; i < palabra.length(); i++) {
        if (lis->buscarPorCoordenada(list->getCoordenadas().at(i).first, list->getCoordenadas().at(i).second, direccion) == nullptr) {
            if (direccion == 'v') {
                list->ingresarPorLetraVertical(palabra[i]);
            }
            else if (direccion == 'h') {
                list->insertar(palabra[i]);
            }
        }
        else {
            NodoL* aux = nullptr;
            if (direccion == 'v') {
                aux = lis->buscarPorCoordenada(list->getCoordenadas().at(i).first, list->getCoordenadas().at(i).second, direccion);
                if (aux->getLetra() == palabra[i]) {
                    list->ingresarPorNodoVertical(aux);
                }
                else return false;
            }
            else {
				aux = lis->buscarPorCoordenada(list->getCoordenadas().at(i).first, list->getCoordenadas().at(i).second, direccion);
                if (aux->getLetra() == palabra[i]) {
                    list->ingresarPorNodo(aux);
                }
            }
        }
    }
    list->setCoordenadas(direccion);
    lis->ingresar(list);
    return true;
}

bool Scrabble::agregarNodoAListaExistente(int x, int y, std::string palabra, char direccion) {
    Nodo* aux2 = this->lis->getPrimero();
    NodoL* aux = nullptr;

    if (direccion == 'h') {
        while (aux2 != nullptr) {
            if (aux2->getDato()->verificarPalabra(palabra,direccion)) {
                aux = new NodoL(ultimoCaracter(palabra), nullptr);
                aux2->getDato()->ingresarPorNodo(aux);
                NodoL* Nodoinicio = this->scrabble[y][x];
                NodoL* temporal = nullptr;
                for (int i = 0; i < palabra.length(); i++) {
                    temporal = this->scrabble[y][x += 1];
                    Nodoinicio->setLetra(palabra[i]);
                    Nodoinicio->setSiguiente(temporal);
                    Nodoinicio = Nodoinicio->getSiguiente();
                }
                return true;
            }
            aux2 = aux2->getSiguiente();
        }
        return false;
    }
    if (direccion == 'v') {
        while (aux2 != nullptr) {
            if (aux2->getDato()->verificarPalabra(palabra,direccion)) {
                aux = new NodoL(ultimoCaracter(palabra), nullptr);
                aux2->getDato()->ingresarPorNodoVertical(aux);
                NodoL* Nodoinicio = this->scrabble[y][x];
                NodoL* temporal = nullptr;
                for (int i = 0; i < palabra.length(); i++) {
                    temporal = this->scrabble[y += 1][x];
                    Nodoinicio->setLetra(palabra[i]);
                    Nodoinicio->setAbajo(temporal);
                    Nodoinicio = Nodoinicio->getAbajo();
                }
                return true;
            }
            aux2 = aux2->getAbajo();
        }
        return false;
    }
}

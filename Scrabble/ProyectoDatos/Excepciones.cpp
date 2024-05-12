#include "Excepciones.h"
#include"Colores.h"
void ExcepcionCordenada::coordenadaDiferente() {
    std::cout << RED "ERROR, la coodernada debe ser un numero" << std::endl;
    Sleep(1000);
    system("cls");
}

void ExcepcionCordenada::maxExcedido() {
    std::cout << RED "ERROR, maximo de casillas excedido" << std::endl;
    Sleep(1000);
    system("cls");
}

void ExcepcionDireccion::tipoDiferente() {
    std::cout << RED "ERROR, el caracter digitado no es valido" << std::endl;
    Sleep(1000);
    system("cls");
}

void ExcepcionPalabras::maxExcedidoPalabras() {
    std::cout << RED "ERROR, no posee suficiente campo para digitar la palabra" << std::endl;
    Sleep(1000);
    system("cls");
}

void ExcepcionPalabras::palabrasRepetidas() {
    std::cout << RED "ERROR, ya existe una palabra en esa coordenada" << std::endl;
    Sleep(1000);
    system("cls");
}

void ExcepcionPalabras::palabrasErroneas() {
    std::cout << RED "ERROR, la palabra digitada no calza con las del tablero" << std::endl;
    Sleep(1000);
    system("cls");
}

void ExcepcionLetras::mensajeError() {
    std::cout << RED "ERROR, el caracter digitado no es valido" << std::endl;
    Sleep(1000);
    system("cls");
}

bool ExcepcionLetras::esNumero(const char* cadena)
{
    for (; *cadena; ++cadena) {
        if ('0' > *cadena || '9' < *cadena)
            return false;
    }
    return true;
}

void ExcepcionCantidad::sobrepasaCantidad()
{
	std::cout << RED "ERROR, la cantidad de jugadores digitados es mayor a la cantidad de jugadores permitidos" << std::endl;
	Sleep(1000);
	system("cls");
}

void ExcepcionDesvinculacion::desvinculacion()
{
	std::cout << RED "ERROR, no se puede ingresar una palabra que no este vinculada, a una ya existente" << std::endl;
	Sleep(1000);
	system("cls");
}

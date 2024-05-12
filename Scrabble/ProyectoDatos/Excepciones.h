#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
//by vero, alisson, jennifer
class ExcepcionLetras {
public:
	void mensajeError();
	bool esNumero(const char* cadena);
};

class ExcepcionCordenada {
	public:
		void coordenadaDiferente();
		void maxExcedido();
		

};

class ExcepcionDireccion {
	public:
		void tipoDiferente();
};

class ExcepcionPalabras {
public:
	void maxExcedidoPalabras();
	void palabrasRepetidas();
	void palabrasErroneas();
};

class ExcepcionCantidad {
public:
	void sobrepasaCantidad();
};
class ExcepcionDesvinculacion {
public:
	void desvinculacion();
};
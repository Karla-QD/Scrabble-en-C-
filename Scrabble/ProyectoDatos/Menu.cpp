#include "Menu.h"
//by alisson

Menu::Menu()
{
	system("title Scrabble");
	Juego arch;
	std::string res = "";
	std::string condicion = "no";
	int cantidad = 0;
	std::string nombre = "";
	char c = ' ';
	Scrabble* scrab = new Scrabble();
	int x = 0;
	int y = 0;
	std::string pa = "";
	char direccion = ' ';
	int opc = 0;
	bool fin = false;
	int turno = 0;
	int saltos = 0;
	int resta = 0;
	int resta2 = 0;
	int con = 0;
	std::string prueba = " ";

	do {
		if (condicion == "no") {
			std::cout <<BLUE "                                     SCRABBLE                         " << std::endl;
			std::cout << "Ingrese la cantidad de jugadores (2-5): ";
		}
		try {
			if (std::cin >> cantidad ) {
				condicion = "si";
			}
			else {
				system("cls");
				std::cin.clear();
				std::cin.ignore(2000, '\n');
				throw new ExcepcionLetras();

			}
			try {
				condicion = "no";
				if (cantidad > 1 && cantidad < 6) {
					condicion = "si";
				}
				else {
					system("cls");
					std::cin.clear();
					std::cin.ignore(2000, '\n');

					throw new ExcepcionCantidad();
				}
			}
			catch (ExcepcionCantidad* ccc) {
				ccc->sobrepasaCantidad();
			}
			
		}
		catch (ExcepcionLetras* ccc) {
			ccc->mensajeError();

		}
		
		
	} while (condicion == "no");
	
	for (int i = 0; i < cantidad; i++) {
		system("cls");
		std::cout <<BLUE "Ingrese el nombre del jugador " << i + 1 << " :  ";
		std::cin >> nombre;
		Jugador* jugador = new Jugador(nombre);
		arch.insertarJugador(jugador);
	}
	system("cls");
	std::cout << CYAN" EMPIEZA JUGADOR" << std::endl;
	Jugador* jug = arch.jugadorRandom();
	turno = arch.devolverPosicion(jug->getNombre());
	do {
		do {
			condicion = "no";
				std::cout <<BLUE "		SCRABBLE	" << std::endl;
				std::cout << scrab->imprimir() << std::endl;
				std::cout << jug->toString() << std::endl;
				std::cout <<BLUE "Ingrese la opcion 1 para colocar palabra: " << std::endl;
				std::cout <<BLUE "Ingrese la opcion 2 para pasar turno: " << std::endl;
				std::cout <<BLUE "Ingrese la opcion: " << std::endl;
			try {
				if ((std::cin >> opc) && opc == 1 || opc == 2) {
					condicion = "si";
				}
				else {
					system("cls");
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					throw new ExcepcionLetras();
				}
			}
			catch (ExcepcionLetras* ccc) {
				ccc->mensajeError();
			}
		} while (condicion == "no");
		switch (opc)
		{
		case 1:
			do {
				res = "no";
				system("cls");
				std::cout << BLUE"		SCRABBLE	" << std::endl;
				std::cout << scrab->imprimir() << std::endl;
				std::cout << jug->toString() << std::endl;
				std::cout <<BLUE "Ingrese La palabra que desea ingresar: " << std::endl;
			std::cin >> pa;
				prueba = pa;
				if (arch.verificar(pa) == true) {
					std::cout << GREEN"La palabra es valida" << std::endl;
					if (scrab->getLista()->esVacio()) {
					  do {
						try {
							condicion = "no";
							std::cout << BLUE "Ingrese la direccion(h = horizontal, v = vertical)" << std::endl;
							std::cin >> direccion;
							if ((direccion != 'h') && (direccion != 'v')) {
								throw new ExcepcionDireccion();
							}
							else {
								if (direccion == 'h') {
									if (scrab->insertarPalabraLis(3, 5, pa, direccion) == true) {
										system("cls");
										condicion = "si";
										std::cout <<GREEN "Se inserto correctamente" << std::endl;
										std::cout << scrab->imprimir() << std::endl;
										arch.eliminarLetras(pa, jug);
										Sleep(1000);
									}
									else {
										std::cout << RED "No se inserto correctamente" << std::endl;
									}
								}
								if (direccion == 'v') {
									if (scrab->insertarPalabraLis(5, 3, pa, direccion) == true) {
										condicion = "si";
										system("cls");
										std::cout <<GREEN "Se inserto correctamente" << std::endl;
										std::cout << scrab->imprimir() << std::endl;
										arch.eliminarLetras(pa, jug);
										Sleep(1000);
									}
									else {
										std::cout <<RED "No se inserto correctamente" << std::endl;
									}
								}
							}
						}
						catch (ExcepcionDireccion* ed) {
							ed->tipoDiferente();
						}
					  } while (condicion == "no");
					}
					else {
						do {
							condicion = "no";
						try {
							std::cout << "Ingrese la coordenada x" << std::endl;
							std::cin.clear();
							std::cin.ignore(1000, '\n');
							std::cin >> x;
							resta = x + pa.length();
							if (isdigit(x)) {
								throw new ExcepcionCordenada();
							}
							if (x > 10) {
								throw new ExcepcionCordenada();
							}
							else {
								condicion = "si";
							}
						}
						catch (ExcepcionCordenada* cd) {
							cd->coordenadaDiferente();
						}
						} while (condicion == "no");
						do{
							condicion = "no";
						try {
							std::cout << "Ingrese la coordenada y" << std::endl;
							std::cin.clear();
							std::cin.ignore(1000, '\n');
							std::cin >> y;
							resta2 = y + pa.length();
							if (isdigit(y)) {
								throw new ExcepcionCordenada();
							}
							if (y > 10) {
								throw new ExcepcionCordenada();
							}
							else {
								condicion = "si";
							}
						}
						catch (ExcepcionCordenada* cdd) {
							cdd->coordenadaDiferente();
						}
					} while (condicion == "no");
					do{
						condicion = "no";
						try {
							std::cout << "Ingrese la direccion(h = horizontal, v = vertical)" << std::endl;
							std::cin >> direccion;

							if ((direccion != 'h') && (direccion != 'v')) {
								condicion = "si";
								throw new ExcepcionDireccion();
							}
							else {
								try {
									if ((direccion == 'v') && (12 <= resta2)) {
										condicion = "si";
										throw new ExcepcionPalabras();
								    }
									if ((direccion == 'h') && (12 <= resta)) {
										condicion = "si";
										throw new ExcepcionPalabras();
									}
									else {
										try {
											if (scrab->palabraUnida(x, y, prueba, direccion)) {
												if (scrab->insertarPalabraLis(x, y, pa, direccion) == true) {
													system("cls");
													std::cout << GREEN "Se inserto correctamente" << std::endl;
													std::cout << scrab->imprimir() << std::endl;
													arch.eliminarLetras(pa, jug);
													Sleep(1000);
													condicion = "si";
												}
											}
											else {
												std::cout << RED "No se inserto correctamente" << std::endl;
												condicion = "si";
												throw new ExcepcionDesvinculacion();
											}	
										}
										catch (ExcepcionDesvinculacion* ep) {
											ep->desvinculacion();
										}
									}
								}
								catch (ExcepcionPalabras* ep) {
									ep->maxExcedidoPalabras();
								}
							}
						}
						catch (ExcepcionDireccion* ce) {
							ce->tipoDiferente();
						}
					} while (condicion == "no");
					}
				}
				else { 
				   
					std::cout <<RED "La palabra no es valida" << std::endl;
					Sleep(1200);
					res = "si";
					con+=1;
					if (con == 1) {
						res = "no";
					}
				}
			} while (res == "si");
			system("cls");
			break;
		case 2:
			if (arch.pasarTurno())
				saltos++;
			system("cls");
			break;
		default:
			break;
		}
		resta = 0;
		resta2 = 0;
		turno += 1;
		cantidad = arch.devolverCantidad();
		con = 0;
		if (saltos == cantidad) {
			fin = true;
		}
		if (turno == cantidad) {
			turno = 0;
			saltos = 0;
		}
		jug = arch.obtenerJugador(turno);
	} while (fin == false);

	system("cls");
	std::cout << BLUE "      FIN DEL JUEGO         " << std::endl;
	std::cout <<BLUE "  El ganador del juego es :        " << std::endl;
	std::cout << CYAN <<arch.ganador()->toString() << std::endl;
	//std::cout << BLUE "MOSTRAR LISTA DE LISTAS DE PALABRAS" << std::endl;
	//std::cout <<scrab->getLista()->toStringLista() << std::endl;
}

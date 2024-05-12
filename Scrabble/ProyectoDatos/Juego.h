#include "Jugador.h"
#include "Scrabble.h"
#include<string>
#include<fstream>



class Juego {
private:
     std::vector<Jugador*> jugadores; 
     Scrabble* scrabble;
public:
    Juego();
    virtual ~Juego();
    void insertarJugador(Jugador*); //metodo para insertar jugadores a un vector. 
    Jugador* ganador();
    Jugador* jugadorRandom(); //metodo para obtener a el primer jugador de manera aleatoria. 
	Jugador* obtenerJugador(int pos);  //metodo para obtener a un jugador en especifico.
	std::vector<Jugador*> getJugadores(); //metodo para obtener a todos los jugadores.
	int devolverPosicion(std::string); //metodo que genera un numero aleatorio para obtener a un jugador de manera aleatoria.
	int devolverCantidad(); //metodo para obtener la cantidad de jugadores.
	void eliminarLetras(std::string, Jugador* jugador); //metodo para eliminar letras de un jugador.
    bool pasarTurno(); //metodo para el salto de tuurno de el jugador en caso de no tener letras funcionales para formar otra palabra. 
    bool verificar(std::string);   // metodo para verificar que la palbra exista en el archivo. 
	
};
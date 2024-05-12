#include "BancoLetras.h"
#include<time.h>
#include<Windows.h>

BancoLetras::BancoLetras() {
	std::vector<char> aux = { 's','l','a','o','p','i' };
	vec.push_back(aux);
	aux = { 'r','l','o','s','a','i' };
	vec.push_back(aux);
	aux = { 's','l','e','r','i','a' };
	vec.push_back(aux);
	aux = { 'l','r','o','i','s','e' };
	vec.push_back(aux);
	aux = { 's','s','p','a','o','i' };
	vec.push_back(aux);
	aux = { 'l','o','r','o','s','u' };
	vec.push_back(aux);
	aux = { 'a','l','a','r','o','i' };
	vec.push_back(aux);
	aux = { 'u','a','e','p','o','r' };
	vec.push_back(aux);
	aux = { 'l','a','e','o','p','t' };
	vec.push_back(aux);
	aux = { 't','a','r','t','o','u' };
	vec.push_back(aux);
	aux = { 'u','t','a','r','o','s' };
	vec.push_back(aux);
	aux = { 'e','a','l','r','o','p' };
	vec.push_back(aux);
}

BancoLetras* BancoLetras::instancia = 0;

BancoLetras::~BancoLetras() {
	this->vec.clear();
}

int BancoLetras::retornarPosicion() {
	srand((unsigned)time(nullptr));
	Sleep(300);
	int numeroAleatorio = rand() % this->vec.size(); 
	return numeroAleatorio;
}


BancoLetras* BancoLetras::getInstancia() {
	if (instancia == nullptr) instancia = new BancoLetras();
	return instancia; 
}

std::vector<std::vector<char>> BancoLetras::getVec()
{
	return this->vec;
}

std::vector<char> BancoLetras::enviarLetras()
{
	std::vector<char> aux;
	int posicion = retornarPosicion();
	aux = this->vec[posicion];
	return aux;

}

#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

class BancoLetras {
private:

	static BancoLetras* instancia; 
	std::vector < std::vector<char>> vec;
	BancoLetras();
public:
	static BancoLetras* getInstancia();
	std::vector < std::vector<char>> getVec(); //vector de vectores que contienen letras. 
	std::vector<char > enviarLetras();
	virtual ~BancoLetras();
	int retornarPosicion();

};


#pragma once
#include"lib.h"
class Pista;
class Garagem;

class Autodromo
{

	string nome;
	int N;
	int cp;
	//vector<Carro*> c;
	//vector<Piloto*> p;

public:
	Autodromo(int num,int com,string& n);
	string getNome();
	int retComp();
	string getASstring();
	~Autodromo();
};


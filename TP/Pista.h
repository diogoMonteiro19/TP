#pragma once
#include "Lib.h"

class Pista
{
	string nome;
	int comprimento;
	//vector<Carro*> nc;

public:
	Pista(string n, int comp);
	string getAsString()const;
	~Pista();
};


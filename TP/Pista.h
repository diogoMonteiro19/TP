#pragma once
#include "lib.h"

class Pista
{
	int comprimento;
	//vector<Carro*> nc;

public:
	Pista();
	void setComprimento(int com);
	string getAsString()const;
	~Pista();
};


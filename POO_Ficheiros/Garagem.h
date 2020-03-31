#pragma once
#include "Lib.h"

class Garagem
{
	string nome;
	int ncarros;

public:
	Garagem(string n, int nc);
	string getAsString()const;
	~Garagem();
};


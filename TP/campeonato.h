#pragma once
#include"lib.h"

class Autodromo;
class Pares;
class Carro;
class Piloto;
class campeonato
{
	vector<string> va;
	vector<Pares> vp;
public:
	campeonato(istringstream& la,vector<Piloto*> pil,vector<Carro*> car);
};


#pragma once
#include"lib.h"

class Piloto
{
	string tipo;
	string nome;
	bool dentro;
public:
	Piloto(string t,string n);
	string getAsString();
	string getN();
	~Piloto();
};


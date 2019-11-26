#pragma once
#include"lib.h"

class Piloto
{
	string tipo;
	string nome;
public:
	Piloto(string t,string n);
	string getAsString();
	~Piloto();
};


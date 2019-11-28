#pragma once
#include"lib.h"

class Carro
{
	string marca, modelo;
	string id;
	int energia;
	int capmax;
	int capini;
	static int nid;
public:
	Carro(string ma,string mo,int cm,int ci);
	Carro(string ma);
	string getAsString();
	string getNome();
};


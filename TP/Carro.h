#pragma once
#include"lib.h"

class Piloto;
class Carro
{
	string marca, modelo;
	string id;
	int energia;
	int capmax;
	int capini;
	static int nid;
	bool ocupado;
	Piloto* p;
public:
	Carro(string ma,string mo,int cm,int ci);
	Carro(string ma);
	string getAsString();
	string getNome();
	bool getOcupado();
	void TOcupado();
	void setJunta(Piloto* pi);
	void FOcupado();
	void RemovePil();
	string getNP();
};


#pragma once
#include"lib.h"
#include"Piloto.h"
#include"Carro.h"

class Pares
{
	string npiloto;
	string ncarro;
	int pos;
	Piloto* p;
	Carro* c;
public:
	Pares(Piloto *pi, Carro *ca);
	string getPiloto();
	string getCarro();
	int getPos();
	string getAsString()const;
	string getCAsString();
	void trocaMove(bool t);
	void carregaPar();
	void setPos(int x);
	void acidente();
	bool getM();
	string getTipo();
	bool getP();
	void setP(bool t);
	int getXP();
	void setXP(int nx);
	int getRand();
	void setR();
};


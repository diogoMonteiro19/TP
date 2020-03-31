#pragma once
#include"lib.h"

class Piloto;
class Carro
{
	string marca, modelo;
	string id;
	float energia;
	float capmax;
	float capini;
	static int nid;
	bool ocupado;
	bool move;
	bool morto;
	Piloto* p;
public:
	Carro(string ma,string mo,float cm,float ci);
	Carro(string ma);
	string getAsString();
	string getNome();
	bool getOcupado();
	void TOcupado();
	void setJunta(Piloto* pi);
	void FOcupado();
	void RemovePil();
	string getNP();
	void trocaMove(bool t);
	void carregab();
	bool getMorto();
	void setMorto(bool t);
};


#pragma once
#include"lib.h"

class Piloto;
class Carro;
class Autodromo;
class mundo
{
	vector<Carro*> lc;
	vector<Piloto*> lp;
	vector<Autodromo*> la;

public:
	mundo();
	void CarregaC(string nf);
	void CarregaP(string nf);
	void CarregaA(string nf);
	void addPiloto(Piloto* p);
	void addCarro(Carro* c);
	void addAutodromo(Autodromo* a);
};


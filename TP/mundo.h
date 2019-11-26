#pragma once
#include"lib.h"

class Piloto;
class Carro;
class mundo
{
	vector<Carro*> lc;
	vector<Piloto*> lp;

public:
	mundo();
	void CarregaC(string nf);
	void CarregaP(string nf);
};


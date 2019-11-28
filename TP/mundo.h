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
	campeonato *novo;
	int static conta;

public:
	mundo();
	void CarregaC(string nf);
	void CarregaP(string nf);
	bool verificaP(string& np);
	void CarregaA(string nf);
	void addPiloto(string& t, string& n);
	void addCarro(string& ma,string& mo, int cm,int ci);
	void addAutodromo(int nc,int com,string& na);
	void criaCamp(istringstream& dados);
	void 
};


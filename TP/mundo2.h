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
<<<<<<< HEAD
	void addPiloto(Piloto* p);
	void addCarro(Carro* c);
	void addAutodromo(Autodromo* a);
	void removePiloto(string n);
	void removeCarro(string id);
	void removeAutodromo(string n);
=======
	void addPiloto(string& t, string& n);
	void addCarro(string& ma,string& mo, int cm,int ci);
	void addAutodromo(int nc,int com,string& na);
	void criaCamp(istringstream& dados);
	void 
>>>>>>> db78fb471d89c05406232cb301b988dd6c0708a7
};


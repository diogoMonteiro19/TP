#pragma once
#include"lib.h"

class Autodromo;
class Pares;
class Carro;
class Piloto;
class campeonato
{
	vector<string> va;
	vector<Pares*> vp;
	vector<Autodromo*> autodromos;
	int autodromoatual;
	int ncorrida;
public:
	campeonato(istringstream& la,vector<Piloto*> pil,vector<Carro*> car,vector<Pares*> mvp);
	string retornaAuto();
	string mostraPares();
	string getAsString();
	void MostraCorrida(int comp);
	int ncarros();
	string listaCarros();
	void andar(bool t);
	void carregab();
	void acidente(string nc);
	void recebeAutos(vector<Autodromo*> lautos);
	void separa(string c);
	void adicionaVP(Piloto* p,Carro *c);
	void addPar(Pares* p);
};


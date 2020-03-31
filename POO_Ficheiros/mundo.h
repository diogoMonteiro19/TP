#pragma once
#include"lib.h"
#include"Pares.h"

class Piloto;
class Carro;
class Autodromo;
class campeonato;
class mundo
{
	vector<Carro*> lc;
	vector<Piloto*> lp;
	vector<Autodromo*> la;
	vector<Pares*> vp;
	campeonato* novo;
	bool camp;
	int static conta;

public:
	mundo();
	void CarregaC(string nf);
	void CarregaP(string nf);
	bool verificaP(string np);
	void CarregaA(string nf);
	void addPiloto(string& t, string& n);
	void addCarro(string& ma,string& mo, int cm,int ci);
	void addAutodromo(int nc,int com,string& na);
	void criaCamp(istringstream& dados);
	void removePiloto(string n);
	void removeCarro(string id);
	void removeAutodromo(string n);
	string entraNoCarro(string np, string id);
	void saiDoCarro(string id);
	void imprime();
	int	compPistaAtual();
	void passatempo();
	void verCarros();
	void verPilotos();
	void verAutodromo();
	void verPares();
	void mostraC();
	void listarCarrosEmCorrida();
	string carregabat();
	string acidente(string nc);
	void enviaListaAuto();
};


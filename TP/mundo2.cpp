#include "mundo.h"
#include"Carro.h"
#include"Piloto.h"
#include"Autodromo.h"
#include"campeonato.h"
#include"lib.h"

int mundo::conta = 1;

mundo::mundo()
{
}

void mundo::CarregaC(string nf)
{
	ifstream ficheiro(nf);
	if (ficheiro) {
		string linha;
		while (getline(ficheiro, linha)) {
			istringstream buffer(linha);
			string mar, mod;
			int ci, cm;
			if (buffer >> ci  && buffer >> cm && buffer>>mar && buffer >> mod) {
				Carro *p = new Carro(mar,mod,cm,ci);
				lc.push_back(p);
			}
		}
	}
	for (int i = 0; i < lc.size();i++) {
		cout << lc[i]->getAsString();
	}	
	
}

void mundo::CarregaP(string nf)
{
	ifstream ficheiro(nf);
	if (ficheiro) {
		string linha;
		while (getline(ficheiro, linha)) {
			istringstream buffer(linha);
			string no, ti;
			if (buffer >> ti  && buffer >> no) {
				Piloto *p = new Piloto(ti,no);
				lp.push_back(p);
			}
		}
	}
	for (int i = 0; i < lp.size();i++) {
		cout << lp[i]->getAsString();
	}

}

bool mundo::verificaP(string& np)
{
	for (auto ptr = lp.begin(); ptr != lp.end();) {
		if ((*ptr)->getN == np) {
			return true;
		}
		else
			ptr++;
	}
	return false;
}

void mundo::CarregaA(string nf)
{
	ifstream ficheiro(nf);
	if (ficheiro) {
		string linha;
		while (getline(ficheiro, linha)) {
			istringstream buffer(linha);
			string no;
			int num,com;
			if (buffer >> num && buffer >> com && buffer >> no) {
				Autodromo* p = new Autodromo(num,com,no);
				la.push_back(p);
			}
		}
	}
	for (int i = 0; i < lp.size(); i++) {
		cout << lp[i]->getAsString();
	}
}

void mundo::addPiloto(string& t,string& n)
{
	if (!verificaP(n)) {
		Piloto* novo = new Piloto(t, n);
		lp.push_back(novo);
	}
	else {
		string auxn;
		ostringstream o;
		o << n << conta;
		auxn = o.str();
		conta++;
		Piloto* novo = new Piloto(auxn, n);
		lp.push_back(novo);
	}
}

void mundo::addCarro(string& ma, string& mo, int cm, int ci)
{
	Carro* novo = new Carro(ma, mo, cm, ci);
	lc.push_back(novo);
}

void mundo::addAutodromo(int nc, int com, string& na)
{
	Autodromo* novo = new Autodromo(nc, com, na);
	la.push_back(novo);
}

void mundo::criaCamp(istringstream& dados)
{
	novo = new campeonato(dados,lp,lc);
}

<<<<<<< HEAD
void mundo::removePiloto(string n)
{
	for (auto ptr = lp.begin(); ptr != lp.end();) {
		if ((*ptr)->getN() == n) {
			delete* ptr;
			ptr = lp.erase(ptr);
		}
		else ptr++;
	}
}

void mundo::removeCarro(string id)
{
	for (auto ptr = lc.begin(); ptr != lc.end();) {
		if ((*ptr)->getNome() == id) {
			delete* ptr;
			ptr = lc.erase(ptr);
		}
		else ptr++;
	}
}

void mundo::removeAutodromo(string n)
{
	for (auto ptr = la.begin(); ptr != la.end();) {
		if ((*ptr)->getNome() == n) {
			delete* ptr;
			ptr = la.erase(ptr);
		}
		else ptr++;
	}
}
=======
>>>>>>> db78fb471d89c05406232cb301b988dd6c0708a7

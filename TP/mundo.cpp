#include "mundo.h"
#include"Carro.h"
#include"Piloto.h"
#include"Autodromo.h"
#include"lib.h"

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

void mundo::addPiloto(Piloto* p)
{
	lp.push_back(p);
}

void mundo::addCarro(Carro* c)
{
	lc.push_back(c);
}

void mundo::addAutodromo(Autodromo* a)
{
	la.push_back(a);
}

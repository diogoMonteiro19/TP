#include "mundo.h"
#include"Carro.h"
#include"Piloto.h"
#include"Autodromo.h"
#include"campeonato.h"
#include"Consola.h"
#include"lib.h"

int mundo::conta = 1;

mundo::mundo()
{
	novo = nullptr;
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

bool mundo::verificaP(string np)
{
	for (auto ptr = lp.begin(); ptr != lp.end();) {
		if ((*ptr)->getN() == np) {
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
	for (int i = 0; i < la.size(); i++) {
		cout << la[i]->getASstring();
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

string mundo::entraNoCarro(string np, string id)
{
	string aux;
	ostringstream buffero;
	for (auto ptr = lp.begin(); ptr != lp.end();) {
		if ((*ptr)->getN() == np) {
			if ((*ptr)->getDentro()) {
				aux = "O piloto esta dentro do carro";
				return aux;
			}
			else {
				for (auto ptr2 = lc.begin(); ptr2 != lc.end();) {
					if((*ptr2)->getNome() == id){
						if ((*ptr2)->getOcupado()) {
							aux = "O carro esta ocupado";
							return aux;
						}
						else
						{
							(*ptr)->TDentro();
							(*ptr2)->TOcupado();
							(*ptr2)->setJunta(*ptr);
							buffero << "O Piloto entrou no carro com id: " << (*ptr2)->getNome();
						}
					}
					ptr2++;
				}
			}
		}
		ptr++;
	}
	return buffero.str();
}

void mundo::saiDoCarro(string id)
{
	for (auto ptr = lc.begin(); ptr != lc.end();) {
		if ((*ptr)->getNome() == id) {
			(*ptr)->FOcupado();
			for (auto ptr2 = lp.begin(); ptr2 != lp.end();) {
				if ((*ptr2)->getN() == (*ptr)->getNP()) {
					(*ptr2)->FDentro();
				}
				else
					ptr2++;
			}
			(*ptr)->RemovePil();
		}
		else
			ptr++;
	}
}
void mundo::imprime()
{
	int compPista,compTraco;

	Consola::clrscr();
	Consola::setScreenSize(64, 40);
	compPista = compPistaAtual();
	compTraco = compPista / 60;
	Consola::gotoxy(1,0);
	cout << "|";
	Consola::gotoxy(62, 0);
	cout << "|";
	Consola::gotoxy(1, 1);
	for (int i = 0; i < 62; i++) {
		Consola::gotoxy(i + 1, 1);
		if (i == 0 || i == 61) {
			cout << "|";
		}
		else
			cout << "-";
	}
	Consola::gotoxy(1, 2);
	cout << "|";
	Consola::gotoxy(62, 2);
	cout << "|";
	Consola::gotoxy(1, 3);
	cout << compPista<<"||"<< compTraco;
	Consola::gotoxy(1, 4);
	for (int i = 0; i < lc.size(); i++){
		Consola::gotoxy(1, i + 4);
		cout << lc[i]->getNome();
	}
}

int mundo::compPistaAtual()
{
	for (auto ptr = la.begin(); ptr != la.end();) {
		if ((*ptr)->getNome() == novo->retornaAuto()) {
			return (*ptr)->retComp();
		}
		else
			ptr++;
	}
}


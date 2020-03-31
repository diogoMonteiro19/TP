#include "campeonato.h"
#include"Autodromo.h"
#include"Pares.h"
#include"Piloto.h"
#include"Carro.h"
#include"Consola.h"
#include<ctime>
#include"Interface.h"

campeonato::campeonato(istringstream& la, vector<Piloto*> pil, vector<Carro*> car, vector<Pares*> mvp)
{
	vp = mvp;
	srand(time(NULL));
	bool valido = false;
	bool existe=false;
	if (pil.size() >= car.size()) {
		for (int i = 0; i < car.size(); i++) {
			if (car[i]->getOcupado() == false) {
				valido = false;
				while (!valido) {
					existe = false;
					int npil = rand() % pil.size();
					//verificar se o piloto ja tem par
					for (int i2 = 0; i2 < vp.size(); i2++) {
						if (pil[npil]->getN() == vp[i2]->getPiloto()) {// existe
							existe = true;
							break;
						}
					}
					if (!existe && pil[npil]->getDentro() == false && car[i]->getOcupado() == false) {
						Pares* novo = new Pares(pil[npil], car[i]);
						pil[npil]->TDentro();
						car[i]->TOcupado();
						vp.push_back(novo);
						car[i]->setJunta(pil[npil]);
						valido = true;
					}
				}
			}
			else
				continue;
		}
	}
	else {
		for (int i = 0; i < pil.size(); i++) {
			if (pil[i]->getDentro() == false) {
				existe = false;
				valido = false;
				while (!valido) {
					int ncar = rand() % car.size();
					//verificar se o carro ja tem par
					for (int i2 = 0; i2 < vp.size(); i2++) {
						if (car[ncar]->getNome() == vp[i2]->getCarro()) {// existe
							existe = true;
							break;
						}
					}
					if (!existe && pil[i]->getDentro() == false && car[ncar]->getOcupado() == false) {
						Pares* novo = new Pares(pil[i], car[ncar]);
						pil[i]->TDentro();
						car[ncar]->TOcupado();
						vp.push_back(novo);
						car[ncar]->setJunta(pil[i]);
						valido = true;
					}
				}
			}
			else
				continue;
		}
	}
	string temp;
	bool autovalido=false;
	while (!la.eof()) {
		la >> temp;
		//	do {
		//		for (int i = 0; i < autodromos.size(); i++) {
		//			if (temp == autodromos[i]->getNome()) {
		//				va.push_back(temp);
		//				autovalido = true;
		//			}
		//		}
		//		cout << "Esse autodromo nao faz parte da lista!!";
		//	} while (autovalido != true);
		//}
		va.push_back(temp);
	}
	autodromoatual = 0;
	ncorrida = 1;
}

string campeonato::retornaAuto()
{
	return va[autodromoatual];
}


string campeonato::mostraPares()
{
	ostringstream os;
	for (int i = 0; i < vp.size(); i++) {
		os << vp[i]->getAsString();
	}

	return os.str();
}

string campeonato::getAsString()
{
	ostringstream o;

	return string();
}

void campeonato::MostraCorrida(int comp)
{
	Interface ola(vp);
	ola.mostra(vp.size());
	ola.anda(comp,vp.size());

}


int campeonato::ncarros()
{
	int conta=0;
	for (int i = 0; i < vp.size(); i++) {
		conta++;
	}
	return conta;
}

string campeonato::listaCarros()
{
	ostringstream os;
	for (int i = 0; i < vp.size(); i++) {
		os << vp[i]->getCAsString();
	}
	return os.str();
}

void campeonato::andar(bool t)
{
	for (int i = 0; i < vp.size(); i++) {
		vp[i]->trocaMove(true);
	}
}

void campeonato::carregab()
{
	for (int i = 0; i < vp.size(); i++) {
			vp[i]->carregaPar();
	}
}

void campeonato::acidente(string nc)
{
	for (int i = 0; i < vp.size(); i++) {
		if(vp[i]->getCarro() == nc)
			vp[i]->acidente();
	}
}

void campeonato::recebeAutos(vector<Autodromo*> lautos)
{
	autodromos = lautos;
}

void campeonato::separa(string c)
{
	for (auto ptr = vp.begin(); ptr != vp.end();) {
		if ((*ptr)->getCarro() == c) {
			delete* ptr;
			ptr = vp.erase(ptr);
		}
		else
			ptr++;
	}
}

void campeonato::adicionaVP(Piloto *p,Carro *c)
{
	Pares*outro = new Pares(p, c);
	vp.push_back(outro);
}

void campeonato::addPar(Pares* p)
{
	vp.push_back(p);
}







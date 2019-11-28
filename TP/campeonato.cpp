#include "campeonato.h"
#include"Autodromo.h"
#include"Pares.h"
#include"Piloto.h"
#include"Carro.h"

campeonato::campeonato(istringstream& la, vector<Piloto*> pil, vector<Carro*> car)
{
	bool valido = false;
	bool existe=false;
	if (pil.size() >= car.size()) {
		for (int i = 0; i < car.size(); i++) {
			existe = false;
			valido = false;
			while (!valido) {
				int npil = rand() % pil.size();
				//verificar se o piloto ja tem par
				for (int i2 = 0; i2 < vp.size(); i2++) {
					if (pil[npil]->getN() == vp[i2].getPiloto()) {// existe
						existe = true;
						break;
					}
				}
				if (!existe) {
					Pares novo(pil[npil]->getN(), car[i]->getNome());
					vp.push_back(novo);
					valido = true;
				}
			}
		}
	}
	else {
		for (int i = 0; i < pil.size(); i++) {
			for (int i = 0; i < car.size(); i++) {
				existe = false;
				valido = false;
				while (!valido) {
					int ncar = rand() % car.size();
					//verificar se o carro ja tem par
					for (int i2 = 0; i2 < vp.size(); i2++) {
						if (car[ncar]->getNome() == vp[i2].getCarro()) {// existe
							existe = true;
							break;
						}
					}
					if (!existe) {
						Pares novo(car[ncar]->getNome(), pil[i]->getN());
						vp.push_back(novo);
						valido = true;
					}
				}
			}
		}
	}
	string temp;
	while (!la.eof()) {//ver como fazer !!!!!!!!!!!!!!
		la >> temp;
		va.push_back(temp);
	}
}



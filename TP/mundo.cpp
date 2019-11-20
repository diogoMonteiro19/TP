#include "mundo.h"
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
				Carro p(mar,mod,cm,ci);
				lc.push_back(p);
			}
		}
	}
	for (auto el : lc) {
		cout << el.getAsString();
	}
	
}

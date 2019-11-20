#include "Garagem.h"


Garagem::Garagem(string n, int nc)
{
	nome = n;
	ncarros = nc;
}

string Garagem::getAsString() const
{
	ostringstream buffero;
	buffero << "Nome: " << nome << "Numero de Carros: " << ncarros << endl;

	return buffero.str();
}

Garagem::~Garagem()
{
}

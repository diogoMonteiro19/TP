#include "Pista.h"


Pista::Pista(string n, int comp)
{
	nome = n;
	comprimento = comp;
}

string Pista::getAsString() const
{
	ostringstream buffero;
	buffero << "Nome: " << nome << "Tamanho: " << comprimento << endl;

	return buffero.str();
}

Pista::~Pista()
{
}

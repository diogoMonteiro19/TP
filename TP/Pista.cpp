#include "Pista.h"


Pista::Pista()
{
}

void Pista::setComprimento(int com)
{
	comprimento = com;
}

string Pista::getAsString() const
{
	ostringstream buffero;
	buffero << "Tamanho: " << comprimento << endl;

	return buffero.str();
}

Pista::~Pista()
{
}

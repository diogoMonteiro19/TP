#include "Piloto.h"
#include"lib.h"

Piloto::Piloto(string t,string n) {
	tipo = t;
	nome = n;
	dentro = false;
}

string Piloto::getAsString()
{
	ostringstream buffero;

	buffero << tipo << "||" << nome << endl;
	return buffero.str();
}

string Piloto::getN()
{
	return nome;
}

Piloto::~Piloto()
{
}

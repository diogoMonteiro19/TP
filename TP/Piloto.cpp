#include "Piloto.h"
#include"lib.h"

Piloto::Piloto(string t,string n) {
	tipo = t;
	nome = n;
}

string Piloto::getAsString()
{
	ostringstream buffero;

	buffero << tipo << "||" << nome << endl;
	return buffero.str();
}

Piloto::~Piloto()
{
}

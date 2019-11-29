#include "Pares.h"

Pares::Pares(string npil, string nc)
{
	npiloto = npil;
	ncarro = nc;
	pos = 0;
}

string Pares::getPiloto()
{
	return npiloto;
}

string Pares::getCarro()
{
	return ncarro;
}

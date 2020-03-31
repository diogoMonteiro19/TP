#include "Piloto.h"
#include"lib.h"

Piloto::Piloto(string t,string n) {
	tipo = t;
	nome = n;
	dentro = false;
	partiu = false;
	x = 1;
	random = 0;
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

bool Piloto::getDentro()
{
	return dentro;
}

void Piloto::TDentro()
{
	dentro = true;
}

void Piloto::FDentro()
{
	dentro = false;
}

string Piloto::getTipo()
{
	return tipo;
}

bool Piloto::getP()
{
	return partiu;
}

void Piloto::setP(bool t)
{
	partiu = t;
}

int Piloto::getX()
{
	return x;
}

void Piloto::setX(int nx)
{
	x = nx;
}

int Piloto::getR()
{
	return random;
}

void Piloto::setR(int t)
{
	random = t;
}

Piloto::~Piloto()
{
}

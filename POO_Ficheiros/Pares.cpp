#include "Pares.h"
#include"Piloto.h"
#include"Carro.h"

Pares::Pares(Piloto *pi, Carro *ca)
{
	npiloto = pi->getN();
	ncarro = ca->getNome();
	p = pi;
	c = ca;
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

int Pares::getPos()
{
	return pos;
}
string Pares::getAsString() const
{
	ostringstream os;
	os << npiloto << "||" << ncarro << endl;

	return os.str();
}

string Pares::getCAsString()
{
	return c->getAsString();
}

void Pares::trocaMove(bool t)
{
	c->trocaMove(t);
}

void Pares::carregaPar()
{
	c->carregab();
}

void Pares::setPos(int x)
{
	pos = x;
}

void Pares::acidente()
{
	c->setMorto(true);
}

bool Pares::getM()
{
	return c->getMorto();
}

string Pares::getTipo()
{
	return p->getTipo();
}

bool Pares::getP()
{
	return p->getP();
}

void Pares::setP(bool t)
{
	p->setP(t);
}

int Pares::getXP()
{
	return p->getX();
}

void Pares::setXP(int nx)
{
	p->setX(nx);
}

int Pares::getRand()
{
	return p->getR();
}

void Pares::setR()
{
	p->CReagePartida();
}


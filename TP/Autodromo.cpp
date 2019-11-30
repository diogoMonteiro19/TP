#include "Autodromo.h"
#include"Pista.h"



Autodromo::Autodromo(int num,int com,string& n)
{
	nome = n;
	N = num;
	cp = com;
	
}

string Autodromo::getNome()
{
	return nome;
}

int Autodromo::retComp()
{
	return cp;
}

string Autodromo::getASstring()
{
	ostringstream buffero;
	buffero << N << "||" << nome << "||" << cp << endl;
	return buffero.str();
}




Autodromo::~Autodromo()
{
}

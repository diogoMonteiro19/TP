#include "Autodromo.h"
#include"Pista.h"



Autodromo::Autodromo(int num,int com,string& n)
{
	nome = n;
	N = num;
	p->setComprimento(com);
}


Autodromo::~Autodromo()
{
}

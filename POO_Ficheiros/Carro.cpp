#include"Carro.h"
#include"Piloto.h"
#include"lib.h"

int Carro::nid = 0;
Carro::Carro(string ma, string mo,float cm,float ci)
{
	string i[27]{ "a","b","c","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	marca = ma;
	modelo = mo;
	p = nullptr;
	ocupado = false;
	if (nid> 27)
		id = "?";
	else
		id = i[nid];
	capmax = cm;	
	capini = ci;
	nid++;
	morto = false;

}

Carro::Carro(string ma)
{
	string i[27]{ "a","b","c","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	marca = ma;
	p = nullptr;
	ocupado = false;
	modelo = "modelo base";
	if (nid > 27)
		id = "?";
	else
		id = i[nid];
}

string Carro::getAsString()
{
	ostringstream buffero;
	buffero << capini << "||" << capmax << "||" << marca << "||" << modelo<<"||"<<id << endl;
	return buffero.str();
}

string Carro::getNome()
{
	return id;
}

bool Carro::getOcupado()
{
	return ocupado;
}

void Carro::TOcupado()
{
	ocupado = true;
}

void Carro::setJunta(Piloto* pi)
{
	p = pi;
}

void Carro::FOcupado()
{
	ocupado = false;
}

void Carro::RemovePil()
{
	p = nullptr;
}

string Carro::getNP()
{
	return p->getN();
}

void Carro::trocaMove(bool t)
{
	move = t;
}

void Carro::carregab()
{
	capini = capmax;
}

bool Carro::getMorto()
{
	return morto;
}

void Carro::setMorto(bool t)
{
	morto = t;
}






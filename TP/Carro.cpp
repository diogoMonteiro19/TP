#include"Carro.h"
#include"lib.h"

int Carro::nid = 0;
Carro::Carro(string ma, string mo,int cm,int ci)
{
	string i[27]{ "a","b","c","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	marca = ma;
	modelo = mo;
	if (nid> 27)
		id = "?";
	else
		id = i[nid];
	capmax = cm;	
	capini = ci;
	nid++;

}

Carro::Carro(string ma)
{
	string i[27]{ "a","b","c","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	marca = ma;
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




#include"Carro.h"


Carro::Carro(string ma, string mo,int cm,int ci)
{
	string i[27]{ "a","b","c","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	marca = ma;
	modelo = mo;
	if (count > 27)
		id = "?";
	else
		id = i[++count];
	capmax = cm;
	capini = ci;

}

Carro::Carro(string ma)
{
	string i[27]{ "a","b","c","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	marca = ma;
	modelo = "modelo base";
	count = count + 1;
	if (count > 27)
		id = "?";
	else
		id = i[count];
}

string Carro::getAsString()
{
	ostringstream buffero;
	buffero << capini << "||" << capmax << "||" << marca << "||" << modelo<<"||"<<id << endl;
	return buffero.str();
}



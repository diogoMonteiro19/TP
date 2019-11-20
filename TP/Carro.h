#pragma once
#include"lib.h"
using namespace std;
class Carro
{
	string marca, modelo;
	string id;
	int energia;
	int count=-1;
	int capmax;
	int capini;
public:
	Carro(string ma,string mo,int cm,int ci);
	Carro(string ma);
	string getAsString();
};


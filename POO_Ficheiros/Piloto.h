#pragma once
#include"lib.h"

class Piloto
{
	string tipo;
	string nome;
	bool dentro;
	bool partiu;
	int x;
	int random;
public:
	Piloto(string t,string n);//verificar nomes iguais
	string getAsString();
	string getN();
	bool getDentro();
	void TDentro();
	void FDentro();
	virtual void CReagePartida()=0;
	virtual void RReageAcelera()=0;
	virtual void RReageProb()=0;
	string getTipo();
	bool getP();
	void setP(bool t);
	int getX();
	void setX(int nx);
	int getR();
	void setR(int t);
	~Piloto();
};


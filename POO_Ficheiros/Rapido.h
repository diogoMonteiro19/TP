#pragma once
#include "lib.h"
#include "Piloto.h"

class Rapido: public Piloto
{
public:
	Rapido(string t, string n) : Piloto(t, n) {};
	void RReageAcelera()override;
	void RReageProb()override;
	void CReagePartida()override;
};


#pragma once
#include"Piloto.h"
#include"lib.h"

class crazy:public Piloto
{
public:
	crazy(string t, string n) :Piloto(t, n) {}
	void CReagePartida()override;
	void RReageAcelera()override;
	void RReageProb()override;
};


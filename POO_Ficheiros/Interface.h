#pragma once
#include"lib.h"
#include"Interface.h"
#include"Pares.h"

class Interface
{
	vector<Pares*> lpa;
	int nseg;
public:
	Interface(vector<Pares*> l);
	void mostra(int ncar);
	void anda(int comp, int ncar);
};


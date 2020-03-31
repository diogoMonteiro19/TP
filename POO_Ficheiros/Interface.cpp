#include "Interface.h"
#include"lib.h"
#include"Consola.h"
#include<ctime>
#include<chrono>
#include<thread>

using namespace chrono;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

Interface::Interface(vector<Pares*> l)
{
	lpa = l;
	nseg = 0;
}

void Interface::mostra(int ncar) {
	int x = 1;
	int y = 4;

	for (int i = 0; i < ncar; i++) {
		Consola::gotoxy(1, y);
		cout << lpa[i]->getCarro();
		y++;
	}
}

void Interface::anda(int comp, int ncar)
{
	int xii = 1;
	int yii = 4;
	int xi = 2;
	int yi = 4;
	int x = 1;
	int y = 4;
	nseg = 0;
	bool partida=false;
	int num=0;
	int aux=0;

	for (int i = 0; i <= comp; i++) {
		sleep_for(1s);
		nseg++;
		y = yii;
		for (int j = 0; j < ncar; j++) {
			if (lpa[j]->getTipo() == "crazy" && lpa[j]->getP() == false) {
				if (nseg == 1) {
					lpa[j]->setR();
				}
					if (nseg == lpa[j]->getRand()) {
						Consola::gotoxy(lpa[j]->getXP()-1, y);
						cout << " ";
						Consola::gotoxy(lpa[j]->getXP(), y);
						aux = lpa[j]->getXP();
						//lpa[j]->setPos(x);
						lpa[j]->setXP(++aux);
						if (lpa[j]->getM() == false) {
							cout << lpa[j]->getCarro();
						}
						lpa[j]->setP(true);
					}
			}
			else if (lpa[j]->getTipo() == "crazy" && lpa[j]->getP() == true) {
				Consola::gotoxy(lpa[j]->getXP() - 1, y);
				cout << " ";
				Consola::gotoxy(lpa[j]->getXP(), y);
				aux = lpa[j]->getXP();
				lpa[j]->setXP(++aux);
				//lpa[j]->setPos(xi);
				if (lpa[j]->getM() == false)
					cout << lpa[j]->getCarro();
			}
			else {
				Consola::gotoxy(lpa[j]->getXP() - 1, y);
				cout << " ";
				Consola::gotoxy(lpa[j]->getXP(), y);
				aux = lpa[j]->getXP();
				lpa[j]->setXP(++aux);
				//lpa[j]->setPos(x);
				if (lpa[j]->getM() == false)
					cout << lpa[j]->getCarro();
			}
			y++;
		}
		x++;
	}
}

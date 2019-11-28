#include"lib.h"
#include"mundo.h"
#include"Piloto.h"
#include"Carro.h"
#include"Autodromo.h"
#include"campeonato.h"
//
//ostream& operator <<(ostream& o, const mundo& k) {
//	o << k.getAsString();
//	return o;
//}

int main(){
	mundo a;
	int cEsp = 0, capi = 0, capm = 0, ncarros = 0, comp = 0;
	string comando,userStr,com2,com3,com4,aux1,aux2;
	cout << "Introduza comando: ";
	getline(cin, userStr);
	istringstream iss(userStr);
	iss >> comando;



	if (comando == "carregP") {
		iss >> com2;
		a.CarregaP(com2);
	}
	else if (comando == "carregaC") {
		iss >> com2;
		a.CarregaC(com2);
	}
	else if (comando == "carregaA") {
		iss >> com2;
		a.CarregaA(com2);
	}
	else if (comando == "cria") {
		iss >> com2;
		if (com2 == "p") {
			iss >> com3;
			iss >> com4;
			a.addPiloto(com3,com4);
		}
		else if (com2 == "c") {
			iss >>aux1;
			stringstream x(aux1);
			x >> capi;
			iss >> aux2;
			stringstream z(aux2);
			z >> capm;
			iss >> com3;
			iss >> com4;
			a.addCarro(com3,com4,capm,capi);
		}
		else if (com2 == "a") {
			iss >> aux1;
			stringstream y(aux1);
			y >> ncarros;
			iss >> aux2;
			stringstream g(aux2);
			g >> comp;
			iss >> com3;
			a.addAutodromo(ncarros,comp,com3);
		}
	}
//	else if (comando == "apaga") {
//
//	}
//	else if (comando == "entranocarro") {
//
	else if (comando == "campeonato") {
		a.criaCamp(iss);
	}



return 0;
}
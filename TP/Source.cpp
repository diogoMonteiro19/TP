#include"lib.h"
#include"mundo.h"
//
//ostream& operator <<(ostream& o, const mundo& k) {
//	o << k.getAsString();
//	return o;
//}

int main(){
	mundo a;
	int cEsp=0;
	string comando,userStr,com2;
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
//	else if (comando == "carregaA") {
//
//	}
//	else if (comando == "cria") {
//
//	}
//	else if (comando == "apaga") {
//
//	}
//	else if (comando == "entranocarro") {
//
//	}else if(com)
//
//	
//	mundo a;
//
//a.CarregaC("carro.txt");

return 0;
}
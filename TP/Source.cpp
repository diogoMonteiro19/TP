#include"lib.h"
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
	iss >> com2;
	for (int i = 0; i < userStr.length(); i++) {
		cEsp++;
	}


/*	if (comando == "carregP") {
//
//	}
	else*/ if (comando == "carregaC") {
		cout << "tou aqui ......";
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
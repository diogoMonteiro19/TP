#include "Interaçao.h"
#include"lib.h"
#include"mundo.h"
#include"Piloto.h"
#include"Carro.h"
#include"Autodromo.h"
#include"campeonato.h"
#include"Interface.h"


void Interaçao::corre() {
	mundo a;
	int cEsp = 0, capi = 0, capm = 0, ncarros = 0, comp = 0;
	string comando, userStr, com2, com3, com4, aux1, aux2;
	bool camp=false;
	float quantidade;

	cout << "Comandos Modo 1:\n"
		<< "\tcarregaP <nomeF>\n"
		<< "\tcarregaC <nomeF>\n"
		<< "\tcarregaA <nomeF>\n"
		<< "\tcria <tipo> <dados>\n"
		<< "\tapaga <tipo> <id>\n"
		<< "\tlista\n"
		<< "\tentranocarro <letraC> <nomeP>\n"
		<< "\tsaidocarro <letraC>\n"
		<<"Comandos Modo 2:\n"
		<<"\tcampeonato <nomeA>\n(Note que estes comandos derivados do campeonato apenas podem ser executados se existir um campeonato criado)\n"
		<<endl
		<<"\t\tstart(inicia a corrida)\n"
		<<"\t\tlistacarros\n"
		<< "\t\tlistapares\n"
		<<"\t\tcarregatudo\n"
		<< "\t\tacidente <letraCarro>\n"
		<< endl;

	while (true) {
		cout << "Introduza comando: ";
		getline(cin, userStr);
		istringstream iss(userStr);
		iss >> comando;
		if (comando == "carregaP") {
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
				a.addPiloto(com3, com4);
			}
			else if (com2 == "c") {
				iss >> aux1;
				stringstream x(aux1);
				x >> capi;
				iss >> aux2;
				stringstream z(aux2);
				z >> capm;
				iss >> com3;
				iss >> com4;
				a.addCarro(com3, com4, capm, capi);
			}
			else if (com2 == "a") {
				iss >> aux1;
				stringstream y(aux1);
				y >> ncarros;
				iss >> aux2;
				stringstream g(aux2);
				g >> comp;
				iss >> com3;
				a.addAutodromo(ncarros, comp, com3);
			}
		}
		else if (comando == "apaga") {
			iss >> com2;
			if (com2 == "p") {
				iss >> com3;
				a.removePiloto(com3);
			}
			else if (com2 == "c") {   //com3 vai ser o ID do carro
				iss >> com3;
				a.removeCarro(com3);
			}
			else if (com2 == "a") {
				iss >> com3;
				a.removeAutodromo(com3);
			}
		}

		else if (comando == "entranocarro") {
			iss >> com2;
			iss >> com3;
			cout << a.entraNoCarro(com3, com2);
		}
		else if (comando == "saidocarro") {
			iss >> com2;
			a.saiDoCarro(com2);
		}
		else if (comando == "campeonato") {
			a.criaCamp(iss);
			a.verPares();
			camp = true;
		}
		else if(comando == "listacarros"){
			if (camp == true)
				a.listarCarrosEmCorrida();
			else
				cout << "Nao existe campeonato, crie um primeiro!!\n";
		}
		else if (comando == "start") {
			if (camp == true) {
				a.imprime();
				a.mostraC();
			}
			else
				cout << "Nao existe campeonato, crie um primeiro!!\n";
		}
		else if (comando == "carregatudo") {
			if (camp == true) {
				cout<<a.carregabat();
			}
			else
				cout << "Nao existe campeonato, crie um primeiro!!\n";
		}
		else if (comando == "acidente") {
			if (camp == true) {
				iss >> com2;
				cout<<a.acidente(com2);
			}
			else
				cout << "Nao existe campeonato, crie um primeiro!!\n";
		}
		else if (comando == "lista") {
			a.verCarros();
			a.verPilotos();
			a.verAutodromo();
		}
		else if (comando == "t") {
			a.CarregaA("autodromo.txt");
			a.CarregaC("carro.txt");
			a.CarregaP("piloto.txt");
		}
		else if (comando == "listapares") {
			a.verPares();
		}
		else if (comando == "sair") {
			exit(1);
		}
	}
}
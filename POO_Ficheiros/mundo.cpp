#include "mundo.h"
#include"Carro.h"
#include"Piloto.h"
#include"Autodromo.h"
#include"campeonato.h"
#include"Consola.h"
#include<ctime>
#include<chrono>
#include<thread>
#include"lib.h"
#include"Interface.h"
#include"Rapido.h"
#include"crazy.h"

using namespace chrono;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

int mundo::conta = 1;


mundo::mundo()
{
	novo = nullptr;
	camp = false;
}

void mundo::CarregaC(string nf)
{
	ifstream ficheiro(nf);
	if (ficheiro) {
		string linha;
		while (getline(ficheiro, linha)) {
			istringstream buffer(linha);
			string mar, mod;
			int ci, cm;
			if (buffer >> ci  && buffer >> cm && buffer>>mar && buffer >> mod) {
				Carro *p = new Carro(mar,mod,cm,ci);
				lc.push_back(p);
			}
		}
	}
	for (int i = 0; i < lc.size();i++) {
		cout << lc[i]->getAsString();
	}	
	
}

void mundo::CarregaP(string nf)
{
	ifstream ficheiro(nf);
	if (ficheiro) {
		string linha;
		while (getline(ficheiro, linha)) {
			istringstream buffer(linha);
			string no, ti;
			if (buffer >> ti  && buffer >> no) {
				if (ti == "rapido") {
					lp.push_back(new Rapido(ti, no));
				}
				else if(ti == "crazy"){
					lp.push_back(new crazy(ti, no));
				}
			}
		}
	}
	for (int i = 0; i < lp.size();i++) {
		cout << lp[i]->getAsString();
	}

}

bool mundo::verificaP(string np)
{
	for (int i=0; i<lp.size();i++) {
		if (lp[i]->getN() == np) {
			return true;
		}
	}
	return false;
}

void mundo::CarregaA(string nf)
{
	ifstream ficheiro(nf);
	if (ficheiro) {
		string linha;
		while (getline(ficheiro, linha)) {
			istringstream buffer(linha);
			string no;
			int num,com;
			if (buffer >> num && buffer >> com && buffer >> no) {
				Autodromo* p = new Autodromo(num,com,no);
				la.push_back(p);
			}
		}
	}
	for (int i = 0; i < la.size(); i++) {
		cout << la[i]->getAsString();
	}
}

void mundo::addPiloto(string& t,string& n)
{
	if (!verificaP(n)) {
		if(t == "rapido")
		//Piloto* outro = new Rapido(t, n);
		lp.push_back(new Rapido(t, n));
		else if (t == "crazy") {

		}
	}
	else {
		string auxn;
		ostringstream o;
		o << n << conta;
		auxn = o.str();
		conta++;
		if (t == "rapido"){
			//Piloto* novo = new Piloto(auxn, n);
			lp.push_back(new Rapido(auxn, n));
		}
	}
}

void mundo::addCarro(string& ma, string& mo, int cm, int ci)
{
	Carro* novo = new Carro(ma, mo, cm, ci);
	lc.push_back(novo);
}

void mundo::addAutodromo(int nc, int com, string& na)
{
	Autodromo* novo = new Autodromo(nc, com, na);
	la.push_back(novo);
}

void mundo::criaCamp(istringstream& dados)
{
	camp = true;
	novo = new campeonato(dados,lp,lc,vp);
}

void mundo::removePiloto(string n)
{
	for (auto ptr = lp.begin(); ptr != lp.end();) {
		if ((*ptr)->getN() == n) {
			delete* ptr;
			ptr = lp.erase(ptr);
		}
		else ptr++;
	}
}

void mundo::removeCarro(string id)
{
	for (auto ptr = lc.begin(); ptr != lc.end();) {
		if ((*ptr)->getNome() == id) {
			delete* ptr;
			ptr = lc.erase(ptr);
		}
		else ptr++;
	}
}

void mundo::removeAutodromo(string n)
{
	for (auto ptr = la.begin(); ptr != la.end();) {
		if ((*ptr)->getNome() == n) {
			delete* ptr;
			ptr = la.erase(ptr);
		}
		else ptr++;
	}
}

string mundo::entraNoCarro(string np, string id)
{
	string aux;
	ostringstream buffero;
	for (int i=0; i < lp.size();i++) {
		if (lp[i]->getN() == np) {
			if (lp[i]->getDentro()) {
				aux = "O piloto esta dentro do carro";
				return aux;
			}
			else {
				for (int j = 0; j < lc.size();j++) {
					if(lc[j]->getNome() == id){
						if (lc[j]->getOcupado()) {
							aux = "O carro esta ocupado";
							return aux;
						}
						else
						{
							lp[i]->TDentro();
							lc[j]->TOcupado();
							lc[j]->setJunta(lp[i]);
							Pares* p = new Pares(lp[i], lc[j]);
							vp.push_back(p);
							if (camp)
								novo->addPar(p);
							buffero << "O Piloto entrou no carro com id: " << lc[j]->getNome()<<endl;
						}
					}
				}
			}
		}
	}
	return buffero.str();
}

void mundo::saiDoCarro(string id)
{
	for (int i = 0; i < lc.size();i++) {
		if (lc[i]->getNome() == id) {
			if(camp)
				novo->separa(id);
			else
				{
				for (auto ptr = vp.begin(); ptr != vp.end();) {
						if ((*ptr)->getCarro() == id) {
							delete* ptr;
							ptr = vp.erase(ptr);
						}
						ptr++;
					}
				}
			lc[i]->FOcupado();
			for (int j = 0; j< lp.size(); j++) {
				if (lp[j]->getN() == lc[i]->getNP()) {
					lp[j]->FDentro();
				}
			}
			lc[i]->RemovePil();
		}
	}
}
void mundo::imprime()
{
	int ncarros = novo->ncarros();

	for (int i = 0; i < ncarros; i++) {
		novo->andar(true);
	}
	int compPista,compTraco;

	Consola::clrscr();
	Consola::setScreenSize(64, 40);
	compPista = compPistaAtual();
	compTraco = compPista / 60;
	Consola::gotoxy(1,0);
	cout << "|";
	Consola::gotoxy(62, 0);
	cout << "|";
	Consola::gotoxy(1, 1);
	for (int i = 0; i < 62; i++) {
		Consola::gotoxy(i + 1, 1);
		if (i == 0 || i == 61) {
			cout << "|";
		}
		else
			cout << "-";
	}
	Consola::gotoxy(1, 2);
	cout << "|";
	Consola::gotoxy(62, 2);
	cout << "|";
	Consola::gotoxy(1, 3);
	cout << compPista<<"||"<< compTraco;
}

int mundo::compPistaAtual()
{
	for (int i = 0; i < la.size();i++) {
		if (la[i]->getNome() == novo->retornaAuto()) {
			return la[i]->retComp();
		}
	}
	cout << "O autodromo inserido nao existe!!" << endl;
	exit(0);
}


void mundo::verCarros()
{
	for (int i = 0; i < lc.size(); i++) {
		cout << lc[i]->getAsString();
	}
}

void mundo::verPilotos()
{
	for (int i = 0; i < lp.size(); i++) {
		cout << lp[i]->getAsString();
	}
}

void mundo::verAutodromo()
{
	for (int i = 0; i < la.size(); i++) {
		cout << la[i]->getAsString();
	}
}

void mundo::verPares()
{
	cout << novo->mostraPares();
}

void mundo::mostraC()
{
	int comp = compPistaAtual();
	novo->MostraCorrida(comp);
}

void mundo::listarCarrosEmCorrida()
{
	cout<<novo->listaCarros();
}

string mundo::carregabat()
{
	novo->carregab();
	ostringstream oss;
	oss << "Os carros foram todos carregados para a sua bateria maxima" << endl;
	return oss.str();
}

string mundo::acidente(string nc)
{
	novo->acidente(nc);
	ostringstream os;
	os << "O carro com a letra " << nc << " teve um acidente!!" << endl;
	return os.str();
}

void mundo::enviaListaAuto()
{
	novo->recebeAutos(la);
}



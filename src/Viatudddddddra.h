#pragma once
#include <string>
#include <vector>

using namespace std;

/*
class Motorizado: public Veiculo {
protected:
	string combustivel;
	int cilindrada;
public:
	Motorizado(string Marca, int Mes, int Ano, string Combustivel, int Cilindrada) : Veiculo(Marca, Mes, Ano), combustivel(Combustivel), cilindrada(Cilindrada) {}
	string getCombustivel() const { return combustivel; }
	float calcImposto() const;
};


class Automovel: public Motorizado {
public:
	Automovel(string Marca, int Mes, int Ano, string Combustivel, int Cilindrada) : Motorizado(Marca, Mes, Ano, Combustivel, Cilindrada) {}
	int info() const;
};

class Camiao: public Motorizado {
	int carga_maxima;
public:
	Camiao(string Marca, int Mes, int Ano, string Combustivel, int Cilindrada, int CargaMaxima)  : Motorizado(Marca, Mes, Ano, Combustivel, Cilindrada), carga_maxima(CargaMaxima) {}
	int info() const;
};


class Frota {
	vector<Veiculo*> veiculos;
public:
	int numVeiculos() const { return veiculos.size(); }
	void adicionaVeiculo(Veiculo *v1);
	int menorAno() const;
	void info() const;
	float totalImposto() const;
};

*/

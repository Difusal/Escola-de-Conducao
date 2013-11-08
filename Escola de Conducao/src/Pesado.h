#ifndef PESADO_H_
#define PESADO_H_
#include "Automovel.h"

class Pesado: public Automovel {
protected:
	int cargaMaxima;
public:
	Pesado(string Matricula, int Ano, string Marca, int Periodicidade, int CargaMaxima) : Automovel(Matricula, Ano, Marca, Periodicidade), cargaMaxima(CargaMaxima) {}
	virtual ~Pesado() {}

	string getTipo() const { return "pesado"; }
	int info();

	int getCargaMaxima() { return cargaMaxima; }
};

#endif

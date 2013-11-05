#ifndef PESADO_H_
#define PESADO_H_
#include "Automovel.h"

class Pesado: public Automovel {
protected:
	int cargaMaxima;
public:
	Pesado(string Matricula, int Ano, string Marca, int CargaMaxima) : Automovel(Matricula, Ano, Marca), cargaMaxima(CargaMaxima) {}
	virtual ~Pesado() {}

	int info() const;

	int getCargaMaxima() { return cargaMaxima; }
};

#endif

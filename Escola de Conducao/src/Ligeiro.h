#ifndef LIGEIRO_H_
#define LIGEIRO_H_
#include "Automovel.h"

class Ligeiro: public Automovel {
public:
	Ligeiro(string Matricula, int Ano, string Marca, int Periodicidade) : Automovel(Matricula, Ano, Marca, Periodicidade) {}
	virtual ~Ligeiro() {}

	TipoCartaConducao getTipo() const { return LIGEIRO; }
	string getTipoNumaString() const { return "ligeiro"; }
	int info();
};

#endif

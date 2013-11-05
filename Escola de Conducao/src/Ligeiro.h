#ifndef LIGEIRO_H_
#define LIGEIRO_H_
#include "Automovel.h"

class Ligeiro: public Automovel {
public:
	Ligeiro(string Matricula, int Ano, string Marca) : Automovel(Matricula, Ano, Marca) {}
	virtual ~Ligeiro() {}

	int info() const;
};

#endif

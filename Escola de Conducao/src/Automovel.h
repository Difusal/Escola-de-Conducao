#ifndef AUTOMOVEL_H_
#define AUTOMOVEL_H_
#include "Viatura.h"

class Automovel: public Viatura {
public:
	Automovel(string Matricula, int Ano, string Marca, int Periodicidade) : Viatura(Matricula, Ano, Marca, Periodicidade) {}
	virtual ~Automovel() {}

	virtual int info();
};

#endif

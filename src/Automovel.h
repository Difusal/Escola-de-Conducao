#ifndef AUTOMOVEL_H_
#define AUTOMOVEL_H_
#include "Viatura.h"

class Automovel: public Viatura {
public:
	Automovel(string Matricula, int Ano, string Marca) : Viatura(Matricula, Ano, Marca) {}
	virtual ~Automovel() {}

	int info() const;
};

#endif

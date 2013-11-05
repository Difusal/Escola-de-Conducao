#ifndef MOTOCICLO_H_
#define MOTOCICLO_H_
#include "Viatura.h"

class Motociclo: public Viatura {
public:
	Motociclo(string Matricula, int Ano, string Marca) : Viatura(Matricula, Ano, Marca) {}
	virtual ~Motociclo() {}

	int info() const;
};

#endif

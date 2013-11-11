/*!
 * \file Motociclo.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
#ifndef MOTOCICLO_H_
#define MOTOCICLO_H_
#include "Viatura.h"

class Motociclo: public Viatura {
public:
	Motociclo(string Matricula, int Ano, string Marca, int Periodicidade) : Viatura(Matricula, Ano, Marca, Periodicidade) {}
	virtual ~Motociclo() {}

	TipoCartaConducao getTipo() const { return MOTOCICLO; }
	string getTipoNumaString() const { return "motociclo"; }
	int info();
};

#endif

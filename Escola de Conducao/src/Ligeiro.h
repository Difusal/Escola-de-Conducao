/*!
 * \file Ligieiro.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
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

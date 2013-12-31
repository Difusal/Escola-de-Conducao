/*!
 * \file Ligeiro.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Maria Joao Marques
 * \author Tiago Figueiredo
 *
 * \date Dezembro 2013
 *
 */
#ifndef LIGEIRO_H_
#define LIGEIRO_H_
#include "Automovel.h"

class Ligeiro: public Automovel {
public:
	/**
	 * Copy Constructor
	 */
	Ligeiro(string Matricula, int Ano, string Marca, int Periodicidade) : Automovel(Matricula, Ano, Marca, Periodicidade) {}
	/**
	 * Destructor
	 */
	virtual ~Ligeiro() {}

	/**
	 * Get tipo de carta de conducao
	 */
	TipoCartaConducao getTipo() const { return LIGEIRO; }
	/**
	 * Get tipo numa string
	 */
	string getTipoNumaString() const { return "ligeiro"; }
	/**
	 * Info de um ligeiro
	 */
	int info();
};

#endif

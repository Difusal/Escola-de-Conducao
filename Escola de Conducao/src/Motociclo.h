/*!
 * \file Motociclo.h
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
#ifndef MOTOCICLO_H_
#define MOTOCICLO_H_
#include "Viatura.h"

class Motociclo: public Viatura {
public:
	/**
	 * Copy Constructor
	 */
	Motociclo(string Matricula, int Ano, string Marca, int Periodicidade) : Viatura(Matricula, Ano, Marca, Periodicidade) {}
	/**
	 * Destructor
	 */
	virtual ~Motociclo() {}

	/**
	 * Get tipo de carta de conducao
	 */
	TipoCartaConducao getTipo() const { return MOTOCICLO; }
	/**
	 * Get tipo numa string
	 */
	string getTipoNumaString() const { return "motociclo"; }
	/**
	 * Info de um motociclo
	 */
	int info();
};

#endif

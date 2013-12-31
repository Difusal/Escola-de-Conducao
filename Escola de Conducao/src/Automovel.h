/*!
 * \file Automovel.h
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
#ifndef AUTOMOVEL_H_
#define AUTOMOVEL_H_
#include "Viatura.h"

class Automovel: public Viatura {
public:
	/**
	 * Copy Constructor
	 */
	Automovel(string Matricula, int Ano, string Marca, int Periodicidade) : Viatura(Matricula, Ano, Marca, Periodicidade) {}
	/**
	 * Destructor
	 */
	virtual ~Automovel() {}

	/**
	 * Info do automovel
	 */
	virtual int info();
};

#endif

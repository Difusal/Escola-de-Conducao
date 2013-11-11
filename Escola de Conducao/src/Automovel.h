/*!
 * \file Automovel.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
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

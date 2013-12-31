/*!
 * \file Pesado.h
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
#ifndef PESADO_H_
#define PESADO_H_
#include "Automovel.h"

class Pesado: public Automovel {
public:
	/**
	 * Copy Constructor
	 */
	Pesado(string Matricula, int Ano, string Marca, int Periodicidade) : Automovel(Matricula, Ano, Marca, Periodicidade) {}
	/**
	 * Destructor
	 */
	virtual ~Pesado() {}

	/**
	 * Get tipo de carta de conducao
	 */
	TipoCartaConducao getTipo() const { return PESADO; }
	/**
	 * Get tipo numa string
	 */
	string getTipoNumaString() const { return "pesado"; }
	/**
	 * Info do veiculo pesado
	 */
	int info();
};

#endif

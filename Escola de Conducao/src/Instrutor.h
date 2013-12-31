/*!
 * \file Instrutor.h
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
#ifndef INSTRUTOR_H_
#define INSTRUTOR_H_

#include "Pessoa.h"
#include <vector>

class Instrutor: public Pessoa {
private:
	bool qualificacoes[3];
public:
	/**
	 * Copy Constructor
	 */
	Instrutor(string Nome, bool qualifLig, bool qualifPes, bool qualifMoto) : Pessoa(Nome) {
		qualificacoes[0] = qualifLig;
		qualificacoes[1] = qualifPes;
		qualificacoes[2] = qualifMoto;
	}
	/**
	 * Destructor
	 */
	virtual ~Instrutor() {}

	/**
	 * Info sobre o instrutor
	 */
	int info();
	/**
	 * Print info sobre o instrutor
	 */
	string printToFile() const;

	/**
	 * Numero de qualificacoes do instrutor
	 */
	int numQualificacoes() {
		int x = 0;
		FOR(i, 0, 3) {
			if (qualificacoes[i])
				x++;
		}
		return x;
	}

	/**
	 * Set qualificacoes do instrutor
	 */
	void setQualificacoes(bool Lig, bool Pes, bool Moto);
	/**
	 * Verifica se o instrutor e qualificado
	 */
	bool isQualifiedFor(TipoCartaConducao Tipo) { return qualificacoes[Tipo]; }
};

#endif /* INSTRUTOR_H_ */

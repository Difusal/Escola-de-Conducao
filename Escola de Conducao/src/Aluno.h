/*!
 * \file Aluno.h
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
#ifndef ALUNO_H_
#define ALUNO_H_

#include "Pessoa.h"
#include <vector>
#include "Instrutor.h"

class Aluno: public Pessoa {
private:
	TipoCartaConducao tipoDeCarta;
	Viatura *viaturaUsual;
	string nomeInstrutor;
public:
	/**
	 * Copy Constructor
	 */
	Aluno(string Nome, TipoCartaConducao CartaDe, Viatura *ViaturaUsual, string NomeInstrutor) :
			Pessoa(Nome), tipoDeCarta(CartaDe), viaturaUsual(ViaturaUsual), nomeInstrutor(NomeInstrutor) {}
	/**
	 * Destructor
	 */
	virtual ~Aluno() {}

	/**
	 * Info do aluno
	 */
	int info();
	/**
	 * Print info do aluno
	 */
	string printToFile() const;

	/**
	 * Set nome do instrutor do aluno
	 */
	void setNomeInstrutor(string nome) { nomeInstrutor = nome; }

	/**
	 * Get tipo de carta do aluno
	 */
	TipoCartaConducao getTipoDeCarta() {
		return tipoDeCarta;
	}
	/**
	 * Set tipo de carta do aluno
	 */
	void setTipoDeCarta(TipoCartaConducao Tipo) {
		tipoDeCarta = Tipo;
	}

	/**
	 * Get viatura usual do aluno
	 */
	Viatura *getViaturaUsual() {
		return viaturaUsual;
	}

	/**
	 * Set viatura usual do aluno
	 */
	void setViaturaUsual(Viatura *viatura) { viaturaUsual = viatura; }
};

#endif

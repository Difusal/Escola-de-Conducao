/*!
 * \file Aluno.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
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
	Aluno(string Nome, TipoCartaConducao CartaDe, Viatura *ViaturaUsual, string NomeInstrutor) :
			Pessoa(Nome), tipoDeCarta(CartaDe), viaturaUsual(ViaturaUsual), nomeInstrutor(NomeInstrutor) {}
	virtual ~Aluno() {}

	int info();
	string printToFile() const;

	void setNomeInstrutor(string nome) { nomeInstrutor = nome; }

	TipoCartaConducao getTipoDeCarta() {
		return tipoDeCarta;
	}
	void setTipoDeCarta(TipoCartaConducao Tipo) {
		tipoDeCarta = Tipo;
	}

	Viatura *getViaturaUsual() {
		return viaturaUsual;
	}

	void setViaturaUsual(Viatura *viatura) { viaturaUsual = viatura; }
};

#endif

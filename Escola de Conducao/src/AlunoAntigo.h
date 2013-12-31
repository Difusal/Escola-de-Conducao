/*!
 * \file AlunoAntigo.h
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
#ifndef ALUNOANTIGO_H_
#define ALUNOANTIGO_H_

#include "Pessoa.h"
//#include <vector>
#include "Instrutor.h"

class AlunoAntigo: public Pessoa {
private:
	TipoCartaConducao tipoDeCarta;
	string nomeInstrutor;
	string contacto;
public:
	/**
	 * Copy Constructor
	 */
	AlunoAntigo(string Nome, TipoCartaConducao CartaDe, string NomeInstrutor, string Contacto) :
			Pessoa(Nome), tipoDeCarta(CartaDe), nomeInstrutor(NomeInstrutor), contacto(Contacto) {}
	/**
	 * Destructor
	 */
	virtual ~AlunoAntigo() {}

	/**
	 * Info do aluno antigo
	 */
	int info();

	/**
	 * Print info do aluno antigo
	 */
	string printToFile() const;

	/**
	 * Get nome do instrutor do aluno antigo
	 */
	string getNomeInstrutor() { return nomeInstrutor; }

	/**
	 * Get tipo de carta do aluno antigo
	 */
	TipoCartaConducao getTipoDeCarta() { return tipoDeCarta; }

	/**
	 * Get contacto do aluno antigo
	 */
	string getContacto() {return contacto;}

	/**
	 * Set contacto do aluno antigo
	 */
	void setContacto(string Contacto) { contacto=Contacto; }


};

#endif

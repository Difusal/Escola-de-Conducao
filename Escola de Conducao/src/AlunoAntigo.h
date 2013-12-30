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
	AlunoAntigo(string Nome, TipoCartaConducao CartaDe, string NomeInstrutor, string Contacto) :
			Pessoa(Nome), tipoDeCarta(CartaDe), nomeInstrutor(NomeInstrutor), contacto(Contacto) {}
	virtual ~AlunoAntigo() {}

	int info();

	string printToFile() const;

	string getNomeInstrutor() { return nomeInstrutor; }

	TipoCartaConducao getTipoDeCarta() { return tipoDeCarta; }

	string getContacto() {return contacto;}

	void setContacto(string Contacto) { contacto=Contacto; }


};

#endif

/*!
 * \file Pessoa.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
#ifndef PESSOA_H_
#define PESSOA_H_
#include <string>
using namespace std;
#include "Viatura.h"
#include "Utilities.h"

class Pessoa {
protected:
	string nome;
public:
	Pessoa(string Nome) : nome(Nome) {}
	virtual ~Pessoa() {}

	virtual int info();
	virtual string printToFile() const = 0;

	string getNome() { return nome; }
};

#endif

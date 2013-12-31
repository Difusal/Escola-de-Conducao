/*!
 * \file Pessoa.h
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
	/**
	 * Copy Constructor
	 */
	Pessoa(string Nome) : nome(Nome) {}
	/**
	 * Destructor
	 */
	virtual ~Pessoa() {}

	/**
	 * Info da pessoa
	 */
	virtual int info();
	/**
	 * Print info da pessoa
	 */
	virtual string printToFile() const = 0;

	/**
	 * Get nome da pessoa
	 */
	string getNome()  const { return nome; }
};

#endif

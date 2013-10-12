/*
 * Ligeiro.h
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#ifndef LIGEIRO_H_
#define LIGEIRO_H_

#include "Automovel.h"

class Ligeiro: public Automovel {
public:
	Ligeiro(string Matricula, int Ano, string Marca);
	virtual ~Ligeiro();
};

#endif /* LIGEIRO_H_ */

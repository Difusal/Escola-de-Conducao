/*
 * Automovel.h
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#ifndef AUTOMOVEL_H_
#define AUTOMOVEL_H_

#include "Viatura.h"

class Automovel: public Viatura {
public:
	Automovel(string Matricula, int Ano, string Marca);
	virtual ~Automovel();
};

#endif /* AUTOMOVEL_H_ */

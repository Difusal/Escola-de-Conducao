/*
 * Pesado.h
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#ifndef PESADO_H_
#define PESADO_H_

#include "Automovel.h"

class Pesado: public Automovel {
public:
	Pesado(string Matricula, int Ano, string Marca);
	virtual ~Pesado();
};

#endif /* PESADO_H_ */

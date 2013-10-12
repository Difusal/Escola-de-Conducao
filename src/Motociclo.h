/*
 * Motociclo.h
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#ifndef MOTOCICLO_H_
#define MOTOCICLO_H_

#include "Viatura.h"

class Motociclo: public Viatura {
public:
	Motociclo(string Matricula, int Ano, string Marca);
	virtual ~Motociclo();
};

#endif /* MOTOCICLO_H_ */

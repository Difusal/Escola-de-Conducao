/*
 * Instrutor.h
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#ifndef INSTRUTOR_H_
#define INSTRUTOR_H_

#include "Pessoa.h"

class Instrutor: public Pessoa {
public:
	Instrutor(string Nome) : Pessoa(Nome) {
		// TODO Auto-generated constructor stub

	}
	virtual ~Instrutor();
};

#endif /* INSTRUTOR_H_ */

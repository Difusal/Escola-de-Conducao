#ifndef ALUNO_H_
#define ALUNO_H_

#include "Pessoa.h"

class Aluno: public Pessoa {
public:
	Aluno(string Nome) : Pessoa(Nome) {}
	virtual ~Aluno();


};

#endif /* ALUNO_H_ */

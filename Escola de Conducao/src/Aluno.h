#ifndef ALUNO_H_
#define ALUNO_H_

#include "Pessoa.h"
#include <vector>
#include "Instrutor.h"

class Aluno: public Pessoa {
private:
	TipoCartaConducao tipoDeCarta;
public:
	Aluno(string Nome, TipoCartaConducao CartaDe) : Pessoa(Nome), tipoDeCarta(CartaDe) {}
	virtual ~Aluno();

	int info();
	string printToFile() const;

	TipoCartaConducao getTipoDeCarta() { return tipoDeCarta; }
};

#endif

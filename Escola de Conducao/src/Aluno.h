#ifndef ALUNO_H_
#define ALUNO_H_

#include "Pessoa.h"
#include <vector>
#include "Instrutor.h"

class Aluno: public Pessoa {
private:
	TipoCartaConducao tipoDeCarta;
	Viatura *viaturaUsual;
public:
	Aluno(string Nome, TipoCartaConducao CartaDe, Viatura *ViaturaUsual) :
			Pessoa(Nome), tipoDeCarta(CartaDe), viaturaUsual(ViaturaUsual) {}
	virtual ~Aluno();

	int info();
	string printToFile() const;

	TipoCartaConducao getTipoDeCarta() {
		return tipoDeCarta;
	}
	Viatura *getViaturaUsual() {
		return viaturaUsual;
	}
};

#endif

#ifndef ALUNO_H_
#define ALUNO_H_

#include "Pessoa.h"
#include <vector>
#include "Instrutor.h"

class Aluno: public Pessoa {
private:
	TipoCartaConducao tipoDeCarta;
	Viatura *viaturaUsual;
	string nomeInstrutor;
public:
	Aluno(string Nome, TipoCartaConducao CartaDe, Viatura *ViaturaUsual, string NomeInstrutor) :
			Pessoa(Nome), tipoDeCarta(CartaDe), viaturaUsual(ViaturaUsual), nomeInstrutor(NomeInstrutor) {}
	virtual ~Aluno();

	int info();
	string printToFile() const;

	TipoCartaConducao getTipoDeCarta() {
		return tipoDeCarta;
	}
	void setTipoDeCarta(TipoCartaConducao Tipo) {
		tipoDeCarta = Tipo;
	}

	Viatura *getViaturaUsual() {
		return viaturaUsual;
	}
};

#endif

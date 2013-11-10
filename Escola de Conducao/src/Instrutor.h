/*
 * Instrutor.h
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#ifndef INSTRUTOR_H_
#define INSTRUTOR_H_

#include "Pessoa.h"
#include "Aluno.h"
#include "Aula.h"
#include "Utilities.h"
#include <vector>

class Instrutor: public Pessoa {
private:
	bool qualificacoes[3];
	vector<Aluno*> alunos;
	vector<Aula*> aulas;
public:
	Instrutor(string Nome, bool qualifLig, bool qualifPes, bool qualifMoto) : Pessoa(Nome) {
		qualificacoes[0] = qualifLig;
		qualificacoes[1] = qualifPes;
		qualificacoes[2] = qualifMoto;
		alunos.clear();
		aulas.clear();
	}
	virtual ~Instrutor();

	int info();
	string printToFile() const;

	int numQualificacoes() {
		int x = 0;
		FOR(i, 0, 3) {
			if (qualificacoes[i])
				x++;
		}
		return x;
	}
	int numAlunos() { return alunos.size(); }
	int numAulas() { return aulas.size(); }

	void setQualificacoes(bool Lig, bool Pes, bool Moto);
};

#endif /* INSTRUTOR_H_ */

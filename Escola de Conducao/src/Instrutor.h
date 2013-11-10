#ifndef INSTRUTOR_H_
#define INSTRUTOR_H_

#include "Pessoa.h"
#include <vector>

class Instrutor: public Pessoa {
private:
	bool qualificacoes[3];
public:
	Instrutor(string Nome, bool qualifLig, bool qualifPes, bool qualifMoto) : Pessoa(Nome) {
		qualificacoes[0] = qualifLig;
		qualificacoes[1] = qualifPes;
		qualificacoes[2] = qualifMoto;
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
	// TODO implement these methods
	int numAlunos() { return 0;}//alunos.size(); }
	int numAulas() { return 0;}//aulas.size(); }

	void setQualificacoes(bool Lig, bool Pes, bool Moto);
};

#endif /* INSTRUTOR_H_ */

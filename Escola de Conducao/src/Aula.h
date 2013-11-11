#ifndef AULA_H_
#define AULA_H_

#include "Viatura.h"
#include "Instrutor.h"
#include "Aluno.h"
using namespace std;

class Aula {
	struct tm data;
	int hora, duracao;
	Aluno *aluno;
	Instrutor *instrutor;
	Viatura *viatura;
public:
	Aula(struct tm Data, int Hora, int Duracao, Aluno *Aluno, Instrutor *Instrutor, Viatura *Viatura) :
			data(Data), hora(Hora), duracao(Duracao), aluno(Aluno), instrutor(Instrutor), viatura(Viatura) { }
	virtual ~Aula();

	int info();
	string printToFile() const;

	struct tm getData() { return data; }
	int getHora() { return hora; }
	int getDuracao() { return duracao; }
	Aluno getAluno() { return *aluno; }
	Instrutor getInstrutor() { return *instrutor; }
	TipoCartaConducao getTipoViatura() { return viatura->getTipo(); }
	Viatura *getViatura() const { return viatura; }
	void setViaturaUsual(Viatura *Viatura) { viatura = Viatura; }
};

#endif /* AULA_H_ */

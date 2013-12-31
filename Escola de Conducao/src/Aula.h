/*!
 * \file Aula.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Maria Joao Marques
 * \author Tiago Figueiredo
 *
 * \date Dezembro 2013
 *
 */
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
	/**
	 * Copy Constructor
	 */
	Aula(struct tm Data, int Hora, int Duracao, Aluno *Aluno, Instrutor *Instrutor, Viatura *Viatura) :
			data(Data), hora(Hora), duracao(Duracao), aluno(Aluno), instrutor(Instrutor), viatura(Viatura) { }
	/**
	 * Destructor
	 */
	virtual ~Aula() {}

	/**
	 * Info da aula
	 */
	int info();
	/**
	 * Print da info da aula
	 */
	string printToFile() const;

	/**
	 * Get data da aula
	 */
	struct tm getData() { return data; }
	/**
	 * Get hora da aula
	 */
	int getHora() { return hora; }
	/**
	 * Get duracao da aula
	 */
	int getDuracao() { return duracao; }
	/**
	 * Get aluno que tem aula
	 */
	Aluno getAluno() { return *aluno; }
	/**
	 * Get instrutor que da a aula
	 */
	Instrutor getInstrutor() { return *instrutor; }
	/**
	 * Get tipo de viatura da aula
	 */
	TipoCartaConducao getTipoViatura() { return viatura->getTipo(); }
	/**
	 * Get viatura da aula
	 */
	Viatura *getViatura() const { return viatura; }
	/**
	 * Set viatura usual
	 */
	void setViaturaUsual(Viatura *Viatura) { viatura = Viatura; }
};

#endif /* AULA_H_ */

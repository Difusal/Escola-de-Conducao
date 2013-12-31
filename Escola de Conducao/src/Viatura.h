/*!
 * \file Viatura.h
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
#ifndef VIATURA_H_
#define VIATURA_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include "Utilities.h"
using namespace std;

enum TipoCartaConducao { LIGEIRO, PESADO, MOTOCICLO };

class Viatura {
protected:
	string matricula;
	int anoFabrico;
	string marca;
	struct tm dataUltimaInspecao;
	int periodicidade;
public:
	/**
	 * Copy Constructor
	 */
	Viatura(string Matricula, int Ano, string Marca, int Periodicidade) : matricula(Matricula), anoFabrico(Ano), marca(Marca), dataUltimaInspecao(*getLocalTimeInfo()), periodicidade(Periodicidade) {}
	/**
	 * Destructor
	 */
	virtual ~Viatura() {}

	/**
	 * Info do veiculo
	 */
	virtual int info();
	/**
	 * Print info do veiculo
	 */
	virtual string printToFile() const;

	// Getters e Setters
	/**
	 * Get matricula do veiculo
	 */
	string getMatricula() { return matricula; }
	/**
	 * Get ano de fabrico do veiculo
	 */
	int getAnoFabrico() { return anoFabrico; }
	/**
	 * Get marca do veiculo
	 */
	string getMarca() const { return marca; }
	/**
	 * Get tipo de veiculo numa string
	 */
	virtual string getTipoNumaString() const = 0;
	/**
	 * Get tipo de carta de conducao
	 */
	virtual TipoCartaConducao getTipo() const = 0;
	/**
	 * Set data da ultima inspecao de um veiculo
	 */
	void setDataUltimaInspecao(string data);
	/**
	 * Get data da ultima inspecao de um veiculo
	 */
	struct tm *getDataUltimaInspecao() { return &dataUltimaInspecao; }
	/**
	 * Get string com data da ultima inspecao
	 */
	string getStringComDataUltimaInspecao() const;
	/**
	 * Get periodicidade
	 */
	int getPeriodicidade() { return periodicidade; }
	/**
	 * Set periodicidade
	 */
	void setPeriodicidade(int Periodicidade) { periodicidade = Periodicidade; }
	/**
	 * Get data da proxima inspecao
	 */
	struct tm getDataProximaInspecao();
};

#endif

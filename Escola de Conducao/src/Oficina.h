/*!
 * \file Oficina.h
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
#ifndef OFICINA_H_
#define OFICINA_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Utilities.h"
using namespace std;

class Oficina {
private:
	string denominacao;
	string localizacao;

	int disponibilidade;
	vector<string> marcasEspecializadas;
public:
	Oficina(string Denominacao, string Localizacao, int Disponibilidade = 10) :
			denominacao(Denominacao), localizacao(Localizacao) {
		disponibilidade = Disponibilidade;
	}
	virtual ~Oficina() {
	}

	string getDenominacao() {
		return denominacao;
	}

	string getLocalizacao() {
		return localizacao;
	}

	int getDisponibilidade() {
		return disponibilidade;
	}

	string getMarcasEspecializadas() {
		if (marcasEspecializadas.empty())
			return "Nenhuma marca disponivel.";

		stringstream ss;

		FOR(i, 0, marcasEspecializadas.size())
			ss << marcasEspecializadas[i] << " ";

		return ss.str();
	}

	int addMarca(string Marca);
	int removeMarca(string Marca);
	void setDisponibilidade(int Disponibilidade) {
		disponibilidade = Disponibilidade;
	}

	bool operator <(const Oficina& o1) const {
		return disponibilidade < o1.disponibilidade;
	}
};

#endif

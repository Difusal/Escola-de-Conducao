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

enum TipoDeServico {
	SERVICO_USUAL, SERVICO_ESPECIFICO
};

class Oficina {
private:
	string denominacao;
	string localizacao;

	int disponibilidade;
	vector<string> marcasEspecializadas;
public:
	/**
	 * Copy Constructor
	 */
	Oficina(string Denominacao, string Localizacao, int Disponibilidade = 10) :
			denominacao(Denominacao), localizacao(Localizacao) {
		disponibilidade = Disponibilidade;
	}
	/**
	 * Destructor
	 */
	virtual ~Oficina() {
	}

	/**
	 * Get denominacao da oficina
	 */
	string getDenominacao() {
		return denominacao;
	}

	/**
	 * Get localizacao da oficina
	 */
	string getLocalizacao() {
		return localizacao;
	}

	/**
	 * Get disponibilidade da oficina
	 */
	int getDisponibilidade() {
		return disponibilidade;
	}

	/**
	 * Get marcas de especializacao da oficina
	 */
	vector<string> getMarcasEspecializadas() {
		return marcasEspecializadas;
	}

	/**
	 * Get marcas especializadas
	 */
	string getMarcasEspecializadasStr() {
		if (marcasEspecializadas.empty())
			return "Nenhuma marca disponivel.";

		stringstream ss;

		FOR(i, 0, marcasEspecializadas.size())
			ss << marcasEspecializadas[i] << " ";

		return ss.str();
	}

	/**
	 * Adiciona servico
	 */
	void adicionaServico() { disponibilidade--; }
	/**
	 * Termona servico
	 */
	void terminaServico() { disponibilidade++; }

	/**
	 * Adiciona marca
	 */
	int addMarca(string Marca);
	/**
	 * Remove marca
	 */
	int removeMarca(string Marca);
	/**
	 * Set disponibilidade
	 */
	void setDisponibilidade(int Disponibilidade) {
		disponibilidade = Disponibilidade;
	}


	bool operator <(const Oficina& o1) const {
		return disponibilidade < o1.disponibilidade;
	}

	friend ostream& operator <<(ostream& os, Oficina& o1) {
		os << "Oficina " << o1.getDenominacao() << endl;
		os << "   Localizacao: " << o1.getLocalizacao() << endl;
		os << "   Disponibilidade: " << o1.getDisponibilidade() << endl;
		os << "   Marcas especializadas: " << o1.getMarcasEspecializadasStr()
				<< endl;
		os << endl;

		return os;
	}
};

#endif

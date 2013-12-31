/*!
 * \file Instrutor.cpp
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
#include "Instrutor.h"
#include <sstream>

int Instrutor::info() {
	int num = Pessoa::info();
	cout << "    Numero qualificacoes: " << numQualificacoes() << endl;
	if (numQualificacoes() != 0)
		cout << "\t";
	if (qualificacoes[0])
		cout << "\tLigeiro";
	if (qualificacoes[1])
		cout << "\tPesado";
	if (qualificacoes[2])
		cout << "\tMotociclo";
	if (numQualificacoes() != 0)
		cout << endl;
	return num + 1;
}

string Instrutor::printToFile() const {
	stringstream ss;
	ss << nome << " " << qualificacoes[0] << " " << qualificacoes[1] << " " << qualificacoes[2];
	return ss.str();
}

void Instrutor::setQualificacoes(bool Lig, bool Pes, bool Moto) {
	qualificacoes[0] = Lig;
	qualificacoes[1] = Pes;
	qualificacoes[2] = Moto;
}

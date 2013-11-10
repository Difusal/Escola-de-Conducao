/*
 * Instrutor.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: henrique
 */

#include "Instrutor.h"
#include <sstream>

Instrutor::~Instrutor() {
	// TODO Auto-generated destructor stub
}

int Instrutor::info() {
	int num = Pessoa::info();
	cout << "\tNumero qualificacoes: " << numQualificacoes() << endl;
	if (numQualificacoes() != 0)
		cout << "\t";
	if (qualificacoes[0])
		cout << "\tLigeiro";
	if (qualificacoes[1])
		cout << "\tPesado";
	if (qualificacoes[3])
		cout << "\tMotociclo";
	if (numQualificacoes() != 0)
		cout << endl;
	cout << "\tNumero de alunos: " << numAlunos() << endl;
	cout << "\tNumero de aulas: " << numAulas() << endl;
	return num + 3;
}

string Instrutor::printToFile() const {
	stringstream ss;
	ss << nome << " " << qualificacoes[0] << " " << qualificacoes[1] << " " << qualificacoes[2];
	return ss.str();
}

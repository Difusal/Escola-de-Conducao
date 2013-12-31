/*!
 * \file Aluno.cpp
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
 #include "Aluno.h"

int Aluno::info() {
	int num = Pessoa::info();
	cout << "    Viatura usual:" << endl;
	getViaturaUsual()->info();
	return num + 1;
}

string Aluno::printToFile() const {
	stringstream ss;
	ss << nome << " " << tipoDeCarta << " " << viaturaUsual->getMatricula() << " " << nomeInstrutor;
	return ss.str();
}

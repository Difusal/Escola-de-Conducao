/*!
 * \file AlunoAntigo.cpp
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
 #include "AlunoAntigo.h"

int AlunoAntigo::info() {
	int num = Pessoa::info();
	cout<<"    Instructor: "<<nomeInstrutor<<endl;
	cout<<"    Contacto: "<<contacto<<endl;
	return num + 1;
}

string AlunoAntigo::printToFile() const {
	stringstream ss;
	ss << nome << " " << tipoDeCarta << " " << nomeInstrutor << " "<< contacto;
	return ss.str();
}

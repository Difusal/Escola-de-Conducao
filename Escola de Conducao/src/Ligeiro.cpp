/*!
 * \file Ligeiro.cpp
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
#include "Ligeiro.h"

int Ligeiro::info() {
	int prevInfo = Automovel::info();
	//cout << "Carga Maxima: " << cargaMaxima << endl;
	return prevInfo + 0;
}

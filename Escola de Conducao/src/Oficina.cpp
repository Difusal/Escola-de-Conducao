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
#include "Oficina.h"

#include <iostream>
#include "Utilities.h"
using namespace std;

int Oficina::addMarca(string Marca) {
	bool existe = 0;
	FOR(i, 0, marcasEspecializadas.size())
	{
		if (marcasEspecializadas[i] == Marca) {
			existe = 1;
			break;
		}
	}
	if (!existe)
		marcasEspecializadas.PB(Marca);

	return existe;
}

int Oficina::removeMarca(string Marca) {
	bool existe = 0;
	FOR(i, 0, marcasEspecializadas.size())
	{
		if (marcasEspecializadas[i] == Marca) {
			existe = 1;
			marcasEspecializadas.erase(marcasEspecializadas.begin() + i);
			break;
		}
	}

	return existe;
}

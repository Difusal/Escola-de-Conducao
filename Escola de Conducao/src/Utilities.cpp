/*
 * Utilities.cpp
 *
 *  Created on: Nov 6, 2013
 *      Author: henrique
 */
#include <sstream>
#include <fstream>
#include "Utilities.h"
#include "Exceptions.h"
using namespace std;

bool fileExists(const string &fileName) {
	ifstream infile(fileName.c_str());
	return infile.good();
}

int parseFilename(string &fileName) {
	stringstream ss;

	ss.str(string());
	ss << "data//" << fileName << ".in";
	fileName = ss.str();

	return 0;
}


int processMatricula(string Matricula) {
	if (Matricula.size() != 8)
		throw(MatriculaInvalida(Matricula));

	FOR(i, 0, Matricula.size()) {
		if ((i == 2 || i == 5) && Matricula[i] != '-')
			throw(MatriculaInvalida(Matricula));

		Matricula[i] = toupper(Matricula[i]);
	}

	return 0;
}


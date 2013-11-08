/*
 * Exceptions.h
 *
 *  Created on: Nov 6, 2013
 *      Author: henrique
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <iostream>
#include "Utilities.h"
#include <exception>
using namespace std;

class MatriculaInvalida: public exception {
	string *m;
public:
	MatriculaInvalida(string &matricula): m(&matricula) {}
	virtual ~MatriculaInvalida() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << "Erro:\tMatricula Invalida." << endl;
		cout << "\tFormato esperado: \"xx-xx-xx\"." << endl;
		cout << "\tUma matricula tem que conter 2 letras e" << endl;
		cout << "\t4 numeros separados por um \'-\'" << endl;
		cout << "\t---------------------------------------" << endl;

		return "";
	}
};

class HoraInvalida: public exception {
	int *hora;
public:
	HoraInvalida(int &Hora): hora(&Hora) {}
	virtual ~HoraInvalida() throw() {}

	virtual const char *what () const throw() {
		cout << endl;
		cout << "Erro:\tHora Invalida." << endl;
		cout << "\tA hora tem que pertencer ao intervalo: [0, 23]" << endl;
		cout << "\t----------------------------------------------" << endl;

		return "";
	}
};

#endif /* EXCEPTIONS_H_ */

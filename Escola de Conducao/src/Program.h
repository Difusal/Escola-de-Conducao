/*!
 * \file Program.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Dezembro 2013
 *
 */
#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "Escola.h"
#include "BST.h"
using namespace std;

class Program {
private:
	BST<Escola> escolas;
	Escola* escola;
public:
	Program() :
			escolas(Escola("", "", -1)) {
		escola = new Escola("", "", 0);
	}

	virtual ~Program() {
	}

	int loadSchoolsFile();
	void removeSchoolFromMainFile(string Designacao);

	void showLoginScreen();

	void showLoginUI();
	void showSignUpUI();
	void showEditSchoolUI();
	void showRemoveSchoolUI();
	void showViewSchoolUI();
};

#endif

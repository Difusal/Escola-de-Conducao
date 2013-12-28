/*!
 * \file Program.h
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
#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "BST.h"
#include <queue>
using namespace std;

#include "Escola.h"
#include "Oficina.h"

typedef priority_queue<Oficina> HEAP_OFICINAS;

class Program {
private:
	BST<Escola> escolas;
	HEAP_OFICINAS oficinas;

	Escola* escola;
public:
	Program() :
			escolas(Escola("", "", -1)) {
		escola = new Escola("", "", 0);
	}

	virtual ~Program() {
	}

	int loadSchoolsFile();
	void renameSchoolFromMainFile(string Nome, string NomeNovo);
	void changeSchoolNumMaxStudentsFromMainFileUI();
	void removeSchoolFromMainFile(string Designacao);

	void showLoginScreen();

	void showLoginUI();
	void showSignUpUI();
	void showEditSchoolUI();
	void showRenameSchoolUI();
	void showRemoveSchoolUI();
	void showViewSchoolUI();

	// Metodos das Oficinas
	void showAddWorkshopUI();
	void viewWorkshopsList();
	void showEditWorkshopUI();
	void showRemoveWorkshopUI();

	void addOficina(string Nome, string Local);
	void removeOficina(string Nome);

	void addMarcaToOficina(string Nome, string marca);
	void removeMarcaFromOficina(string Nome, string marca);
	void alteraDisponibilidadeDeOficina(string Nome, int disponibilidade);

	Oficina* getOficinaDisponivel();
};

#endif

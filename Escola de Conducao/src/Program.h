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
	/**
	 * Copy Constructor
	 */
	Program() :
			escolas(Escola("", "", -1)) {
		escola = new Escola("", "", 0);
	}
	/**
	 * Destructor
	 */
	virtual ~Program() {
	}

	/**
	 * Load ficheiros da escola de conducao
	 */
	int loadSchoolsFile();
	/**
	 * Renomear escola
	 */
	void renameSchoolFromMainFile(string Nome, string NomeNovo);
	/**
	 * Mudar numero maximo de alunos de uma escola (user interface)
	 */
	void changeSchoolNumMaxStudentsFromMainFileUI();
	/**
	 * Remover escola
	 */
	void removeSchoolFromMainFile(string Designacao);

	/**
	 * Show ecra de login
	 */
	void showLoginScreen();

	/**
	 * Show login (user interface)
	 */
	void showLoginUI();
	/**
	 * Show sign up (user interface)
	 */
	void showSignUpUI();
	/**
	 * Show editar escola (user interface)
	 */
	void showEditSchoolUI();
	/**
	 * Show renomear escola (user interface)
	 */
	void showRenameSchoolUI();
	/**
	 * Show remover escola (user interface)
	 */
	void showRemoveSchoolUI();
	/**
	 * Show ver escola (user interface)
	 */
	void showViewSchoolUI();

	// Metodos das Oficinas
	/**
	 * Load oficinas
	 */
	void loadOficinas();
	/**
	 * Save oficinas
	 */
	void saveOficinas();

	/**
	 * Show adicionar oficina (user interface)
	 */
	void showAddWorkshopUI();
	/**
	 * Ver lista de oficinas
	 */
	void viewWorkshopsList();
	/**
	 * Show editar oficina (user interface)
	 */
	void showEditWorkshopUI();
	/**
	 * Show remover oficina (user interface)
	 */
	void showRemoveWorkshopUI();

	/**
	 * Adiciona oficina
	 */
	void addOficina(string Nome, string Local, bool feedback = 1);
	/**
	 * Remove oficina
	 */
	void removeOficina(string Nome);

	/**
	 * Adicina marca a oficina
	 */
	void addMarcaToOficina(string Nome, string marca, bool feedback = 1);
	/**
	 * Remove marca de oficina
	 */
	void removeMarcaFromOficina(string Nome, string marca);
	/**
	 * Altera disponibilidade de oficina
	 */
	void alteraDisponibilidadeDeOficina(string Nome, int disponibilidade,
			bool feedback = 1);
	/**
	 * Incrementa disponibilidade de oficina
	 */
	void incDisponibilidadeDeOficina(string Nome);

	/**
	 * Get oficina disponivel
	 */
	Oficina getOficinaDisponivel(TipoDeServico servico, string marca = "");
};

#endif

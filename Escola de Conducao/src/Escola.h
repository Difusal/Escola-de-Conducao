/*!
 * \file Escola.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
#ifndef ESCOLA_H_
#define ESCOLA_H_

#include "Viatura.h"
#include "Automovel.h"
#include "Ligeiro.h"
#include "Pesado.h"
#include "Motociclo.h"
#include "Instrutor.h"
#include "Aluno.h"
#include "Aula.h"
#include <map>
#include <tr1/unordered_set>

enum MetodoDeSortDeViaturas {
	MATRICULA, ANOFABRICO, MARCA, TIPO, DATAULTIMAINSPECAO, PROXIMAINSPECAO
};
enum MetodoDeSortDeInstrutores {
	NOMEINSTRUTOR, NQUALIFICACOES
};
enum MetodoDeSortDeAlunos {
	NOMEALUNO, NAULASMARCADAS
};
enum MetodoDeSortDeAulas {
	DATA, ALUNO, INSTRUTOR, TIPOVIATURA
};

struct eqaluno {
	bool operator()(const Aluno* a1, const Aluno* a2) const {
		return a1->getNome() == a2->getNome();
	}
};

struct haluno {
	int operator()(const Aluno* a1) const {
		int v = 0;
		for (unsigned int i = 0; i < a1->getNome().size(); i++)
			v = 37 * v + a1->getNome()[i];
		return v;
	}
};

typedef tr1::unordered_set<Aluno*, haluno, eqaluno> HashAlunos;

class Escola {
private:
	string designacao;
	string localizacao;
	int nMaxAlunos;
	int abertura, fecho;

	vector<Viatura*> viaturas;
	map<Instrutor*, vector<Aluno*> > comunidade;
	vector<Aula*> aulas;
	HashAlunos alunosInactivos;
public:
	Escola(string Nome, string Localizacao, int NumMaxAlunos) :
			designacao(Nome), localizacao(Localizacao), nMaxAlunos(NumMaxAlunos) {
		abertura = fecho = 0;
	}
	virtual ~Escola() {
	}

	int createFileStructure();
	int saveSchoolData();
	int loadSchoolData();
	void saveSchoolToMainFile();

	string getDesignacao() {
		return designacao;
	}
	string getLocalizacao() {
		return localizacao;
	}
	int getNumMaxALunos() {
		return nMaxAlunos;
	}

	int setDesignacao(string nome);
	int setHorarioUI();
	int setLocalizacaoUI();
	int setNumMaxAlunosUI();

	int showMainMenu();
	void showManutencaoViaturasUI();
	void showManutencaoInstrutoresUI();
	void showManutencaoAlunosUI();
	void showManutencaoAulasUI();

	void showVisualizaViaturasUI();
	void showAdicionarViaturaUI();
	void showEditarViaturaUI();
	void showRemoverViaturaUI();

	void visualizaViaturas(MetodoDeSortDeViaturas metodo);
	void adicionaViatura(Viatura *viatura) {
		viaturas.push_back(viatura);
	}

	void showVisualizaInstrutoresUI();
	void showAdicionarInstrutorUI();
	void showEditarInstrutorUI();
	void showRemoverInstrutorUI();

	void visualizaInstrutores(MetodoDeSortDeInstrutores metodo);
	void adicionaInstrutor(Instrutor *instrutor) {
		comunidade[instrutor];
	}

	void showVisualizaAlunosUI();
	void showAdicionarAlunoUI();
	void showEditarAlunoUI();
	void showRemoverAlunoUI();
	void adicionaAluno(Aluno *aluno, Instrutor *instrutor) {
		comunidade[instrutor].push_back(aluno);
	}
	void visualizaAlunos(MetodoDeSortDeAlunos metodo);
	void visualizaAlunosInactivos();
	void setInactivo(Aluno *aluno);
	void removeInactivo(Aluno *aluno);

	void showVisualizaAulasUI();
	void showMarcarAulaUI();
	void showEditarAulaUI();
	void showDesmarcarAulaUI();

	void visualizaAulas(MetodoDeSortDeAulas metodo);
	void marcaAula(Aula *aula) {
		aulas.push_back(aula);
	}

	unsigned int numViaturas() const {
		return viaturas.size();
	}
	unsigned int numInstrutores() const {
		return comunidade.size();
	}
	unsigned int numAlunos() const;
	unsigned int numAulas() const {
		return aulas.size();
	}
	unsigned int numAulasDoInstrutor(Instrutor *instrutor);
	int numAlunosQueUsamAViatura(Viatura *viatura);
	int numAlunosQueTemAulasComInstrutor(Instrutor *instrutor);

	Viatura *getViaturaComMatricula(string Matricula);
	Viatura *getViaturaComMenosAlunos(TipoCartaConducao TipoViatura);

	const vector<Aluno*> getTodosAlunos();
	Aluno *getAlunoChamado(string nome);

	Instrutor *getInstrutorChamado(string nome);
	Instrutor *getInstrutorDoAluno(Aluno *aluno);
	Instrutor *getInstrutorComMenosAlunos(TipoCartaConducao TipoViatura);

	void waitForValidAluno(string &nomeAluno);

	bool operator <(const Escola &escola) const {
		return nMaxAlunos < escola.nMaxAlunos;
	}

	friend class Program;
};

#endif

/*!
 * \file Escola.h
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
#ifndef ESCOLA_H_
#define ESCOLA_H_

#include "Viatura.h"
#include "Automovel.h"
#include "Ligeiro.h"
#include "Pesado.h"
#include "Motociclo.h"
#include "Instrutor.h"
#include "Aluno.h"
#include "AlunoAntigo.h"
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
	NOMEALUNO, NAULASMARCADAS, INACTIVOS
};
enum MetodoDeSortDeAulas {
	DATA, ALUNO, INSTRUTOR, TIPOVIATURA
};

struct eqAlunoAntigo {
	bool operator()(const AlunoAntigo* a1, const AlunoAntigo* a2) const {
		return a1->getNome() == a2->getNome();
	}
};

struct hAlunoAntigo {
	int operator()(const AlunoAntigo* a1) const {
		int v = 0;
		for (unsigned int i = 0; i < a1->getNome().size(); i++)
			v = 37 * v + a1->getNome()[i];
		return v;
	}
};

typedef tr1::unordered_set<AlunoAntigo*, hAlunoAntigo, eqAlunoAntigo> HashAlunoAntigo;

class Escola {
private:
	string designacao;
	string localizacao;
	int nMaxAlunos;
	int abertura, fecho;

	vector<Viatura*> viaturas;
	map<Instrutor*, vector<Aluno*> > comunidade;
	vector<Aula*> aulas;
	HashAlunoAntigo alunosAntigos;
public:
	/**
	 * Copy Constructor
	 */
	Escola(string Nome, string Localizacao, int NumMaxAlunos) :
			designacao(Nome), localizacao(Localizacao), nMaxAlunos(NumMaxAlunos) {
		abertura = fecho = 0;
	}
	/**
	 * Destructor
	 */
	virtual ~Escola() {
	}

	/**
	 * Create file structure
	 */
	int createFileStructure();
	/**
	 * Save school data
	 */
	int saveSchoolData();
	/**
	 * Load school data
	 */
	int loadSchoolData();
	/**
	 * Save school to main file
	 */
	void saveSchoolToMainFile();

	/**
	 * Get designacao
	 */
	string getDesignacao() {
		return designacao;
	}
	/**
	 * Get localizacao
	 */
	string getLocalizacao() {
		return localizacao;
	}
	/**
	 * Get numero maximo de alunos
	 */
	int getNumMaxALunos() {
		return nMaxAlunos;
	}

	/**
	 * Set designacao
	 */
	int setDesignacao(string nome);
	/**
	 * Set horario (user interface)
	 */
	int setHorarioUI();
	/**
	 * Set localizacao (user interface)
	 */
	int setLocalizacaoUI();
	/**
	 * Set numero maximo de aluno da escola (user interface)
	 */
	int setNumMaxAlunosUI();

	/**
	 * Show Main Menu
	 */
	int showMainMenu();
	/**
	 * Show Manutencao Viaturas (user interface)
	 */
	void showManutencaoViaturasUI();
	/**
	 * Show manutencao instrutores (user interface)
	 */
	void showManutencaoInstrutoresUI();
	/**
	 * Show manutencao de alunos (user interface)
	 */
	void showManutencaoAlunosUI();
	/**
	 * Show manutencao de alunos antigos (user interface)
	 */
	void showManutencaoAlunosAntigosUI();
	/**
	 * Show manutencao de aulas (user interface)
	 */
	void showManutencaoAulasUI();

	/**
	 * Show visualiza viaturas (user interface)
	 */
	void showVisualizaViaturasUI();
	/**
	 * Show adicionar viatura (user interface)
	 */
	void showAdicionarViaturaUI();
	/**
	 * Show editar viatura (user interface)
	 */
	void showEditarViaturaUI();
	/**
	 * Show remover viatura (user interface)
	 */
	void showRemoverViaturaUI();

	/**
	 * Visualiza viaturas
	 */
	void visualizaViaturas(MetodoDeSortDeViaturas metodo);
	/**
	 * Adiciona viaturas
	 */
	void adicionaViatura(Viatura *viatura) {
		viaturas.push_back(viatura);
	}

	/**
	 * Show visualiza instrutores (user interface)
	 */
	void showVisualizaInstrutoresUI();
	/**
	 * Show adicionar instrutor (user interface)
	 */
	void showAdicionarInstrutorUI();
	/**
	 * Show editar instrutor (user interface)
	 */
	void showEditarInstrutorUI();
	/**
	 * Show remover instrutor (user interface)
	 */
	void showRemoverInstrutorUI();

	/**
	 * Visualiza instrutores
	 */
	void visualizaInstrutores(MetodoDeSortDeInstrutores metodo);
	/**
	 * Adiciona instrutor
	 */
	void adicionaInstrutor(Instrutor *instrutor) {
		comunidade[instrutor];
	}

	/**
	 * Show visualiza alunos (user interface)
	 */
	void showVisualizaAlunosUI();
	/**
	 * Show adicionar aluno (user interface)
	 */
	void showAdicionarAlunoUI();
	/**
	 * Show editar aluno (user interface)
	 */
	void showEditarAlunoUI();
	/**
	 * Show editar aluno antigo (user interface)
	 */
	void showEditarAlunoAntigoUI();
	/**
	 * Show remover aluno (user interface)
	 */
	void showRemoverAlunoUI();
	/**
	 * Show remover aluno antigo (user interface)
	 */
	void showRemoverAlunoAntigoUI();
	/**
	 * Adiciona aluno
	 */
	void adicionaAluno(Aluno *aluno, Instrutor *instrutor) {
		comunidade[instrutor].push_back(aluno);
	}
	/**
	 * Visualiza alunos
	 */
	void visualizaAlunos(MetodoDeSortDeAlunos metodo);
	/**
	 * Visualiza alunos antigos
	 */
	void visualizaAlunosAntigos();
	/**
	 * Adiciona aluno antigo
	 */
	void adicionaAlunoAntigo(AlunoAntigo *aluno);
	/**
	 * Remove aluno antigo
	 */
	void removeAlunoAntigo(AlunoAntigo *aluno);

	/**
	 * Show visualiza aulas (user interface)
	 */
	void showVisualizaAulasUI();
	/**
	 * Show marcar aulas (user interface)
	 */
	void showMarcarAulaUI();
	/**
	 * Show editar aulas (user interface)
	 */
	void showEditarAulaUI();
	/**
	 * Show desmarcar aula (user interface)
	 */
	void showDesmarcarAulaUI();

	/**
	 * Visualiza aulas
	 */
	void visualizaAulas(MetodoDeSortDeAulas metodo);
	/**
	 * Marca aula
	 */
	void marcaAula(Aula *aula) {
		aulas.push_back(aula);
	}

	/**
	 * Numero de viaturas
	 */
	unsigned int numViaturas() const {
		return viaturas.size();
	}
	/**
	 * Numero de instrutores
	 */
	unsigned int numInstrutores() const {
		return comunidade.size();
	}
	/**
	 * Numero de alunos
	 */
	unsigned int numAlunos() const;
	/**
	 * Numero de aulas
	 */
	unsigned int numAulas() const {
		return aulas.size();
	}
	/**
	 * Numero de aulas do instrutor
	 */
	unsigned int numAulasDoInstrutor(Instrutor *instrutor);
	/**
	 * Numero de alunos que usam a viatura
	 */
	int numAlunosQueUsamAViatura(Viatura *viatura);
	/**
	 * Numero de alunos que tem aula com o instrutor
	 */
	int numAlunosQueTemAulasComInstrutor(Instrutor *instrutor);

	/**
	 * Get Viatura com matricula
	 */
	Viatura *getViaturaComMatricula(string Matricula);
	/**
	 * Get viatura com menos alunos
	 */
	Viatura *getViaturaComMenosAlunos(TipoCartaConducao TipoViatura);

	/**
	 * Get todos os alunos
	 */
	const vector<Aluno*> getTodosAlunos();
	/**
	 * Get aluno chamado
	 */
	Aluno *getAlunoChamado(string nome);
	/**
	 * Get aluno antigo chamado
	 */
	AlunoAntigo *getAlunoAntigoChamado(string nome);
	/**
	 * Get inactivo
	 */
	bool getInactivo(Aluno *aluno);

	/**
	 * Get instrutor chamado
	 */
	Instrutor *getInstrutorChamado(string nome);
	/**
	 * Get instrutor do aluno
	 */
	Instrutor *getInstrutorDoAluno(Aluno *aluno);
	/**
	 * Get instrutor com menos alunos
	 */
	Instrutor *getInstrutorComMenosAlunos(TipoCartaConducao TipoViatura);

	/**
	 * Espera por aluno valido
	 */
	void waitForValidAluno(string &nomeAluno);

	bool operator <(const Escola &escola) const {
		return nMaxAlunos < escola.nMaxAlunos;
	}

	friend class Program;
};

#endif

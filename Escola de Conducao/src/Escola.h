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

enum MetodoDeSortDeViaturas { MATRICULA, ANOFABRICO, MARCA, TIPO, DATAULTIMAINSPECAO, PERIODICIDADE };
enum MetodoDeSortDeInstrutores { NOMEINSTRUTOR, NQUALIFICACOES, NALUNOS, NAULAS };
enum MetodoDeSortDeAlunos { NOMEALUNO, NAULASMARCADAS };
enum MetodoDeSortDeAulas { DATA, ALUNO, INSTRUTOR, TIPOVIATURA };

class Escola {
private:
	string nome;
	int abertura, fecho;
	vector<Viatura*> viaturas;
	vector<Instrutor*> instrutores;
	vector<Aluno*> alunos;
	vector<Aula*> aulas;
	map<Instrutor*, vector<Aluno*> > instrutores2;
public:
	Escola();
	virtual ~Escola();

	int createFileStructure();
	int saveSchoolData();
	int loadSchoolData();

	void showLoginScreen();
	void showLoginUI();
	void showSignUpUI();
	int setHorarioUI();
	void showRenameSchoolUI();
	void showRemoveSchoolUI();

	void showMainMenu();
	void showManutencaoViaturasUI();
	void showManutencaoInstrutoresUI();
	void showManutencaoAlunosUI();
	void showManutencaoAulasUI();

	void showVisualizaViaturasUI();
	void showAdicionarViaturaUI();
	void showEditarViaturaUI();
	void showRemoverViaturaUI();

	void visualizaViaturas(MetodoDeSortDeViaturas metodo);
	void adicionaViatura(Viatura *viatura) { viaturas.push_back(viatura); }

	void showVisualizaInstrutoresUI();
	void showAdicionarInstrutorUI();
	void showEditarInstrutorUI();
	void showRemoverInstrutorUI();

	void visualizaInstrutores(MetodoDeSortDeInstrutores metodo);
	void adicionaInstrutor(Instrutor *instrutor) { instrutores.push_back(instrutor); }

	void showVisualizaAlunosUI();
	void showAdicionarAlunoUI();
	void showEditarAlunoUI();
	void showRemoverAlunoUI();

	void visualizaAlunos(MetodoDeSortDeAlunos metodo);
	void adicionaAluno(Aluno *aluno) { alunos.push_back(aluno); }

	void showVisualizaAulasUI();
	void showMarcarAulaUI();
	void showEditarAulaUI();
	void showDesmarcarAulaUI();

	void visualizaAulas(MetodoDeSortDeAulas metodo);
	void marcaAula(Aula *aula) { aulas.push_back(aula); }

	unsigned int numViaturas() const { return viaturas.size(); }
	unsigned int numInstrutores() const { return instrutores.size(); }
	unsigned int numAlunos() const { return alunos.size(); }
	unsigned int numAulas() const { return aulas.size(); }

	Viatura *getViaturaComMatricula(string Matricula);
	Aluno *getAlunoChamado(string nome);
	Instrutor *getInstrutorDoAluno(Aluno *aluno);

	int numAlunosQueUsamAViatura(Viatura *viatura);
	int numAlunosQueTemAulasComInstrutor(Instrutor *instrutor);

	Viatura *getViaturaComMenosAlunos(TipoCartaConducao TipoViatura);
	Instrutor *getInstrutorComMenosAlunos(TipoCartaConducao TipoViatura);
};

#endif

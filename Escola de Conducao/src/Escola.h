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

enum MetodoDeSortDeViaturas { MATRICULA, ANOFABRICO, MARCA, TIPO, DATAULTIMAINSPECAO, PERIODICIDADE };
enum MetodoDeSortDeInstrutores { NOME, NQUALIFICACOES, NALUNOS, NAULAS };

class Escola {
private:
	string nome;
	int abertura, fecho;
	vector<Viatura*> viaturas;
	vector<Instrutor*> instrutores;
	vector<Aluno*> alunos;
	vector<Aula*> aulas;
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

	unsigned int numViaturas() const { return viaturas.size(); }
	unsigned int numInstrutores() const { return instrutores.size(); }
	unsigned int numAlunos() const { return alunos.size(); }
	unsigned int numAulas() const { return aulas.size(); }
};

#endif

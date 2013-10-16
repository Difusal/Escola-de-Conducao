#ifndef ESCOLA_H_
#define ESCOLA_H_
#include "Viatura.h"
#include "Automovel.h"
#include "Ligeiro.h"
#include "Pesado.h"
#include "Motociclo.h"

class Escola {
private:
	vector<Viatura*> viaturas;
public:
	Escola();
	virtual ~Escola();

	void showMainMenu();
	void showManutencaoViaturas();
	void showAdicionarViaturaUI();
	void showManutencaoInstrutores();
	void showManutencaoAlunos();
	void showManutencaoAulas();

	int numViaturas() const { return viaturas.size(); }
	void adicionaViatura(Viatura *viatura) { viaturas.push_back(viatura); }
	/*
	int menorAno() const;
	void info() const;
	*/
};

#endif

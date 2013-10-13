#ifndef ESCOLA_H_
#define ESCOLA_H_
#include "Viatura.h"

class Escola {
private:
	vector<Viatura*> viaturas;
public:
	Escola();
	virtual ~Escola();

	int numViaturas() const { return viaturas.size(); }
	//void adicionaVeiculo(Veiculo *v1);
	/*
	int menorAno() const;
	void info() const;
	*/
};

#endif

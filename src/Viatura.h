#ifndef VIATURA_H_
#define VIATURA_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Viatura {
protected:
	string matricula;
	int anoFabrico;
	string marca;
public:
	Viatura(string Matricula, int Ano, string Marca) : matricula(Matricula), anoFabrico(Ano), marca(Marca) {}
	virtual ~Viatura() {}

	virtual int info() const;

	// Getters e Setters
	string getMatricula() { return matricula; }
	int getAnoFabrico() { return anoFabrico; }
	string getMarca() const { return marca; }
};

#endif

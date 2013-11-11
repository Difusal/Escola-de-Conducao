#ifndef VIATURA_H_
#define VIATURA_H_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include "Utilities.h"
using namespace std;

enum TipoCartaConducao { LIGEIRO, PESADO, MOTOCICLO };

class Viatura {
protected:
	string matricula;
	int anoFabrico;
	string marca;
	struct tm dataUltimaInspecao;
	int periodicidade;
public:
	Viatura(string Matricula, int Ano, string Marca, int Periodicidade) : matricula(Matricula), anoFabrico(Ano), marca(Marca), dataUltimaInspecao(*getLocalTimeInfo()), periodicidade(Periodicidade) {}
	virtual ~Viatura() {}

	virtual int info();
	virtual string printToFile() const;

	// Getters e Setters
	string getMatricula() { return matricula; }
	int getAnoFabrico() { return anoFabrico; }
	string getMarca() const { return marca; }
	virtual string getTipoNumaString() const = 0;
	virtual TipoCartaConducao getTipo() const = 0;
	void setDataUltimaInspecao(string data);
	struct tm *getDataUltimaInspecao() { return &dataUltimaInspecao; }
	string getStringComDataUltimaInspecao() const;
	int getPeriodicidade() { return periodicidade; }
	void setPeriodicidade(int Periodicidade) { periodicidade = Periodicidade; }
	struct tm getDataProximaInspecao();
};

#endif

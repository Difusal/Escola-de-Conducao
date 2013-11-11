#include "Aluno.h"

Aluno::~Aluno() {
	// TODO Auto-generated destructor stub
}

int Aluno::info() {
	int num = Pessoa::info();
	cout << "    Viatura usual:" << endl;
	getViaturaUsual()->info();
	return num + 1;
}

string Aluno::printToFile() const {
	stringstream ss;
	ss << nome << " " << tipoDeCarta << " " << viaturaUsual->getMatricula() << " " << nomeInstrutor;
	return ss.str();
}

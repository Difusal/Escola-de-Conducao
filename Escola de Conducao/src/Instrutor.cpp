#include "Instrutor.h"
#include <sstream>

Instrutor::~Instrutor() {
	// TODO Auto-generated destructor stub
}

int Instrutor::info() {
	int num = Pessoa::info();
	cout << "\tNumero qualificacoes: " << numQualificacoes() << endl;
	if (numQualificacoes() != 0)
		cout << "\t";
	if (qualificacoes[0])
		cout << "\tLigeiro";
	if (qualificacoes[1])
		cout << "\tPesado";
	if (qualificacoes[2])
		cout << "\tMotociclo";
	if (numQualificacoes() != 0)
		cout << endl;
	cout << "\tNumero de alunos: " << numAlunos() << endl;
	cout << "\tNumero de aulas: " << numAulas() << endl;
	return num + 3;
}

string Instrutor::printToFile() const {
	stringstream ss;
	ss << nome << " " << qualificacoes[0] << " " << qualificacoes[1] << " " << qualificacoes[2];
	return ss.str();
}

void Instrutor::setQualificacoes(bool Lig, bool Pes, bool Moto) {
	qualificacoes[0] = Lig;
	qualificacoes[1] = Pes;
	qualificacoes[2] = Moto;
}

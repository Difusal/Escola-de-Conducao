#include "Aluno.h"

Aluno::~Aluno() {
	// TODO Auto-generated destructor stub
}

int Aluno::info() {
	int num = Pessoa::info();
	cout << "\tTipo de carta: ";
	switch (tipoDeCarta) {
	case LIGEIRO:
		cout << "Ligeiro";
		break;
	case PESADO:
		cout << "Pesado";
		break;
	case MOTOCICLO:
		cout << "Motociclo";
		break;
	}
	cout << endl;
	return num + 1;
}

string Aluno::printToFile() const {
	stringstream ss;
	ss << nome << " " << tipoDeCarta;
	return ss.str();
}

#include "Aula.h"

using namespace std;

Aula::~Aula() {
	// TODO Auto-generated destructor stub
}

int Aula::info() {
	cout << "Data: " << convertTimeToString(data) << endl;
	cout << "Hora: " << hora << endl;
	cout << "Duracao: " << duracao << endl;
	cout << "Aluno: " << aluno->getNome() << endl;
	cout << "Instrutor: " << instrutor->getNome() << endl;
	cout << "Viatura: " << endl;
	aluno->getViaturaUsual()->info();

	return 6;
}

string Aula::printToFile() const {
	stringstream ss;
	ss << convertTimeToString(data) << " " << hora << " " << duracao << " "
			<< aluno->getNome() << " " << instrutor->getNome() << " "
			<< aluno->getViaturaUsual()->getMatricula();
	return ss.str();
}

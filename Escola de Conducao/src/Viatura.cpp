#include "Viatura.h"

int Viatura::info() {
	cout << "\tMatricula: " << matricula << endl;
	cout << "\tAno de fabrico: " << anoFabrico << endl;
	cout << "\tMarca: " << marca << endl;
	cout << "\tData ultima inspecao: " << getDataUltimaInspecao() << endl;
	cout << "\tPeriodicidade: " << periodicidade << endl;
	return 3;
}

string Viatura::printToFile() const {
	stringstream ss;
	ss << matricula << " " << anoFabrico << " " << marca << " " << getTipo() << " " << endl;
	return ss.str();
}

string Viatura::getDataUltimaInspecao() {
	stringstream ss;

	struct tm *localTime = getTimeInfo();
	ss << localTime->tm_mday << "/" << localTime->tm_mon << "/" << 1900 + localTime->tm_year;

	return ss.str();
}

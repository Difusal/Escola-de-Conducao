#include <cstdlib>
#include <string>
#include "Viatura.h"

int Viatura::info() {
	cout << "\tMatricula: " << matricula << endl;
	cout << "\tAno de fabrico: " << anoFabrico << endl;
	cout << "\tMarca: " << marca << endl;
	cout << "\tTipo: " << getTipoNumaString() << endl;
	cout << "\tData ultima inspecao: " << getStringComDataUltimaInspecao() << endl;
	cout << "\tPeriodicidade: " << getPeriodicidade() << endl;
	cout << "\tData proxima inspecao: " << convertTimeToString(getDataProximaInspecao()) << endl;
	return 6;
}

string Viatura::printToFile() const {
	stringstream ss;
	ss << matricula << " " << anoFabrico << " " << marca << " " << getTipoNumaString() << " " << getStringComDataUltimaInspecao() << " " << periodicidade;
	return ss.str();
}

void Viatura::setDataUltimaInspecao(string data) {
	struct tm ultimaInspec = *getLocalTimeInfo();

	int day = atoi(data.substr(0, 2).c_str());
	ultimaInspec.tm_mday = day;

	int month = atoi(data.substr(3, 2).c_str());
	ultimaInspec.tm_mon = month;

	int year = atoi(data.substr(6, 4).c_str());
	ultimaInspec.tm_year = year-1900;

	dataUltimaInspecao = ultimaInspec;
}

string Viatura::getStringComDataUltimaInspecao() const {
	stringstream ss;

	if (dataUltimaInspecao.tm_mday < 10)
		ss << 0;
	ss << dataUltimaInspecao.tm_mday << "/";

	if (dataUltimaInspecao.tm_mon+1 < 10)
		ss << 0;
	ss << dataUltimaInspecao.tm_mon+1 << "/";

	if (1900 + dataUltimaInspecao.tm_year < 10)
		ss << 0;
	if (1900 + dataUltimaInspecao.tm_year < 100)
		ss << 0;
	if (1900 + dataUltimaInspecao.tm_year < 1000)
		ss << 0;
	ss << 1900 + dataUltimaInspecao.tm_year;

	return ss.str();
}

struct tm Viatura::getDataProximaInspecao() {
	struct tm *ultima = getDataUltimaInspecao();
	time_t rawUltima = mktime(ultima);

	time_t rawPeriod = periodicidade*31*24*60*60;

	time_t rawProxima = rawUltima + rawPeriod;
	return (*gmtime(&rawProxima));
}

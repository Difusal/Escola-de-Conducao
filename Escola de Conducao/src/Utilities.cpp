#include <sstream>
#include <fstream>
#include <time.h>
#include "Utilities.h"
#include "Exceptions.h"
using namespace std;

struct tm *getLocalTimeInfo() {
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	return timeinfo;
}

int getAnoActual() {
	return (1900 + getLocalTimeInfo()->tm_year);
}

struct tm convertStringToDate(string data) {
	struct tm ultimaInspec = *getLocalTimeInfo();

	int day = atoi(data.substr(0, 2).c_str());
	ultimaInspec.tm_mday = day;

	int month = atoi(data.substr(3, 2).c_str());
	ultimaInspec.tm_mon = month;

	int year = atoi(data.substr(6, 4).c_str());
	ultimaInspec.tm_year = year - 1900;

	return ultimaInspec;
}

string convertTimeToString(struct tm Time) {
	stringstream ss;

	if (Time.tm_mday < 10)
		ss << 0;
	ss << Time.tm_mday << "/";

	if (Time.tm_mon < 10)
		ss << 0;
	ss << Time.tm_mon << "/";

	if (1900 + Time.tm_year < 10)
		ss << 0;
	if (1900 + Time.tm_year < 100)
		ss << 0;
	if (1900 + Time.tm_year < 1000)
		ss << 0;
	ss << 1900 + Time.tm_year;

	return ss.str();
}

bool fileExists(const string &fileName) {
	ifstream infile(fileName.c_str());
	return infile.good();
}

int parseFilename(string &fileName) {
	stringstream ss;

	ss.str(string());
	ss << "data//" << fileName << ".in";
	fileName = ss.str();

	return 0;
}


int processMatricula(string &Matricula) {
	if (Matricula.size() != 8)
		throw(MatriculaInvalida(Matricula));

	int nums = 0, chars = 0;
	FOR(i, 0, Matricula.size()) {
		if ((i == 2 || i == 5) && Matricula[i] != '-')
			throw(MatriculaInvalida(Matricula));

		Matricula[i] = toupper(Matricula[i]);
		if ('A' <= Matricula[i] && Matricula[i] <= 'Z')
			chars++;
		if ('0' <= Matricula[i] && Matricula[i] <= '9')
			nums++;

		if (nums > 4 || chars > 2)
			throw(MatriculaInvalida(Matricula));
	}

	return 0;
}

void waitForValidInt(int &num, int min, int max, string descricao) {
	while (1) {
		try {
			cout << "\t" << descricao << ": ";
			cin >> num;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(num, min, max));
			} else if (min <= num && num <= max)
				return;
			else
				throw(InputEsperadoEraInt(num, min, max));
		} catch (InputEsperadoEraInt &e) {
			e.what();
		}
	}
}

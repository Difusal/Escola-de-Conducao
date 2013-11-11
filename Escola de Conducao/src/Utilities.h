/*!
 * \file Utilities.h
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++ )

struct tm *getLocalTimeInfo();
int getAnoActual();
struct tm convertStringToDate(string data);
string convertTimeToString(struct tm Time);
bool dataJaUltrapassada(int dia, int mes, int ano);
bool operator <(struct tm t1, struct tm t2);

bool fileExists(const string &fileName);
int parseFilename(string &fileName);

int processMatricula(string &Matricula);

void waitForValidInt(int &num, int min, int max, string descricao);

#endif /* UTILITIES_H_ */

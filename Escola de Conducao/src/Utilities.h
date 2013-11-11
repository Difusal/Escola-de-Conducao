#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#define FOR(i, a, b) for(unsigned int i = a; i < b; i++)
#define ALL(v) (v).begin(), (v).end()
#define foreach(v, it) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++ )

void sleep(double seconds);
struct tm *getLocalTimeInfo();
int getAnoActual();
struct tm convertStringToDate(string data);
string convertTimeToString(struct tm Time);

bool fileExists(const string &fileName);
int parseFilename(string &fileName);

int processMatricula(string &Matricula);

#endif /* UTILITIES_H_ */

#include "Viatura.h"

int Viatura::info() const {
	cout << "\tMatricula: " << matricula << endl;
	cout << "\tAno de Fabrico: " << anoFabrico << endl;
	cout << "\tMarca: " << marca << endl;
	return 3;
}

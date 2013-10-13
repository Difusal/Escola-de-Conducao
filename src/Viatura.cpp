#include "Viatura.h"

int Viatura::info() const {
	cout << "Matricula: " << matricula << endl;
	cout << "Ano de Fabrico: " << anoFabrico << endl;
	cout << "Marca: " << marca << endl;
	return 3;
}

#include "Ligeiro.h"

int Ligeiro::info() const {
	int prevInfo = Automovel::info();
	//cout << "Carga Maxima: " << cargaMaxima << endl;
	return prevInfo + 0;
}

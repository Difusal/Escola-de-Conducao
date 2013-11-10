#include "Pesado.h"

int Pesado::info() {
	int prevInfo = Automovel::info();
	//cout << "\tCarga Maxima: " << cargaMaxima << endl;
	//return prevInfo + 1;
	return prevInfo;
}

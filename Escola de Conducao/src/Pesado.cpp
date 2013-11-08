#include "Pesado.h"

int Pesado::info() {
	int prevInfo = Automovel::info();
	cout << "Carga Maxima: " << cargaMaxima << endl;
	return prevInfo + 1;
}

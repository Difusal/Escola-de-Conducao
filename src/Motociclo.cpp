#include "Motociclo.h"

int Motociclo::info() const {
	int infoV = Viatura::info();
	/*
	cout << "Combustivel: " << combustivel << endl;
	cout << "Cilindrada: " << cilindrada << endl;
	*/
	return infoV + 0;
}

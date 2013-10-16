#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include "Escola.h"
#include "Viatura.h"
#include "Ligeiro.h"
#include "Pesado.h"
#include "Motociclo.h"

using namespace std;

void testCriarViaturas() {
	Ligeiro a1("44-01-MJ", 1994, "Range Rover");
	Ligeiro a2("12-15-XD", 2012, "Renault");
	Pesado p1("33-HS-47", 2002, "GMC", 5000);
	Motociclo m1("54-LS-65", 2010, "Yamaha");

	ASSERT_EQUAL("Range Rover", a1.getMarca());
	ASSERT_EQUAL(2012, a2.getAnoFabrico());
	ASSERT_EQUAL(5000, p1.getCargaMaxima());
	ASSERT_EQUAL("GMC", p1.getMarca());
	ASSERT_EQUAL("Yamaha", m1.getMarca());
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(testCriarViaturas));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "CG1 AEDA 2013/2014 - Gestao de uma Escola de Conducao");
}

int main(){
	// ucomment next line for cute tests
    //runSuite();

	Escola Viriato;
	Viriato.showMainMenu();

    return 0;
}

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

//#include "Viatura.h"

using namespace std;

void test_a_criarAnimais() {
	/*
	Animal *a1=new Cao("kurika",10,"estrela");  //nome, idade, ra�a
	Animal *a2=new Morcego("bobo",2,70,2);  //nome, idade, velocidade_maxima, altura_maxima
	Animal *a3=new Cao("bobby",3,"rafeiro");
	Animal *a4=new Cao("fly",7,"dalmata");
	Animal *a5=new Morcego("timao",7,80,4);
	ASSERT_EQUAL("kurika", a1->getNome());
	ASSERT_EQUAL("bobo", a2->getNome());
	ASSERT_EQUAL("bobby", a3->getNome());
	ASSERT_EQUAL("fly", a4->getNome());
	ASSERT_EQUAL("timao", a5->getNome());
	ASSERT_EQUAL(2, Animal::getMaisJovem());
	*/
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_a_criarAnimais));
	/*
	s.push_back(CUTE(test_b_adicionarAnimais));
	s.push_back(CUTE(test_c_imprimirAnimais));
	s.push_back(CUTE(test_d_verificarAnimalJovem));
	s.push_back(CUTE(test_e_alocarVeterinarios));
	s.push_back(CUTE(test_f_removerVeterinario));
	s.push_back(CUTE(test_g_compararZoos));
	*/
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "CG1 AEDA 2013/2014 - Gestao de uma Escola de Conducao");
}

int main(){
    runSuite();
    return 0;
}

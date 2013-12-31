/*!
 * \file main.cpp
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Maria Joao Marques
 * \author Tiago Figueiredo
 *
 * \date Dezembro 2013
 *
 */
#include "Program.h"

using namespace std;

int main(){
	Program program;
	program.loadSchoolsFile();
	program.loadOficinas();
	program.showLoginScreen();

    return 0;
}

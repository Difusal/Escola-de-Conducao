/*!
 * \file main.cpp
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Novembro 2013
 *
 */
#include "Program.h"

using namespace std;

int main(){
	Program program;
	program.loadSchoolsFile();
	program.showLoginScreen();

    return 0;
}

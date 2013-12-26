/*!
 * \file Program.cpp
 *
 * \author FEUP AEDA1314 2MIEIC5 C:
 * \author David Azevedo
 * \author Henrique Ferrolho
 * \author Tiago Figueiredo
 *
 * \date Dezembro 2013
 *
 */
#include "Program.h"

#include <fstream>

int Program::loadSchoolsFile() {
	string designacao, localizacao;
	unsigned int n, nMaxAlunos;

	cout << endl;
	cout << "A carregar escolas... ";

	// opening input strings
	string path = "Escolas";
	parseFilename(path);
	ifstream fin(path.c_str());

	fin >> n;
	FOR(i, 0, n)
	{
		fin >> designacao >> localizacao >> nMaxAlunos;

		Escola nova(designacao, localizacao, nMaxAlunos);
		escolas.insert(nova);
	}
	cout << "OK!" << endl;

	return 0;
}

void Program::showLoginScreen() {
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "**********************" << endl;
		cout << "* Escola de Conducao *" << endl;
		cout << "**********************" << endl;
		cout << endl;
		cout << "1. Carregar escola existente" << endl;
		cout << "2. Criar uma nova escola" << endl;
		cout << "3. Editar escola" << endl;
		cout << "4. Apagar escola" << endl;
		cout << "5. Visualizar escolas" << endl;
		cout << endl;
		cout << "X. Terminar Programa" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);
		done = false;
		switch (input) {
		case '1':
			showLoginUI();
			break;
		case '2':
			showSignUpUI();
			break;
		case '3':
			showEditSchoolUI();
			break;
		case '4':
			showRemoveSchoolUI();
			break;
		case '5':
			showViewSchoolUI();
			break;
		case 'x':
			cout << "A terminar programa..." << endl;
			exit(0);
		default:
			done = false;
			break;
		}
	}
}

void Program::showLoginUI() {
	string input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "Nome da escola: ";
		cin.clear();
		getline(cin, input);
		escola->setDesignacao(input);

		// if user chose to go back to start menu
		if (input.size() == 1 && input[0] == '.') {
			showLoginScreen();
			done = true;
			break;
		}

		parseFilename(input);
		if (fileExists(input)) {
			escola->loadSchoolData();
			if (escola->showMainMenu())
				showLoginScreen();
			done = true;
			return;
		} else {
			cout << "Erro:\tEscola inexistente." << endl;
			cout << "\tSe pretende retornar ao menu inicial" << endl;
			cout << "\tinsira o caracter \'.\' como nome da escola." << endl;
		}
	}
}

void Program::showSignUpUI() {
	string input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "Nome da escola: ";
		cin.clear();
		getline(cin, input);
		escola->setDesignacao(input);

		// if user chose to go back to start menu
		if (input.size() == 1 && input[0] == '.') {
			showLoginScreen();
			done = true;
			return;
		}

		parseFilename(input);
		if (fileExists(input)) {
			cout << "Erro:\tEscola ja existente." << endl;
			cout << "\tSe pretende retornar ao menu inicial" << endl;
			cout << "\tinsira o caracter \'.\' como nome da escola." << endl;
		} else {
			escola->setHorarioUI();
			escola->setLocalizacaoUI();
			escola->setNumMaxAlunosUI();
			escola->createFileStructure();
			escola->showMainMenu();
			done = true;
			return;
		}
	}
}

void Program::showEditSchoolUI() {
	string nomeNovo, unparsedCopy;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "Insira o caracter \'.\' para voltar ao menu inicial." << endl;
		cout << "> Nome antigo da escola: ";
		cin.clear();
		getline(cin, escola->designacao);

		// if user chose to go back to start menu
		if (escola->designacao.size() == 1 && escola->designacao[0] == '.') {
			showLoginScreen();
			done = true;
			return;
		}

		string escolaStr, escolaAulas;

		escolaStr = escola->designacao;
		parseFilename(escolaStr);

		if (fileExists(escolaStr)) {
			stringstream ss;
			ss << escola->designacao << " - aulas";
			escolaAulas = ss.str();
			parseFilename(escolaAulas);

			string oldNameEscola = escolaStr;
			string oldNameEscolaAulas = escolaAulas;

			string tempNameEscola = "tempname.txt";
			string tempNameEscolaAulas = "tempname - aulas.txt";
			parseFilename(tempNameEscola);
			parseFilename(tempNameEscolaAulas);

			if (rename(oldNameEscola.c_str(), tempNameEscola.c_str()) == 0
					&& rename(oldNameEscolaAulas.c_str(),
							tempNameEscolaAulas.c_str()) == 0) {
				// a inserir novo nome para a escola
				cout << "> Nome novo da escola: ";
				cin.clear();
				getline(cin, nomeNovo);
				unparsedCopy = nomeNovo;
				parseFilename(nomeNovo);

				cout << "A alterar o nome da escola... ";
				if (fileExists(nomeNovo)) {
					cout << endl;
					cout << "* Erro ao alterar o nome da escola *" << endl;
					cout
							<< "Ja existe uma escolaStr com o novo nome que escolheu."
							<< endl;
					cout << "A cancelar operacao... ";

					escolaStr = escola->designacao;
					parseFilename(escolaStr);

					ss.str(string());
					ss << escola->designacao << " - aulas";
					escolaAulas = ss.str();
					parseFilename(escolaAulas);

					rename(tempNameEscola.c_str(), escolaStr.c_str());
					rename(tempNameEscolaAulas.c_str(), escolaAulas.c_str());

					cout << "OK!" << endl;
				} else {
					string newNameEscola = unparsedCopy;
					parseFilename(newNameEscola);

					ss.str(string());
					ss << unparsedCopy << " - aulas";
					string newNameEscolaAulas = ss.str();
					parseFilename(newNameEscolaAulas);

					rename(tempNameEscola.c_str(), newNameEscola.c_str());
					rename(tempNameEscolaAulas.c_str(),
							newNameEscolaAulas.c_str());

					cout << "OK!" << endl;
					cout << "* Nome da escolaStr alterado com sucesso *"
							<< endl;
				}
			} else {
				cout << endl;
				cout << "* Erro: o nome que especificou nao existe *" << endl;
			}

			cout << "Prima <enter> para voltar ao menu inicial." << endl;
			cin.get();
			showLoginScreen();
			return;
		} else {
			cout << "Erro:\tO nome da escola inserida não existe." << endl;
			cout << "\tPrima <enter> para voltar ao menu inicial." << endl;
			cin.get();

			showLoginScreen();
			done = true;
			return;
		}
	}
}

void Program::showRemoveSchoolUI() {
	bool done = false;
	while (!done) {
		cout << endl;
		cout << "!!!!!!!!!!!!!!!" << endl;
		cout << "!!  ATENCAO  !!" << endl;
		cout << "!!!!!!!!!!!!!!!" << endl;
		cout << endl;
		cout << "- Todos os dados da escola que inserir vao ser apagados."
				<< endl;
		cout << "  Insira o caracter \'.\' para voltar ao menu inicial."
				<< endl;
		cout << endl;
		cout << "> Nome da escola: ";
		cin.clear();
		getline(cin, escola->designacao);

		// if user chose to go back to start menu
		if (escola->designacao.size() == 1 && escola->designacao[0] == '.') {
			showLoginScreen();
			done = true;
			return;
		}

		string escolaStr, escolaAulas;
		escolaStr = escola->designacao;
		parseFilename(escolaStr);
		if (fileExists(escolaStr)) {
			cout << "A remover dados da escola permanentemente... ";

			escolaAulas = escola->designacao;
			stringstream ss;
			ss << escolaAulas << " - aulas";
			escolaAulas = ss.str();
			parseFilename(escolaAulas);

			if (remove(escolaStr.c_str()) != 0
					|| remove(escolaAulas.c_str()) != 0) {
				cout << endl;
				cout << "* Erro a apagar escola *" << endl;
			} else {
				cout << "OK!" << endl;
				cout << "* Escola apagada com sucesso *" << endl;
			}

			cout << "Prima <enter> para voltar ao menu inicial." << endl;
			cin.get();
			showLoginScreen();
			return;
		} else {
			cout << "Erro:\tO nome da escola inserida não existe." << endl;
			cout << "\tPrima <enter> para voltar ao menu inicial." << endl;
			cin.get();

			showLoginScreen();
			done = true;
			return;
		}
	}
}

void Program::showViewSchoolUI() {
	BSTItrIn<Escola> it = escolas;
	while (!it.isAtEnd()) {
		cout << endl;
		cout << "Escola: " << it.retrieve().designacao << endl;
		cout << "   Localizacao: " << it.retrieve().localizacao << endl;
		cout << "   Numero Max de Alunos: " << it.retrieve().nMaxAlunos << endl;

		it.advance();
	}
	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();

	showLoginScreen();
}

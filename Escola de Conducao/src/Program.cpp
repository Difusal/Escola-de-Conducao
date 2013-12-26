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
#include "Exceptions.h"

int Program::loadSchoolsFile() {
	escolas.makeEmpty();

	string designacao, localizacao;
	unsigned int n, nMaxAlunos;

	/*
	cout << endl;
	cout << "A carregar escolas... ";
	*/

	// opening input strings
	string path = "Escolas";
	parseFilename(path);
	if (!fileExists(path))
		return 1;

	ifstream fin(path.c_str());

	fin >> n;
	FOR(i, 0, n)
	{
		fin >> designacao >> localizacao >> nMaxAlunos;

		Escola nova(designacao, localizacao, nMaxAlunos);
		escolas.insert(nova);
	}
	//cout << "OK!" << endl;

	return 0;
}

void Program::renameSchoolFromMainFile(string Nome, string NomeNovo) {
	string mainFile = "Escolas";
	parseFilename(mainFile);

	// reading schools
	vector<Escola> escolasTemp;
	unsigned int n;
	if (fileExists(mainFile)) {
		ifstream fin(mainFile.c_str());

		fin >> n;

		string nome, local;
		int nMax;
		FOR(i, 0, n)
		{
			fin >> nome >> local >> nMax;
			escolasTemp.push_back(Escola(nome, local, nMax));
		}

		n--;

		ofstream fout(mainFile.c_str());
		fout << n << endl;
		FOR(i, 0, escolasTemp.size())
		{
			if (Nome == escolasTemp[i].getDesignacao())
				fout << NomeNovo << " " << escolasTemp[i].getLocalizacao()
						<< " " << escolasTemp[i].getNumMaxALunos() << endl;
			else
				fout << escolasTemp[i].getDesignacao() << " "
						<< escolasTemp[i].getLocalizacao() << " "
						<< escolasTemp[i].getNumMaxALunos() << endl;
		}
	}
}

void Program::changeSchoolNumMaxStudentsFromMainFileUI() {
	string Nome;
	int NumNovo;

	cout << endl;
	cout << "Qual o nome da escola?\n\t> ";
	cin >> Nome;
	cin.ignore();
	cout << "Qual o numero de alunos maximo a definir?\n\t> ";
	cin >> NumNovo;
	cin.ignore();

	string mainFile = "Escolas";
	parseFilename(mainFile);

	// reading schools
	vector<Escola> escolasTemp;
	unsigned int n;
	if (fileExists(mainFile)) {
		ifstream fin(mainFile.c_str());

		fin >> n;

		string nome, local;
		int nMax;
		FOR(i, 0, n)
		{
			fin >> nome >> local >> nMax;
			escolasTemp.push_back(Escola(nome, local, nMax));
		}

		ofstream fout(mainFile.c_str());
		fout << n << endl;
		FOR(i, 0, escolasTemp.size())
		{
			if (Nome == escolasTemp[i].getDesignacao())
				fout << escolasTemp[i].getDesignacao() << " "
						<< escolasTemp[i].getLocalizacao() << " " << NumNovo
						<< endl;
			else
				fout << escolasTemp[i].getDesignacao() << " "
						<< escolasTemp[i].getLocalizacao() << " "
						<< escolasTemp[i].getNumMaxALunos() << endl;
		}
	} else
		cout << "ERROR" << endl;
}

void Program::removeSchoolFromMainFile(string Designacao) {
	string mainFile = "Escolas";
	parseFilename(mainFile);

	// reading schools
	vector<Escola> escolasTemp;
	unsigned int n;
	if (fileExists(mainFile)) {
		ifstream fin(mainFile.c_str());

		fin >> n;

		string nome, local;
		int nMax;
		FOR(i, 0, n)
		{
			fin >> nome >> local >> nMax;
			escolasTemp.push_back(Escola(nome, local, nMax));
		}

		n--;

		ofstream fout(mainFile.c_str());
		fout << n << endl;
		FOR(i, 0, escolasTemp.size())
		{
			if (Designacao != escolasTemp[i].getDesignacao())
				fout << escolasTemp[i].getDesignacao() << " "
						<< escolasTemp[i].getLocalizacao() << " "
						<< escolasTemp[i].getNumMaxALunos() << endl;
		}
	}
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

		loadSchoolsFile();
		BSTItrIn<Escola> it = escolas;
		while (!it.isAtEnd()) {
			if (it.retrieve().designacao == input) {
				escola->designacao = it.retrieve().designacao;
				escola->localizacao = it.retrieve().localizacao;
				escola->nMaxAlunos = it.retrieve().nMaxAlunos;
				break;
			}

			it.advance();
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
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "1. Alterar nome" << endl;
		cout << "2. Alterar numero maximo de alunos" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);
		done = false;
		switch (input) {
		case '1':
			showRenameSchoolUI();
			done = true;
			break;
		case '2':
			changeSchoolNumMaxStudentsFromMainFileUI();
			done = true;
			break;
		default:
			done = false;
			break;
		}
	}
}

void Program::showRenameSchoolUI() {
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

					cout << "changing " << escola->designacao << " por "
							<< unparsedCopy << endl;
					renameSchoolFromMainFile(escola->designacao, unparsedCopy);

					cout << "OK!" << endl;
					cout << "* Nome da escola alterado com sucesso *" << endl;
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

			removeSchoolFromMainFile(escola->designacao);

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
	loadSchoolsFile();

	try {
		if (escolas.isEmpty())
			throw ColecaoVazia("Escolas");

		BSTItrIn<Escola> it = escolas;
		while (!it.isAtEnd()) {
			cout << endl;
			cout << "Escola: " << it.retrieve().designacao << endl;
			cout << "   Localizacao: " << it.retrieve().localizacao << endl;
			cout << "   Numero Max de Alunos: " << it.retrieve().nMaxAlunos
					<< endl;

			it.advance();
		}
		cout << endl;
		cout << "Pressione enter para continuar... ";
		cin.get();
	} catch (ColecaoVazia &e) {
		e.what();
	}

	showLoginScreen();
}

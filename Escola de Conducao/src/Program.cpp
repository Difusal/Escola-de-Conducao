/*!
 * \file Program.cpp
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
		cout << "6. Adicionar Oficina" << endl;
		cout << "7. Editar Oficina" << endl;
		cout << "8. Remover Oficina" << endl;
		cout << "9. Listar Oficinas" << endl;
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
		case '6':
			showAddWorkshopUI();
			break;
		case '7':
			showEditWorkshopUI();
			break;
		case '8':
			showRemoveWorkshopUI();
			break;
		case '9':
			viewWorkshopsList();
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

void Program::loadOficinas() {
	string oficinasPath = "oficinas";
	parseFilename(oficinasPath);

	if (fileExists(oficinasPath)) {
		ifstream fin(oficinasPath.c_str());

		unsigned int n;

		string nome, local;
		int disponibilidade;

		unsigned int nMarcas;
		string marca;

		fin >> n;
		FOR(i, 0, n)
		{
			fin >> nome >> local >> disponibilidade;

			addOficina(nome, local, 0);
			alteraDisponibilidadeDeOficina(nome, disponibilidade, 0);

			fin >> nMarcas;
			FOR(j, 0, nMarcas)
			{
				fin >> marca;
				addMarcaToOficina(nome, marca, 0);
			}
		}
	}
}

void Program::saveOficinas() {
	string oficinasPath = "oficinas";
	parseFilename(oficinasPath);

	ofstream fout(oficinasPath.c_str());

	// numero de oficinas
	fout << oficinas.size() << endl;

	HEAP_OFICINAS oficinasCopy = oficinas;

	while (!oficinasCopy.empty()) {
		Oficina temp = oficinasCopy.top();
		oficinasCopy.pop();

		// oficina
		fout << temp.getDenominacao() << " " << temp.getLocalizacao() << " "
				<< temp.getDisponibilidade() << endl;

		// marcas especializadas
		fout << temp.getMarcasEspecializadas().size() << endl;
		FOR(i, 0, temp.getMarcasEspecializadas().size())
			fout << temp.getMarcasEspecializadas()[i] << endl;
	}
}

void Program::showAddWorkshopUI() {
	string oficina, local;

	cout << endl;
	cout << "> Insira o nome da oficina:" << endl;
	cout << "> ";
	cin >> oficina;
	cin.ignore();

	cout << endl;
	cout << "> Insira a localizacao da oficina:" << endl;
	cout << "> ";
	cin >> local;
	cin.ignore();

	addOficina(oficina, local);
}

void Program::viewWorkshopsList() {
	try {
		if (oficinas.empty())
			throw ColecaoVazia("Oficinas");

		HEAP_OFICINAS oficinasCopy = oficinas;

		cout << endl;
		cout << "------------------" << endl;
		cout << "Lista de oficinas:" << endl;
		cout << "------------------" << endl;
		cout << endl;
		while (!oficinasCopy.empty()) {
			Oficina temp = oficinasCopy.top();

			cout << "Oficina " << temp.getDenominacao() << endl;
			cout << "   Localizacao: " << temp.getLocalizacao() << endl;
			cout << "   Disponibilidade: " << temp.getDisponibilidade() << endl;
			cout << "   Marcas especializadas: "
					<< temp.getMarcasEspecializadasStr() << endl;
			cout << endl;

			oficinasCopy.pop();
		}

		cout << "Prima <enter> para voltar ao menu inicial." << endl;
		cin.get();
	} catch (ColecaoVazia &e) {
		e.what();
	}
}

void Program::showEditWorkshopUI() {
	string oficina, marca;
	int disponibilidade;
	char input;

	cout << endl;
	cout << "> Insira o nome da oficina:" << endl;
	cout << "> ";
	cin >> oficina;
	cin.ignore();

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "1. Adicionar marca especializada" << endl;
		cout << "2. Remover marca especializada" << endl;
		cout << "3. Redefinir disponibilidade" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);
		done = false;
		switch (input) {
		case '1':
			cout << endl;
			cout << "Insira a marca: ";
			cin >> marca;
			cin.ignore();
			addMarcaToOficina(oficina, marca);
			done = true;
			break;
		case '2':
			cout << endl;
			cout << "Insira a marca: ";
			cin >> marca;
			cin.ignore();
			removeMarcaFromOficina(oficina, marca);
			done = true;
			break;
		case '3':
			cout << endl;
			cout << "Insira a disponibiliade: ";
			cin >> disponibilidade;
			cin.ignore();
			alteraDisponibilidadeDeOficina(oficina, disponibilidade);
			done = true;
			break;
		default:
			done = false;
			break;
		}
	}
}

void Program::showRemoveWorkshopUI() {
	string oficina;

	cout << endl;
	cout << "> Insira o nome da oficina:" << endl;
	cout << "> ";
	cin >> oficina;
	cin.ignore();

	removeOficina(oficina);
}

void Program::addOficina(string Nome, string Local, bool feedback) {
	HEAP_OFICINAS oficinasCopy = oficinas;

	// checking if already exists
	bool existe = false;
	while (!oficinasCopy.empty()) {
		Oficina temp = oficinasCopy.top();

		if (temp.getDenominacao() == Nome) {
			cout << endl << "O nome " << Nome << " ja esta a ser utilizado."
					<< endl;
			cout << "Prima <enter> para voltar ao menu inicial." << endl;
			cin.get();

			existe = true;
			return;
		}

		oficinasCopy.pop();
	}
	if (!existe)
		oficinas.push(Oficina(Nome, Local));

	if (feedback) {
		saveOficinas();

		cout << endl;
		cout << "Oficina " << Nome << " adicionada." << endl;
		cout << "Prima <enter> para voltar ao menu inicial." << endl;
		cin.get();
	}
}

void Program::removeOficina(string Nome) {
	HEAP_OFICINAS oficinasCopy;

	bool existe = false;
	while (!oficinas.empty()) {
		Oficina temp = oficinas.top();

		if (temp.getDenominacao() != Nome)
			oficinasCopy.push(temp);
		else if (temp.getDenominacao() == Nome)
			existe = true;

		oficinas.pop();
	}

	oficinas = oficinasCopy;

	if (existe) {
		saveOficinas();

		cout << endl;
		cout << "Oficina removida." << endl;
	} else {
		cout << endl;
		cout << "A oficina " << Nome << " nao existe." << endl;
	}

	cout << "Prima <enter> para voltar ao menu inicial." << endl;
	cin.get();

}

void Program::addMarcaToOficina(string Nome, string marca, bool feedback) {
	HEAP_OFICINAS oficinasCopy;

	bool existe = false;
	while (!oficinas.empty()) {
		Oficina temp = oficinas.top();

		if (temp.getDenominacao() == Nome) {
			existe = true;

			int res = temp.addMarca(marca);

			if (feedback) {
				if (res == 1)
					cout << endl << "A marca " << marca
							<< " ja existe na oficina " << Nome << "." << endl;
				else
					cout << endl << "A marca " << marca
							<< " foi adicionada a oficina " << Nome << "."
							<< endl;
			}
		}

		oficinasCopy.push(temp);

		oficinas.pop();
	}

	oficinas = oficinasCopy;

	if (!existe && feedback) {
		cout << endl;
		cout << "A oficina " << Nome << " nao existe." << endl;
	}

	if (feedback) {
		saveOficinas();

		cout << "Prima <enter> para voltar ao menu inicial." << endl;
		cin.get();
	}
}

void Program::removeMarcaFromOficina(string Nome, string marca) {
	HEAP_OFICINAS oficinasCopy;

	bool existe = false;
	while (!oficinas.empty()) {
		Oficina temp = oficinas.top();

		if (temp.getDenominacao() == Nome) {
			existe = true;

			if (temp.removeMarca(marca) == 0)
				cout << endl << "A marca " << marca << " nao existe na oficina "
						<< Nome << "." << endl;
			else
				cout << endl << "A marca " << marca
						<< " foi removida da oficina " << Nome << "." << endl;
		}

		oficinasCopy.push(temp);

		oficinas.pop();
	}

	oficinas = oficinasCopy;

	if (!existe) {
		cout << endl;
		cout << "A oficina " << Nome << " nao existe." << endl;
	}

	saveOficinas();
	cout << "Prima <enter> para voltar ao menu inicial." << endl;
	cin.get();
}

void Program::alteraDisponibilidadeDeOficina(string Nome, int disponibilidade,
		bool feedback) {
	HEAP_OFICINAS oficinasCopy;

	bool existe = false;
	while (!oficinas.empty()) {
		Oficina temp = oficinas.top();

		if (temp.getDenominacao() == Nome) {
			existe = true;

			temp.setDisponibilidade(disponibilidade);

			if (feedback)
				cout << endl << "A disponibilidade da oficina " << Nome
						<< " foi alterada." << endl;
		}

		oficinasCopy.push(temp);

		oficinas.pop();
	}

	oficinas = oficinasCopy;

	if (!existe && feedback) {
		cout << endl;
		cout << "A oficina " << Nome << " nao existe." << endl;
	}

	if (feedback) {
		saveOficinas();

		cout << "Prima <enter> para voltar ao menu inicial." << endl;
		cin.get();
	}
}

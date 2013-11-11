#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Escola.h"
#include "Utilities.h"
#include "Exceptions.h"

Escola::Escola() {
	nome = "";
	abertura = fecho = 0;
}

Escola::~Escola() {
	// TODO Auto-generated destructor stub
}

int Escola::createFileStructure() {
	cout << "---------------------------------" << endl;
	cout << "A criar ficheiros iniciais... ";

	string escola, escolaAulas;

	// opening output strings
	escola = nome;
	parseFilename(escola);
	ofstream fout(escola.c_str());

	stringstream ss;
	ss << nome << " - aulas";
	escolaAulas = ss.str();
	parseFilename(escolaAulas);
	ofstream foutAulas(escolaAulas.c_str());

	// writing to streams
	fout << "0\n0\n0";

	foutAulas << abertura << " " << fecho << endl;
	foutAulas << 0;

	cout << "OK!" << endl;
	cout << "---------------------------------" << endl;

	return 0;
}

int Escola::saveSchoolData() {
	// TODO finish this
	string escola, escolaAulas;

	// opening output strings
	escola = nome;
	parseFilename(escola);
	ofstream fout(escola.c_str());

	stringstream ss;
	ss << nome << " - aulas";
	escolaAulas = ss.str();
	parseFilename(escolaAulas);
	ofstream foutAulas(escolaAulas.c_str());

	// A guardar viaturas
	fout << numViaturas() << endl;
	FOR(i, 0, numViaturas())
		fout << viaturas[i]->printToFile() << endl;

	// A guardar instrutores
	fout << numInstrutores() << endl;
	FOR(i, 0, numInstrutores())
		fout << instrutores[i]->printToFile() << endl;

	// A guardar alunos
	fout << numAlunos() << endl;
	FOR(i, 0, numAlunos())
		fout << alunos[i]->printToFile() << endl;

	// A guardar aulas
	foutAulas << abertura << " " << fecho << endl;
	foutAulas << numAulas() << endl;
	FOR(i, 0, numAulas())
		foutAulas << aulas[i]->printToFile() << endl;

	return 0;
}

int Escola::loadSchoolData() {
	unsigned int n;
	string escola, escolaAulas;
	// TODO this func

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "- A carregar dados da escola -" << endl;
	cout << "------------------------------" << endl;

	// opening input strings
	escola = nome;
	parseFilename(escola);
	ifstream fin(escola.c_str());

	stringstream ss;
	ss << nome << " - aulas";
	escolaAulas = ss.str();
	parseFilename(escolaAulas);
	ifstream finAulas(escolaAulas.c_str());

	cout << "> A carregar viaturas... ";
	viaturas.clear();
	string matricula, marca, tipo, dataUltimaInspec;
	int anoFabrico, periodicidade;

	fin >> n;
	FOR(i, 0, n)
	{
		fin >> matricula >> anoFabrico >> marca >> tipo >> dataUltimaInspec
				>> periodicidade;

		Viatura *temp;
		if (tipo == "ligeiro") {
			temp = new Ligeiro(matricula, anoFabrico, marca, periodicidade);
		} else if (tipo == "pesado") {
			temp = new Pesado(matricula, anoFabrico, marca, periodicidade);
		} else if (tipo == "motociclo") {
			temp = new Motociclo(matricula, anoFabrico, marca, periodicidade);
		} else {
			// TODO exception here
		}
		temp->setDataUltimaInspecao(dataUltimaInspec);
		viaturas.push_back(temp);
	}
	cout << "OK!" << endl;

	cout << "> A carregar instrutores... ";
	instrutores.clear();
	string nome;
	bool lig, pes, moto;

	fin >> n;
	FOR(i, 0, n)
	{
		fin >> nome >> lig >> pes >> moto;

		Instrutor *temp;
		temp = new Instrutor(nome, lig, pes, moto);
		instrutores.push_back(temp);
	}
	cout << "OK!" << endl;

	cout << "> A carregar alunos... ";
	alunos.clear();
	int tipoCarta;
	string matriculaUsual;

	fin >> n;
	FOR(i, 0, n)
	{
		fin >> nome >> tipoCarta >> matriculaUsual;

		Aluno *temp;
		Viatura *viaturaUsual;
		viaturaUsual = getViaturaComMatricula(matriculaUsual);
		temp = new Aluno(nome, (TipoCartaConducao) tipoCarta, viaturaUsual);
		alunos.push_back(temp);
	}
	cout << "OK!" << endl;

	cout << "> A carregar aulas... ";
	aulas.clear();

	finAulas >> abertura >> fecho;
	finAulas >> n;
	FOR(i, 0, n) {
		// TODO thiasfa
		;
	}
	cout << "OK!" << endl;

	return 0;
}

void Escola::showLoginScreen() {
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
		cout << "3. Alterar nome de escola" << endl;
		cout << "4. Apagar escola" << endl;
		cout << endl;
		cout << "X. Terminar Programa" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);
		done = true;
		switch (input) {
		case '1':
			showLoginUI();
			break;
		case '2':
			showSignUpUI();
			break;
		case '3':
			showRenameSchoolUI();
			break;
		case '4':
			showRemoveSchoolUI();
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

void Escola::showLoginUI() {
	string input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "Nome da escola: ";
		cin.clear();
		getline(cin, input);
		nome = input;

		// if user chose to go back to start menu
		if (input.size() == 1 && input[0] == '.') {
			showLoginScreen();
			done = true;
			break;
		}

		parseFilename(input);
		if (fileExists(input)) {
			loadSchoolData();
			showMainMenu();
			done = true;
			return;
		} else {
			cout << "Erro:\tEscola inexistente." << endl;
			cout << "\tSe pretende retornar ao menu inicial" << endl;
			cout << "\tinsira o caracter \'.\' como nome da escola." << endl;
		}
	}
}

void Escola::showSignUpUI() {
	string input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "Nome da escola: ";
		cin.clear();
		getline(cin, input);
		nome = input;

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
			setHorarioUI();
			createFileStructure();
			showMainMenu();
			done = true;
			return;
		}
	}
}

void Escola::showRenameSchoolUI() {
	string nomeNovo, unparsedCopy;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "Insira o caracter \'.\' para voltar ao menu inicial." << endl;
		cout << "> Nome antigo da escola: ";
		cin.clear();
		getline(cin, nome);

		// if user chose to go back to start menu
		if (nome.size() == 1 && nome[0] == '.') {
			showLoginScreen();
			done = true;
			return;
		}

		string escola, escolaAulas;

		escola = nome;
		parseFilename(escola);

		if (fileExists(escola)) {
			stringstream ss;
			ss << nome << " - aulas";
			escolaAulas = ss.str();
			parseFilename(escolaAulas);

			string oldNameEscola = escola;
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
					cout << "Ja existe uma escola com o novo nome que escolheu."
							<< endl;
					cout << "A cancelar operacao... ";

					escola = nome;
					parseFilename(escola);

					ss.str(string());
					ss << nome << " - aulas";
					escolaAulas = ss.str();
					parseFilename(escolaAulas);

					rename(tempNameEscola.c_str(), escola.c_str());
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

int Escola::setHorarioUI() {
	cout << "> Insira o horario da escola:" << endl;

	while (1) {
		try {
			cout << "\tAbertura: ";
			cin >> abertura;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(HoraInvalida(abertura));
			} else if (0 <= abertura && abertura <= 23)
				break;
			else
				throw(HoraInvalida(abertura));
		} catch (HoraInvalida &e) {
			e = HoraInvalida(abertura);
			e.what();
		}
	}

	while (1) {
		try {
			cout << "\tFecho: ";
			cin >> fecho;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(HoraInvalida(fecho));
			} else if (0 <= fecho && fecho <= 23)
				break;
			else
				throw(HoraInvalida(fecho));
		} catch (HoraInvalida &e) {
			e = HoraInvalida(fecho);
			e.what();
		}
	}

	return 0;
}

void Escola::showRemoveSchoolUI() {
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
		getline(cin, nome);

		// if user chose to go back to start menu
		if (nome.size() == 1 && nome[0] == '.') {
			showLoginScreen();
			done = true;
			return;
		}

		string escola, escolaAulas;
		escola = nome;
		parseFilename(escola);
		if (fileExists(escola)) {
			cout << "A remover dados da escola permanentemente... ";

			escolaAulas = nome;
			stringstream ss;
			ss << escolaAulas << " - aulas";
			escolaAulas = ss.str();
			parseFilename(escolaAulas);

			if (remove(escola.c_str()) != 0
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

void Escola::showMainMenu() {
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "**********************" << endl;
		cout << "* Escola de Conducao *" << endl;
		cout << "**********************" << endl;
		cout << endl;
		cout << "- Manutencao de:" << endl;
		cout << "\t1. Viaturas" << endl;
		cout << "\t2. Instrutores" << endl;
		cout << "\t3. Alunos" << endl;
		cout << "\t4. Aulas" << endl;
		cout << endl;
		cout << "X. Terminar Sessão" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;

		input = tolower(input);
		done = true;
		switch (input) {
		case '1':
			showManutencaoViaturasUI();
			break;
		case '2':
			showManutencaoInstrutoresUI();
			break;
		case '3':
			showManutencaoAlunosUI();
			break;
		case '4':
			showManutencaoAulasUI();
			break;
		case 'x':
			cout << "A terminar sessao..." << endl;
			showLoginScreen();
			return;
		default:
			done = false;
			break;
		}
	}
}

void Escola::showManutencaoViaturasUI() {
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "--------------------------" << endl;
		cout << "- Manutencao de Viaturas -" << endl;
		cout << "--------------------------" << endl;
		cout << "1. Visualizar viaturas" << endl;
		cout << "2. Adicionar viatura" << endl;
		cout << "3. Editar viatura" << endl;
		cout << "4. Remover viatura" << endl;
		cout << endl;
		cout << "X. Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);

		done = false;
		switch (input) {
		case '1':
			showVisualizaViaturasUI();
			break;
		case '2':
			showAdicionarViaturaUI();
			break;
		case '3':
			showEditarViaturaUI();
			break;
		case '4':
			showRemoverViaturaUI();
			break;
		case 'x':
			showMainMenu();
			done = true;
			break;
		default:
			break;
		}
	}
}

void Escola::showManutencaoInstrutoresUI() {
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "-----------------------------" << endl;
		cout << "- Manutencao de Instrutores -" << endl;
		cout << "-----------------------------" << endl;
		cout << "1. Visualizar instrutores" << endl;
		cout << "2. Adicionar instrutor" << endl;
		cout << "3. Editar dados de instrutor" << endl;
		cout << "4. Remover instrutor" << endl;
		cout << endl;
		cout << "X. Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);

		done = false;
		switch (input) {
		case '1':
			showVisualizaInstrutoresUI();
			break;
		case '2':
			showAdicionarInstrutorUI();
			break;
		case '3':
			showEditarInstrutorUI();
			break;
		case '4':
			showRemoverInstrutorUI();
			break;
		case 'x':
			showMainMenu();
			done = true;
			break;
		default:
			break;
		}
	}
}

void Escola::showManutencaoAlunosUI() {
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "------------------------" << endl;
		cout << "- Manutencao de Alunos -" << endl;
		cout << "------------------------" << endl;
		cout << "1. Visualizar alunos" << endl;
		cout << "2. Adicionar aluno" << endl;
		cout << "3. Editar dados de aluno" << endl;
		cout << "4. Remover aluno" << endl;
		cout << endl;
		cout << "X. Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);

		done = false;
		switch (input) {
		case '1':
			showVisualizaAlunosUI();
			break;
		case '2':
			showAdicionarAlunoUI();
			break;
		case '3':
			showEditarAlunoUI();
			break;
		case '4':
			showRemoverAlunoUI();
			break;
		case 'x':
			showMainMenu();
			done = true;
			break;
		default:
			break;
		}
	}
}

void Escola::showManutencaoAulasUI() {
	// TODO this method
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "-----------------------" << endl;
		cout << "- Manutencao de Aulas -" << endl;
		cout << "-----------------------" << endl;
		cout << "1. Visualizar aulas" << endl;
		cout << "2. Marcar aula" << endl;
		cout << "3. Editar aula" << endl;
		cout << "4. Desmarcar aula" << endl;
		cout << endl;
		cout << "X. Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();

		input = tolower(input);

		done = false;
		switch (input) {
		case '1':
			showVisualizaAulasUI();
			break;
		case '2':
			showMarcarAulaUI();
			break;
		case '3':
			showEditarAulaUI();
			break;
		case '4':
			showDesmarcarAulaUI();
			break;
		case 'x':
			showMainMenu();
			done = true;
			break;
		default:
			break;
		}
	}
}

void Escola::showVisualizaViaturasUI() {
	try {
		if (numViaturas() == 0)
			throw ColecaoVazia("Viaturas");

		cout << endl;
		cout << "------------------------" << endl;
		cout << "- Listagem de viaturas -" << endl;
		cout << "------------------------" << endl;
		cout << "1. Matricula" << endl;
		cout << "2. Ano de fabrico" << endl;
		cout << "3. Marca" << endl;
		cout << "4. Tipo" << endl;
		cout << "5. Ultima data de inspecao" << endl;
		cout << "6. Periodicidade de inspecoes" << endl;
		cout << endl;

		bool done = false;
		while (!done) {
			cout << "> Escolha o metodo de ordenacao da lista:" << endl;
			cout << "> ";
			char input;
			cin >> input;
			cin.ignore();

			done = true;
			switch (input) {
			case '1':
				visualizaViaturas(MATRICULA);
				break;
			case '2':
				visualizaViaturas(ANOFABRICO);
				break;
			case '3':
				visualizaViaturas(MARCA);
				break;
			case '4':
				visualizaViaturas(TIPO);
				break;
			case '5':
				visualizaViaturas(DATAULTIMAINSPECAO);
				break;
			case '6':
				visualizaViaturas(PERIODICIDADE);
				break;
			default:
				done = false;
				break;
			}
		}
	} catch (ColecaoVazia &e) {
		e = ColecaoVazia("Viaturas");
		e.what();
	}
}

void Escola::showAdicionarViaturaUI() {
	string matricula;
	int anoFabrico;
	string marca;
	int periodicidade;

	char input;
	bool done = false;
	while (!done) {
		cout << endl;
		cout << "---------------------" << endl;
		cout << "- Adicionar Viatura -" << endl;
		cout << "---------------------" << endl;
		cout << "- Automovel" << endl;
		cout << "\t1. Ligeiro" << endl;
		cout << "\t2. Pesado" << endl;
		cout << "3. Motociclo" << endl;
		cout << endl;
		cout << "X. Voltar ao menu anterior" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;

		input = tolower(input);
		done = true;
		switch (input) {
		case '1':
		case '2':
		case '3':
			done = true;
			break;
		case 'x':
			showManutencaoViaturasUI();
			return;
		default:
			done = false;
			break;
		}
	}

	cout << endl;
	cout << "Insira:" << endl;

	done = false;
	while (!done) {
		try {
			cout << "\ta matricula: ";
			cin >> matricula;
			processMatricula(matricula);
			break;
		} catch (MatriculaInvalida &e) {
			e = MatriculaInvalida(matricula);
			e.what();
		}
	}

	while (1) {
		try {
			cout << "\to ano de fabrico: ";
			cin >> anoFabrico;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(anoFabrico, 0, getAnoActual()));
			} else if (0 <= anoFabrico && anoFabrico <= getAnoActual())
				break;
			else
				throw(InputEsperadoEraInt(anoFabrico, 0, getAnoActual()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(anoFabrico, 0, getAnoActual());
			e.what();
		}
	}

	while (1) {
		try {
			cout << "\ta marca: ";
			cin >> marca;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraString(marca));
			} else {
				FOR(i, 0, marca.size())
				{
					if (i == 0)
						marca[i] = toupper(marca[i]);
					else
						marca[i] = tolower(marca[i]);

				}
				break;
			}
		} catch (InputEsperadoEraString &e) {
			e = InputEsperadoEraString(marca);
			e.what();
		}
	}

	while (1) {
		try {
			cout << "\tperiodicidade (meses): ";
			cin >> periodicidade;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(periodicidade, 1, 24));
			} else if (1 <= periodicidade && periodicidade <= 24)
				break;
			else
				throw(InputEsperadoEraInt(periodicidade, 1, 24));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(periodicidade, 1, 24);
			e.what();
		}
	}

	Viatura *temp;
	switch (input) {
	case '1':
		temp = new Ligeiro(matricula, anoFabrico, marca, periodicidade);
		break;
	case '2':
		temp = new Pesado(matricula, anoFabrico, marca, periodicidade);
		break;
	case '3':
		temp = new Motociclo(matricula, anoFabrico, marca, periodicidade);
		break;
	}
	adicionaViatura(temp);

	cout << endl;
	cout << "* Viatura adicionada com sucesso *" << endl;

	saveSchoolData();
	showManutencaoViaturasUI();
}

void Escola::showEditarViaturaUI() {
	showVisualizaViaturasUI();

	unsigned int input, posViatura, valorNovo;
	while (1) {
		try {
			cout << "> Insira o numero da viatura que pretende editar:" << endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, numViaturas()));
			} else if (1 <= input && input <= numViaturas())
				break;
			else
				throw(InputEsperadoEraInt(input, 1, numViaturas()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, numViaturas());
			e.what();
		}
	}
	posViatura = input - 1;

	cout << "Editar:" << endl;
	cout << "1. Periodicidade de inspecoes" << endl;
	cout << endl;
	while (1) {
		try {
			cout << "> O que pretende editar?" << endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, 1));
			} else if (1 <= input && input <= 1)
				break;
			else
				throw(InputEsperadoEraInt(input, 1, 1));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, 1);
			e.what();
		}
	}
	switch (input) {
	case 1:
		while (1) {
			try {
				cout << "\tNova periodicidade (meses): ";
				cin >> valorNovo;
				cin.ignore();

				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');

					throw(InputEsperadoEraInt(valorNovo, 1, 24));
				} else if (1 <= valorNovo && valorNovo <= 24)
					break;
				else
					throw(InputEsperadoEraInt(valorNovo, 1, 24));
			} catch (InputEsperadoEraInt &e) {
				e = InputEsperadoEraInt(valorNovo, 1, 24);
				e.what();
			}
		}
		break;
	}

	viaturas[posViatura]->setPeriodicidade(valorNovo);
	saveSchoolData();

	cout << "* Viatura editada com sucesso *" << endl;
	cout << "Prima <enter> para voltar ao menu anterior." << endl;
	cin.get();
}

void Escola::showRemoverViaturaUI() {
	showVisualizaViaturasUI();

	unsigned int input;
	while (1) {
		try {
			cout << "> Insira o numero da viatura que pretende remover:"
					<< endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, numViaturas()));
			} else if (1 <= input && input <= numViaturas())
				break;
			else
				throw(InputEsperadoEraInt(input, 1, numViaturas()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, numViaturas());
			e.what();
		}
	}

	viaturas.erase(viaturas.begin() + input - 1);
	saveSchoolData();

	cout << "* Viatura removida com sucesso *" << endl;
	cout << "Prima <enter> para voltar ao menu inicial." << endl;
	cin.get();
}

bool menorMatricula(Viatura *v1, Viatura *v2) {
	return (v1->getMatricula() < v2->getMatricula());
}
bool menorAnoFabrico(Viatura *v1, Viatura *v2) {
	return (v1->getAnoFabrico() < v2->getAnoFabrico());
}
bool menorMarca(Viatura *v1, Viatura *v2) {
	return (v1->getMarca() < v2->getMarca());
}
bool menorTipo(Viatura *v1, Viatura *v2) {
	return (v1->getTipoNumaString() < v2->getTipoNumaString());
}
bool menorDataInspec(Viatura *v1, Viatura *v2) {
	return (v1->getDataUltimaInspecao() < v2->getDataUltimaInspecao());
}
bool menorPeriodicidade(Viatura *v1, Viatura *v2) {
	return (v1->getPeriodicidade() < v2->getPeriodicidade());
}

void Escola::visualizaViaturas(MetodoDeSortDeViaturas metodo) {
	switch (metodo) {
	case MATRICULA:
		sort(ALL(viaturas), menorMatricula);
		break;
	case ANOFABRICO:
		sort(ALL(viaturas), menorAnoFabrico);
		break;
	case MARCA:
		sort(ALL(viaturas), menorMarca);
		break;
	case TIPO:
		sort(ALL(viaturas), menorTipo);
		break;
	case DATAULTIMAINSPECAO:
		sort(ALL(viaturas), menorDataInspec);
		break;
	case PERIODICIDADE:
		sort(ALL(viaturas), menorPeriodicidade);
		break;
	}

	FOR(i, 0, numViaturas())
	{
		cout << endl;
		cout << "> Viatura " << i + 1 << ":" << endl;
		viaturas[i]->info();
	}

	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();
}

void Escola::showVisualizaInstrutoresUI() {
	try {
		if (numInstrutores() == 0)
			throw ColecaoVazia("Instrutores");

		cout << endl;
		cout << "---------------------------" << endl;
		cout << "- Listagem de instrutores -" << endl;
		cout << "---------------------------" << endl;
		cout << "1. Nome" << endl;
		cout << "2. Numero de qualificacoes" << endl;
		cout << "3. Numero de alunos" << endl;
		cout << "4. Numero de aulas" << endl;
		cout << endl;

		bool done = false;
		while (!done) {
			cout << "> Escolha o metodo de ordenacao da lista:" << endl;
			cout << "> ";
			char input;
			cin >> input;
			cin.ignore();

			done = true;
			switch (input) {
			case '1':
				visualizaInstrutores(NOMEINSTRUTOR);
				break;
			case '2':
				visualizaInstrutores(NQUALIFICACOES);
				break;
			case '3':
				visualizaInstrutores(NALUNOS);
				break;
			case '4':
				visualizaInstrutores(NAULAS);
				break;
			default:
				done = false;
				break;
			}
		}
	} catch (ColecaoVazia &e) {
		e = ColecaoVazia("Instrutores");
		e.what();
	}
}

void Escola::showAdicionarInstrutorUI() {
	string nome;
	bool qualifLig, qualifPes, qualifMoto;

	cout << endl;
	cout << "-----------------------" << endl;
	cout << "- Adicionar Instrutor -" << endl;
	cout << "-----------------------" << endl;
	cout << endl;
	cout << "Insira:" << endl;

	bool done = false;
	while (!done) {
		try {
			cout << "\to nome: ";
			cin >> nome;
			//processMatricula(matricula);
			break;
		} catch (MatriculaInvalida &e) {
			//e = MatriculaInvalida(matricula);
			//e.what();
		}
	}

	while (1) {
		try {
			cout << "\tqualificacao de ligeiro: ";
			cin >> qualifLig;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(qualifLig, 0, 1));
			} else if (0 <= qualifLig && qualifLig <= 1)
				break;
			else
				throw(InputEsperadoEraInt(qualifLig, 0, 1));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(qualifLig, 0, 1);
			e.what();
		}
	}
	while (1) {
		try {
			cout << "\tqualificacao de pesado: ";
			cin >> qualifPes;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(qualifPes, 0, 1));
			} else if (0 <= qualifPes && qualifPes <= 1)
				break;
			else
				throw(InputEsperadoEraInt(qualifPes, 0, 1));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(qualifPes, 0, 1);
			e.what();
		}
	}
	while (1) {
		try {
			cout << "\tqualificacao de motociclo: ";
			cin >> qualifMoto;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(qualifMoto, 0, 1));
			} else if (0 <= qualifMoto && qualifMoto <= 1)
				break;
			else
				throw(InputEsperadoEraInt(qualifMoto, 0, 1));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(qualifMoto, 0, 1);
			e.what();
		}
	}

	Instrutor *temp;
	temp = new Instrutor(nome, qualifLig, qualifPes, qualifMoto);
	adicionaInstrutor(temp);

	cout << endl;
	cout << "* Instrutor adicionado com sucesso *" << endl;

	saveSchoolData();
	showManutencaoInstrutoresUI();
}

void Escola::showEditarInstrutorUI() {
	showVisualizaInstrutoresUI();

	unsigned int input, pos;
	bool qualifLig, qualifPes, qualifMoto;
	while (1) {
		try {
			cout << "> Insira o numero do instrutor que pretende editar:"
					<< endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, numInstrutores()));
			} else if (1 <= input && input <= numInstrutores())
				break;
			else
				throw(InputEsperadoEraInt(input, 1, numInstrutores()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, numInstrutores());
			e.what();
		}
	}
	pos = input - 1;

	cout << "Editar:" << endl;
	cout << "1. Qualificacoes" << endl;
	cout << endl;
	while (1) {
		try {
			cout << "> O que pretende editar?" << endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, 1));
			} else if (1 <= input && input <= 1)
				break;
			else
				throw(InputEsperadoEraInt(input, 1, 1));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, 1);
			e.what();
		}
	}
	switch (input) {
	case 1:
		while (1) {
			try {
				cout << "\tqualificacao de ligeiro: ";
				cin >> qualifLig;
				cin.ignore();

				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');

					throw(InputEsperadoEraInt(qualifLig, 0, 1));
				} else if (0 <= qualifLig && qualifLig <= 1)
					break;
				else
					throw(InputEsperadoEraInt(qualifLig, 0, 1));
			} catch (InputEsperadoEraInt &e) {
				e = InputEsperadoEraInt(qualifLig, 0, 1);
				e.what();
			}
		}
		while (1) {
			try {
				cout << "\tqualificacao de pesado: ";
				cin >> qualifPes;
				cin.ignore();

				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');

					throw(InputEsperadoEraInt(qualifPes, 0, 1));
				} else if (0 <= qualifPes && qualifPes <= 1)
					break;
				else
					throw(InputEsperadoEraInt(qualifPes, 0, 1));
			} catch (InputEsperadoEraInt &e) {
				e = InputEsperadoEraInt(qualifPes, 0, 1);
				e.what();
			}
		}
		while (1) {
			try {
				cout << "\tqualificacao de motociclo: ";
				cin >> qualifMoto;
				cin.ignore();

				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');

					throw(InputEsperadoEraInt(qualifMoto, 0, 1));
				} else if (0 <= qualifMoto && qualifMoto <= 1)
					break;
				else
					throw(InputEsperadoEraInt(qualifMoto, 0, 1));
			} catch (InputEsperadoEraInt &e) {
				e = InputEsperadoEraInt(qualifMoto, 0, 1);
				e.what();
			}
		}
		break;
	}

	instrutores[pos]->setQualificacoes(qualifLig, qualifPes, qualifMoto);
	saveSchoolData();

	cout << "* Instrutor editado com sucesso *" << endl;
	cout << "Prima <enter> para voltar ao menu anterior." << endl;
	cin.get();
}

void Escola::showRemoverInstrutorUI() {
	showVisualizaInstrutoresUI();

	unsigned int input;
	while (1) {
		try {
			cout << "> Insira o numero do instrutor que pretende remover:"
					<< endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, numInstrutores()));
			} else if (1 <= input && input <= numInstrutores())
				break;
			else
				throw(InputEsperadoEraInt(input, 1, numInstrutores()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, numInstrutores());
			e.what();
		}
	}

	instrutores.erase(instrutores.begin() + input - 1);
	saveSchoolData();

	cout << "* Instrutor removido com sucesso *" << endl;
	cout << "Prima <enter> para voltar ao menu inicial." << endl;
	cin.get();
}

bool menorNomeInstrutor(Instrutor *x1, Instrutor *x2) {
	return (x1->getNome() < x2->getNome());
}
bool menorNQualificacoes(Instrutor *x1, Instrutor *x2) {
	return (x1->numQualificacoes() < x2->numQualificacoes());
}
bool menorNAlunos(Instrutor *x1, Instrutor *x2) {
	return (x1->numAlunos() < x2->numAlunos());
}
bool menorNAulas(Instrutor *x1, Instrutor *x2) {
	return (x1->numAulas() < x2->numAulas());
}

void Escola::visualizaInstrutores(MetodoDeSortDeInstrutores metodo) {
	switch (metodo) {
	case NOMEINSTRUTOR:
		sort(ALL(instrutores), menorNomeInstrutor);
		break;
	case NQUALIFICACOES:
		sort(ALL(instrutores), menorNQualificacoes);
		break;
	case NALUNOS:
		sort(ALL(instrutores), menorNAlunos);
		break;
	case NAULAS:
		sort(ALL(instrutores), menorNAulas);
		break;
	}

	FOR(i, 0, numInstrutores())
	{
		cout << endl;
		cout << "> Instrutor " << i + 1 << ":" << endl;
		instrutores[i]->info();
	}

	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();
}

void Escola::showVisualizaAlunosUI() {
	try {
		if (numAlunos() == 0)
			throw ColecaoVazia("Alunos");

		cout << endl;
		cout << "----------------------" << endl;
		cout << "- Listagem de alunos -" << endl;
		cout << "----------------------" << endl;
		cout << "1. Nome" << endl;
		cout << "2. Numero de aulas marcadas" << endl;
		cout << endl;

		bool done = false;
		while (!done) {
			cout << "> Escolha o metodo de ordenacao da lista:" << endl;
			cout << "> ";
			char input;
			cin >> input;
			cin.ignore();

			done = true;
			switch (input) {
			case '1':
				visualizaAlunos(NOMEALUNO);
				break;
			case '2':
				visualizaAlunos(NAULASMARCADAS);
				break;
			default:
				done = false;
				break;
			}
		}
	} catch (ColecaoVazia &e) {
		e = ColecaoVazia("Alunos");
		e.what();
	}
}

void Escola::showAdicionarAlunoUI() {
	string nome;

	cout << endl;
	cout << "-------------------" << endl;
	cout << "- Adicionar Aluno -" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	cout << "Insira:" << endl;

	bool done = false;
	while (!done) {
		try {
			cout << "\to nome: ";
			cin >> nome;
			//processMatricula(matricula);
			break;
		} catch (MatriculaInvalida &e) {
			//e = MatriculaInvalida(matricula);
			//e.what();
		}
	}

	cout << endl;
	cout << "Tipo de carta de conducao:" << endl;
	cout << "\t1. Ligeiro" << endl;
	cout << "\t2. Pesado" << endl;
	cout << "\t3. Motociclo" << endl;
	cout << endl;

	int input;
	while (1) {
		try {
			cout << "> Insira o tipo de carta:" << endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, 3));
			} else if (1 <= input && input <= 3)
				break;
			else
				throw(InputEsperadoEraInt(input, 1, 3));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, 3);
			e.what();
		}
	}

	Aluno *temp;
	Viatura *viaturaUsual;
	switch (input) {
	case 1:
		viaturaUsual = getViaturaComMenosAlunos(LIGEIRO);
		temp = new Aluno(nome, LIGEIRO, viaturaUsual);
		break;
	case 2:
		viaturaUsual = getViaturaComMenosAlunos(PESADO);
		temp = new Aluno(nome, PESADO, viaturaUsual);
		break;
	case 3:
		viaturaUsual = getViaturaComMenosAlunos(MOTOCICLO);
		temp = new Aluno(nome, MOTOCICLO, viaturaUsual);
		break;
	}
	adicionaAluno(temp);

	cout << endl;
	cout << "* Aluno adicionado com sucesso *" << endl;

	saveSchoolData();
	showManutencaoAlunosUI();
}

void Escola::showEditarAlunoUI() {

}

void Escola::showRemoverAlunoUI() {
	showVisualizaAlunosUI();

	unsigned int input;
	while (1) {
		try {
			cout << "> Insira o numero do aluno que pretende remover:" << endl;
			cout << "> ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, numAlunos()));
			} else if (1 <= input && input <= numAlunos())
				break;
			else
				throw(InputEsperadoEraInt(input, 1, numAlunos()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, numAlunos());
			e.what();
		}
	}

	alunos.erase(alunos.begin() + input - 1);
	saveSchoolData();

	cout << "* Aluno removido com sucesso *" << endl;
	cout << "Prima <enter> para voltar ao menu inicial." << endl;
	cin.get();
}

bool menorNomeAluno(Aluno *x1, Aluno *x2) {
	return (x1->getNome() < x2->getNome());
}

bool tipoCarta(Aluno *x1, Aluno *x2) {
	return (x1->getTipoDeCarta() < x2->getTipoDeCarta());
}

void Escola::visualizaAlunos(MetodoDeSortDeAlunos metodo) {
	switch (metodo) {
	case NOMEALUNO:
		sort(ALL(alunos), menorNomeAluno);
		break;
	case NAULASMARCADAS:
		sort(ALL(alunos), tipoCarta);
		break;
	}

	FOR(i, 0, numAlunos())
	{
		cout << endl;
		cout << "> Aluno " << i + 1 << ":" << endl;
		alunos[i]->info();
	}

	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();
}

void Escola::showVisualizaAulasUI() {
	try {
		if (numAulas() == 0)
			throw ColecaoVazia("Aulas");

		cout << endl;
		cout << "---------------------" << endl;
		cout << "- Listagem de aulas -" << endl;
		cout << "---------------------" << endl;
		cout << "1. Data da aula" << endl;
		cout << "2. Nome de aluno" << endl;
		cout << "3. Nome de instrutor" << endl;
		cout << "4. Tipo de viatura" << endl;
		cout << endl;

		bool done = false;
		while (!done) {
			cout << "> Escolha o metodo de ordenacao da lista:" << endl;
			cout << "> ";
			char input;
			cin >> input;
			cin.ignore();

			done = true;
			switch (input) {
			case '1':
				visualizaAulas(DATA);
				break;
			case '2':
				visualizaAulas(ALUNO);
				break;
			case '3':
				visualizaAulas(INSTRUTOR);
				break;
			case '4':
				visualizaAulas(TIPOVIATURA);
				break;
			default:
				done = false;
				break;
			}
		}
	} catch (ColecaoVazia &e) {
		e = ColecaoVazia("Aulas");
		e.what();
	}
}

void Escola::showMarcarAulaUI() {
	string data;
	int dia, mes, ano;
	int hora, duracao;
	string nomeAluno;
	TipoCartaConducao tipoViatura;
	Aluno *aluno;
	Instrutor *instrutor;
	Viatura *viatura;

	cout << endl;
	cout << "---------------" << endl;
	cout << "- Marcar Aula -" << endl;
	cout << "---------------" << endl;
	cout << endl;
	cout << "Insira:" << endl;

	int input;
	while (1) {
		try {
			cout << "\tdia: ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, 31));
			} else if (1 <= input && input <= 31)
				break;
			else
				throw(InputEsperadoEraInt(input, 1, 31));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, 31);
			e.what();
		}
	}
	dia = input;
	while (1) {
		try {
			cout << "\tmes: ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, 12));
			} else if (1 <= input && input <= 12)
				break;
			else
				throw(InputEsperadoEraInt(input, 1, 12));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, 12);
			e.what();
		}
	}
	mes = input;
	while (1) {
		try {
			cout << "\tano: ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, getAnoActual()));
			} else if (1 <= input && input <= getAnoActual())
				break;
			else
				throw(InputEsperadoEraInt(input, 1, getAnoActual()));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, getAnoActual());
			e.what();
		}
	}
	ano = input;
	while (1) {
		try {
			cout << "\tduracao: ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, 1, 2));
			} else if (1 <= input && input <= 2)
				break;
			else
				throw(InputEsperadoEraInt(input, 1, 2));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, 1, 2);
			e.what();
		}
	}
	duracao = input;
	while (1) {
		try {
			cout << "\thora: ";
			cin >> input;
			cin.ignore();

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');

				throw(InputEsperadoEraInt(input, abertura, fecho - duracao));
			} else if (abertura <= input && input <= fecho - duracao)
				break;
			else
				throw(InputEsperadoEraInt(input, abertura, fecho - duracao));
		} catch (InputEsperadoEraInt &e) {
			e = InputEsperadoEraInt(input, abertura, fecho - duracao);
			e.what();
		}
	}
	hora = input;

	// nome aluno
	cout << "\tnome do aluno: ";
	cin >> nomeAluno; cin.ignore();
	aluno = getAlunoChamado(nomeAluno);

	// tipo viatura
	tipoViatura = aluno->getTipoDeCarta();

	// instrutor
	instrutor = getInstrutorComMenosAlunos(tipoViatura);

	// viatura usual
	viatura = getViaturaComMenosAlunos(tipoViatura);

	// a processar data
	stringstream ss;
	ss << dia << "/" << mes << "/" << ano;
	data = ss.str();

	Aula *temp;
	temp = new Aula(getDateFromString(data), hora, duracao, aluno, instrutor, viatura);
	marcaAula(temp);

	cout << endl;
	cout << "* Aula marcada com sucesso *" << endl;

	saveSchoolData();
	showManutencaoAulasUI();
}

void Escola::showEditarAulaUI() {

}

void Escola::showDesmarcarAulaUI() {

}

bool menorData(Aula *x1, Aula *x2) {
	struct tm d1 = x1->getData(), d2 = x2->getData();
	int sum1 = d1.tm_mday + d1.tm_mon + d1.tm_year;
	int sum2 = d2.tm_mday + d2.tm_mon + d2.tm_year;

	return sum1 < sum2;
}

bool menorAluno(Aula *x1, Aula *x2) {
	return (x1->getAluno().getNome() < x2->getAluno().getNome());
}

bool menorInstrutor(Aula *x1, Aula *x2) {
	return (x1->getInstrutor().getNome() < x2->getInstrutor().getNome());
}

bool tipoViatura(Aula *x1, Aula *x2) {
	return (x1->getTipoViatura() < x2->getTipoViatura());
}

void Escola::visualizaAulas(MetodoDeSortDeAulas metodo) {
	switch (metodo) {
	case DATA:
		sort(ALL(aulas), menorData);
		break;
	case ALUNO:
		sort(ALL(aulas), menorAluno);
		break;
	case INSTRUTOR:
		sort(ALL(aulas), menorInstrutor);
		break;
	case TIPOVIATURA:
		sort(ALL(aulas), tipoViatura);
		break;
	}

	FOR(i, 0, numAlunos())
	{
		cout << endl;
		cout << "> Aula " << i + 1 << ":" << endl;
		aulas[i]->info();
	}

	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();
}

Viatura *Escola::getViaturaComMatricula(string Matricula) {
	FOR(i, 0, numViaturas()) {
		if (viaturas[i]->getMatricula().compare(Matricula))
			return viaturas[i];
	}
	return NULL;
}

Aluno *Escola::getAlunoChamado(string nome) {
	FOR(i, 0, numAlunos()) {
		if (alunos[i]->getNome().compare(nome) == 0)
			return alunos[i];
	}
	//TODO exception here
	return NULL;
}

Instrutor *Escola::getInstrutorDoAluno(Aluno *aluno) {
	foreach(instrutores2, it)
	{
		FOR(i, 0, it->second.size())
		{
			if (aluno == it->second[i])
				return it->first;
		}
	}

	return NULL;
}

int Escola::numAlunosQueUsamAViatura(Viatura *viatura) {
	unsigned int counter = 0;

	FOR(i, 0, numAlunos())
	{
		if (viatura == alunos[i]->getViaturaUsual())
			counter++;
	}

	return counter;
}

int Escola::numAlunosQueTemAulasComInstrutor(Instrutor *instrutor) {
	unsigned int counter = 0;

	FOR(i, 0, numAlunos())
	{
		if (instrutor == getInstrutorDoAluno(alunos[i]))
			counter++;
	}

	return counter;
}

Viatura *Escola::getViaturaComMenosAlunos(TipoCartaConducao TipoViatura) {
	int min = -1, id = -1;
	FOR(i, 0, numViaturas())
	{
		if ((id == -1 && viaturas[i]->getTipo() == TipoViatura)
				|| (id != -1 && viaturas[i]->getTipo() == TipoViatura
						&& numAlunosQueUsamAViatura(viaturas[i]) < min)) {
			id = i;
			min = numAlunosQueUsamAViatura(viaturas[i]);
		}
	}
	return viaturas[id];
}

Instrutor *Escola::getInstrutorComMenosAlunos(TipoCartaConducao TipoViatura) {
	int id = -1, min = -1;
	FOR(i, 0, numInstrutores())
	{
		if ((id == -1 && instrutores[i]->isQualifiedFor(TipoViatura))
				|| (id != -1 && instrutores[i]->isQualifiedFor(TipoViatura)
						&& numAlunosQueTemAulasComInstrutor(instrutores[i]) < min)) {
			id = i;
			min = numAlunosQueTemAulasComInstrutor(instrutores[i]);
		}
	}
	return instrutores[id];
}

#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
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
	{
		; //printf("%s %d %s %s %s %d",);
	}

	// A guardar instrutores

	// A guardar alunos

	// A guardar aulas

	return 0;
}

int Escola::loadSchoolData() {
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "- A carregar dados da escola -" << endl;
	cout << "------------------------------" << endl;

	cout << "> A carregar viaturas... ";
	cout << "OK!" << endl;

	cout << "> A carregar instrutores... ";
	cout << "OK!" << endl;

	cout << "> A carregar alunos... ";
	cout << "OK!" << endl;

	cout << "> A carregar aulas... ";
	cout << "OK!" << endl;

	return 0;
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
					&& rename(oldNameEscolaAulas.c_str(), tempNameEscolaAulas.c_str()) == 0) {
				// a inserir novo nome para a escola
				cout << "> Nome novo da escola: ";
				cin.clear();
				getline(cin, nomeNovo);
				unparsedCopy = nomeNovo;
				parseFilename(nomeNovo);

				cout << "A alterar o nome da escola... ";
				if(fileExists(nomeNovo)) {
					cout << endl;
					cout << "* Erro ao alterar o nome da escola *" << endl;
					cout << "Ja existe uma escola com o novo nome que escolheu." << endl;
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
					rename(tempNameEscolaAulas.c_str(), newNameEscolaAulas.c_str());

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
				cout << "* Error deleting file! *" << endl;
			} else {
				cout << "OK!" << endl;
				cout << "* School deleted successfully *" << endl;
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
			showManutencaoViaturas();
			break;
		case '2':
			showManutencaoInstrutores();
			break;
		case '3':
			showManutencaoAlunos();
			break;
		case '4':
			showManutencaoAulas();
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

void Escola::showManutencaoViaturas() {
	char input;

	bool done = false;
	while (!done) {
		cout << endl;
		cout << "--------------------------" << endl;
		cout << "- Manutencao de Viaturas -" << endl;
		cout << "--------------------------" << endl;
		cout << "1. Visualizar viaturas" << endl;
		cout << "2. Adicionar viatura" << endl;
		cout << "3. Alterar viatura" << endl;
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
			visualizaViaturas();
			break;
		case '2':
			showAdicionarViaturaUI();
			break;
		case '3':
			break;
		case '4':
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

void Escola::showAdicionarViaturaUI() {
	string matricula;
	int anoFabrico;
	string marca;
	int cargaMaxima;
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
			showManutencaoViaturas();
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

	if (input == '2') {
		cout << "\ta carga maxima: ";
		cin >> cargaMaxima;
	}

	Viatura *temp;
	switch (input) {
	case '1':
		temp = new Ligeiro(matricula, anoFabrico, marca, periodicidade);
		break;
	case '2':
		temp = new Pesado(matricula, anoFabrico, marca, periodicidade,
				cargaMaxima);
		break;
	case '3':
		temp = new Motociclo(matricula, anoFabrico, marca, periodicidade);
		break;
	}
	adicionaViatura(temp);

	cout << endl;
	cout << "* Viatura adicionada com sucesso *" << endl;
	showManutencaoViaturas();
}

void Escola::showManutencaoInstrutores() {

}

void Escola::showManutencaoAlunos() {

}

void Escola::showManutencaoAulas() {

}

void Escola::visualizaViaturas() {
	cout << endl;
	cout << "------------------------" << endl;
	cout << "- Listagem de viaturas -" << endl;
	cout << "------------------------" << endl;
	int size = viaturas.size();
	if (size == 0)
		cout << ".: Nao existe nenhuma viatura :." << endl;
	for (int i = 0; i < size; i++) {
		cout << endl;
		cout << "> Viatura " << i + 1 << ":" << endl;
		viaturas[i]->info();
	}
	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();
}

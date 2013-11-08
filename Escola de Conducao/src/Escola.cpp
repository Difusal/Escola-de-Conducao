#include <fstream>
#include "Escola.h"
#include "Utilities.h"
#include "Exceptions.h"

Escola::Escola() {
	// TODO Auto-generated constructor stub

}

Escola::~Escola() {
	// TODO Auto-generated destructor stub
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
		case 'x':
			cout << "A terminar programa..." << endl;
			break;
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
		if(fileExists(input)) {
			loadSchoolData();
			showMainMenu();
			done = true;
			break;
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
			break;
		}

		parseFilename(input);
		if (fileExists(input)) {
			cout << "Erro:\tEscola ja existente." << endl;
			cout << "\tSe pretende retornar ao menu inicial" << endl;
			cout << "\tinsira o caracter \'.\' como nome da escola." << endl;
		} else {
			int abertura, fecho;
			cout << "> Insira o horario da escola:" << endl;

			while (1) {
				try {
					cout << "\tAbertura: ";
					cin >> abertura; cin.ignore();

					if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');

						throw(HoraInvalida(abertura));
					} else if(0 <= abertura && abertura <= 23)
						break;
					else throw(HoraInvalida(abertura));
				} catch (HoraInvalida &e) {
					e = HoraInvalida(abertura);
					e.what();
				}
			}
			while (1) {
				try {
					cout << "\tFecho: ";
					cin >> fecho; cin.ignore();

					if (cin.fail()) {
						cin.clear();
						cin.ignore(10000, '\n');

						throw(HoraInvalida(fecho));
					} else if(0 <= fecho && fecho <= 23)
						break;
					else throw(HoraInvalida(fecho));
				} catch (HoraInvalida &e) {
					e = HoraInvalida(fecho);
					e.what();
				}
			}

			showMainMenu();
			done = true;
			break;
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
			break;
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
		cin >> input; cin.ignore();

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
			break;
		case 'x':
			showManutencaoViaturas();
			break;
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
			cout << "\ta matricula: "; cin >> matricula;
			processMatricula(matricula);
			break;
		} catch (MatriculaInvalida &e) {
			e = MatriculaInvalida(matricula);
			e.what();
		}
	}

	cout << "\to ano de fabrico: "; cin >> anoFabrico;
	cout << "\ta marca: "; cin >> marca;
	if (input == '2') {
		cout << "\ta carga maxima: "; cin >> cargaMaxima;
	}

	Viatura *temp;
	switch (input) {
	case '1':
		temp = new Ligeiro(matricula, anoFabrico, marca);
		break;
	case '2':
		temp = new Pesado(matricula, anoFabrico, marca, cargaMaxima);
		break;
	case '3':
		temp = new Motociclo(matricula, anoFabrico, marca);
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
		cout << "> Viatura " << i+1 << ":" << endl;
		viaturas[i]->info();
	}
	cout << endl;
	cout << "Pressione enter para continuar... ";
	cin.get();
}

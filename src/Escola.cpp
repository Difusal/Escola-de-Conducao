#include "Escola.h"

Escola::Escola() {
	// TODO Auto-generated constructor stub

}

Escola::~Escola() {
	// TODO Auto-generated destructor stub
}


void Escola::showMainMenu() {
	char input;

	bool done = false;
	while (!done) {
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
		cout << "X. Terminar Programa" << endl;
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
		cout << "3. Remover viatura" << endl;
		cout << endl;
		cout << "X. Voltar ao menu inicial" << endl;
		cout << endl;
		cout << "> Escolha o que pretende fazer:" << endl;
		cout << "> ";
		cin >> input;

		input = tolower(input);
		done = true;
		switch (input) {
		case '1':
			break;
		case '2':
			showAdicionarViaturaUI();
			break;
		case '3':
			break;
		case 'x':
			showMainMenu();
			break;
		default:
			done = false;
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
	cout << "\ta matricula: "; cin >> matricula;
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

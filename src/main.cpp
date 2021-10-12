// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Outubro 2021

#include "../include/siga.h"

ostream & operator<<(ostream &, Aluno);

inline void printarMenu()
{
	cout << "--------------------------------------" << endl;
	cout << "[ MENU ]\n" << endl;	
	cout << "[1] Listar alunos" << endl;	
	cout << "[2] Listar disciplinas" << endl;	
	cout << "[3] Registrar aluno" << endl;	
	cout << "[4] Registrar disciplina" << endl;	
	cout << "[5] Realizar pedido de inscricao" << endl;	
	cout << "[6] Processar pedidos de inscricao" << endl;	
	cout << "\n[0] sair\n" << endl;
	cout << "Escolha uma operacao: ";
};

inline void pressEnter()
{
	string aux;
	cout << "Aperte [ENTER] para prosseguir. "<< endl;
	getline(cin, aux);
}

inline int recebeStringDevolveInteiro()
{
	bool stringValida = false;
	int opInt;
	string opStr;

	while (!stringValida)
	{
		try
		{
			getline(cin, opStr);
			opInt = stoi(opStr);
			stringValida = true;
		}
		catch (const invalid_argument& ia)
		{
			cout << "Argumento invalido." <<
			" Insira um numero inteiro dentro das opcoes listadas." << endl;
			cout << "what(): " << ia.what() << endl;
			cout << "Tente novamente: "; 
		}
	}	
		
	return opInt;
}

int main()
{

	bool executarPrograma = true;
	string opStr;
	int opInt;
	SIGA siga;

	Aluno a1("Artur", "Amaral", "119057968", ENG_ELETRONICA, 6.2, 5);
	Aluno a2("Bruno", "Ramos", "119057968", ENG_ELETRONICA, 6.2, 5);
	Aluno a3("Gabriel", "Peroba", "119057968", ENG_AUTOMACAO, 6.2, 5);
	Aluno a4("Carlos", "Eduardo", "119057968", ENG_ELETRICA, 6.2, 5);
	Aluno a5("Breno", "Miranda", "119057968", ENG_COMPUTACAO, 6.2, 5);

	siga.registrarAluno(a1);
	siga.registrarAluno(a2);
	siga.registrarAluno(a3);
	siga.registrarAluno(a4);
	siga.registrarAluno(a5);	

	Disciplina d1("Arquitetura de computadores", "EEL570", ENG_ELETRONICA, 5, 45);
	Disciplina d2("Algoritmos e estruturas de dados", "EEL480", ENG_COMPUTACAO, 5, 45);
	Disciplina d3("Circuitos Eletricos I", "EEL440", ENG_ELETRICA, 5, 45);
	Disciplina d4("Controle Linear I", "EEL570", ENG_AUTOMACAO, 5, 45);

	siga.registrarDisciplina(d1);
	siga.registrarDisciplina(d2);
	siga.registrarDisciplina(d3);
	siga.registrarDisciplina(d4);



	cout << "\n==============================" << endl;	
	cout << "========== SIGA APP ==========" << endl;	
	cout << "\n-> Simulador de inscrição em disciplinas." << endl;	
	cout << "\tProjeto final da disciplina \"Linguagens de programacao.\"\n" << endl;	
	cout << "==============================\n" << endl;	

	while (executarPrograma)
	{
		printarMenu();
		opInt = recebeStringDevolveInteiro();
		cout << "--------------------------------------" << endl;

		switch(opInt)
		{
			case 1:
				siga.listarAlunos();
				pressEnter();
				break;
			case 2:
				siga.listarDisciplinas();
				pressEnter();
				break;
			case 3:
				cout << "3" << endl;
				pressEnter();
				break;
			case 4:
				cout << "4" << endl;
				pressEnter();
				break;
			case 5:
				cout << "5" << endl;
				pressEnter();
				break;
			case 6:
				cout << "6" << endl;
				pressEnter();
				break;
			case 0:
				executarPrograma = false;
				break;
			default:
				cout << "Esta entrada nao representa uma operacao." << endl;
				cout << "Tente novamente." << endl;
				pressEnter();
				break;
		}
	}


	return 0;
}

// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Outubro 2021

#include "../include/siga.h"

//-----------------------------------
// Funções utilitárias para a main
//-----------------------------------

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

//---------
// Main
//---------

int main()
{

	bool executarPrograma = true;
	string opStr;
	int opInt;
	SIGA siga;
	pedido_t pedidoDeInscricao;

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
				siga.registrarAluno();
				pressEnter();
				break;

			case 4:
				siga.registrarDisciplina();
				pressEnter();			
				break;

			case 5:
/*
				cout << "5" << endl;
	
				cout << "PEDIDO DE INSCRICAO EM DISCIPLINA: " << endl;	

				cout << "DRE do solicitante: ";
				getline(cin, DRE);

				if (DRE.size() != COMPRIMENTO_DRE)
				{
					cout << "Comprimento do DRE invalido (correto: "<< COMPRIMENTO_DRE << ")." << endl;
					pressEnter();
					break;
				}


				if ( !(DRE.find_first_not_of("0123456789") == string::npos))
				{
					cout << "DRE contem caracteres nao numericos. " << endl;
					pressEnter();
					break;
				}

				if (!siga.alunoExistePorDRE(DRE))
				{
					cout << "Este DRE nao existe no sistema." << endl;	
				} 

				// Validacoes:
				// DRE contem apenas caracteres numericos;
				// DRE existe no siga

				cout << "Codigo da disciplina almejada: ";
				getline(cin, codigo);

				if (codigo.size() != COMPRIMENTO_CODIGO_DISCIPLINA)
				{
					cout << "Comprimento do codigo invalido (correto: "<< COMPRIMENTO_CODIGO_DISCIPLINA << ")." << endl;
					pressEnter();
					break;
				}
	
				if (!siga.disciplinaExistePorCodigo(codigo))
				{
					cout << "Este codigo de disciplina nao existe no sistema." << endl;	
				} 

				pedidoDeInscricao.DRE = DRE;
				pedidoDeInscricao.codigoDisciplina = codigo;

				siga.registrarPedido(pedidoDeInscricao);

				pressEnter();
*/
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

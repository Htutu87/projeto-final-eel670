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
	curso_t c;
	float CRAfloat;
	unsigned short periodoInt, numVagasInt;
	pedido_t pedidoDeInscricao;

	string nome, sobrenome, DRE, curso, CRA, periodo, codigo, numVagas;

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
			{
				// REGISTRAR ALUNO
				cout << "Insira os dados do aluno para registra-lo:"<< endl;
				cout << "Nome: ";
				getline(cin, nome);	

				if (nome.size() > MAX_COMPRIMENTO_NOME)
				{
					cout << "Comprimento do nome maior que o maximo permitido." << endl;
					pressEnter();
					break;
				}

				cout << "Sobrenome: ";	
				getline(cin, sobrenome);	
				
				if (sobrenome.size() > MAX_COMPRIMENTO_NOME)
				{
					cout << "Comprimento do sobrenome maior que o maximo permitido." << endl;
					pressEnter();
					break;	
				}

				cout << "DRE: ";	
				getline(cin, DRE);

				if (DRE.size() != COMPRIMENTO_DRE)
				{
					cout << "Comprimento do DRE invalido (correto: "<< COMPRIMENTO_DRE << ")." << endl;
					pressEnter();
					break;
				}

				cout << "Curso: " << endl;

				cout << "[0] ENGENHARIA ELETRICA" << endl;
				cout << "[1] ENGENHARIA ELETRONICA" << endl;
				cout << "[2] ENGENHARIA AUTOMACAO" << endl;
				cout << "[3] ENGENHARIA COMPUTACAO" << endl;
				
				cout << ">> ";
				getline(cin, curso);
				try
				{
					unsigned cursoInt;
					cursoInt = stoi(curso);
					if (cursoInt > NUM_CURSOS-1)
					{
						cout << "Entrada invalida." << endl;
					   	pressEnter();
						break;	
					}

					switch(cursoInt)
					{
						case 0:
							c = ENG_ELETRICA;
							break;
						case 1:
							c = ENG_ELETRONICA; 
							break;
						case 2:
							c = ENG_AUTOMACAO; 
							break;
						case 3:
							c = ENG_COMPUTACAO; 
							break;
					}

				}
				catch (const invalid_argument& ia)
				{
					cout << "Argumento invalido." << endl;
					cout << "what(): " << ia.what() << endl;
					pressEnter();
					break;
				}

				cout << "CRA: ";
				getline(cin, CRA);

				try
				{
					CRAfloat = stof(CRA);
					if (CRAfloat > 10.0 || CRAfloat < 0.0)
					{
						cout << "Entrada invalida." << endl;
					   	pressEnter();
						break;	
					}
						
				}		
				catch (const invalid_argument& ia)
				{
					cout << "Argumento invalido." << endl;
					cout << "what(): " << ia.what() << endl;
					pressEnter();
					break;
				}
	
				cout << "Periodo: ";	
				getline(cin, periodo);	
				
				try
				{
					periodoInt = stoi(periodo);
					if (periodoInt > NUM_PERIODOS_GRADUACAO)
					{
						cout << "Entrada invalida." << endl;
					   	pressEnter();
						break;	
					}
				}
				catch (const invalid_argument& ia)
				{
					cout << "Argumento invalido." << endl;
					cout << "what(): " << ia.what() << endl;
					pressEnter();
					break;
				}

				Aluno a(nome, sobrenome, DRE, c, CRAfloat, periodoInt);
				siga.registrarAluno(a);
				pressEnter();
		}
				break;

			case 4:
			{
				//REGISTRAR DISCIPLINA
				

				cout << "Insira os dados da disciplina para registra-la:"<< endl;
				cout << "Nome: ";
				getline(cin, nome);	

				if (nome.size() > MAX_COMPRIMENTO_DISCIPLINA)
				{
					cout << "Comprimento do nome maior que o maximo permitido." << endl;
					pressEnter();
					break;
				}

				cout << "Codigo: ";	
				getline(cin, codigo);

				if (codigo.size() != COMPRIMENTO_CODIGO_DISCIPLINA)
				{
					cout << "Comprimento do codigo invalido (correto: "<< COMPRIMENTO_CODIGO_DISCIPLINA << ")." << endl;
					pressEnter();
					break;
				}

				cout << "Curso: " << endl;

				cout << "[0] ENGENHARIA ELETRICA" << endl;
				cout << "[1] ENGENHARIA ELETRONICA" << endl;
				cout << "[2] ENGENHARIA AUTOMACAO" << endl;
				cout << "[3] ENGENHARIA COMPUTACAO" << endl;
				
				cout << ">> ";
				getline(cin, curso);
				try
				{
					unsigned cursoInt;
					cursoInt = stoi(curso);
					if (cursoInt > NUM_CURSOS-1)
					{
						cout << "Entrada invalida." << endl;
					   	pressEnter();
						break;	
					}

					switch(cursoInt)
					{
						case 0:
							c = ENG_ELETRICA;
							break;
						case 1:
							c = ENG_ELETRONICA; 
							break;
						case 2:
							c = ENG_AUTOMACAO; 
							break;
						case 3:
							c = ENG_COMPUTACAO; 
							break;
					}
				}
				catch (const invalid_argument& ia)
				{
					cout << "Argumento invalido." << endl;
					cout << "what(): " << ia.what() << endl;
					pressEnter();
					break;
				}
	
				cout << "Periodo: ";	
				getline(cin, periodo);	
				
				try
				{
					periodoInt = stoi(periodo);
					if (periodoInt > NUM_PERIODOS_GRADUACAO)
					{
						cout << "Entrada invalida." << endl;
					   	pressEnter();
						break;	
					}
				}
				catch (const invalid_argument& ia)
				{
					cout << "Argumento invalido." << endl;
					cout << "what(): " << ia.what() << endl;
					pressEnter();
					break;
				}

				cout << "Numero de vagas: ";
				getline(cin, numVagas);

				try
				{
					numVagasInt = stoi(numVagas);
					if (numVagasInt > MAX_NUM_VAGAS || numVagasInt < MIN_NUM_VAGAS)
					{
						cout << "Entrada invalida." << endl;
					   	pressEnter();
						break;	
					}
				}
				catch (const invalid_argument& ia)
				{
					cout << "Argumento invalido." << endl;
					cout << "what(): " << ia.what() << endl;
					pressEnter();
					break;
				}
	
				Disciplina d(nome, codigo, c, periodoInt, numVagasInt);
				siga.registrarDisciplina(d);

				pressEnter();
			}
				break;
			case 5:

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

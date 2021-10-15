// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/siga.h"

SIGA::SIGA()
{
	#ifdef _DEBUG_
	cout << "_DEBUG_ defined." << endl;
	Aluno a1("Artur", "Amaral", "119057968", ENG_ELETRONICA, 6.2, 5);
	alunos.push_back(a1);
	Aluno a2("Bruno", "Ramos", "119057968", ENG_ELETRONICA, 6.2, 5);
	alunos.push_back(a2);
	Aluno a3("Gabriel", "Peroba", "119057968", ENG_AUTOMACAO, 6.2, 5);
	alunos.push_back(a3);
	Aluno a4("Carlos", "Eduardo", "119057968", ENG_ELETRICA, 6.2, 5);
	alunos.push_back(a4);
	Aluno a5("Breno", "Miranda", "119057968", ENG_COMPUTACAO, 6.2, 5);
	alunos.push_back(a5);

	Disciplina d1("Arquitetura de computadores", "EEL570", ENG_ELETRONICA, 5, 45);
	disciplinas.push_back(d1);
	Disciplina d2("Algoritmos e estruturas de dados", "EEL480", ENG_COMPUTACAO, 5, 45);
	disciplinas.push_back(d2);
	Disciplina d3("Circuitos Eletricos I", "EEL440", ENG_ELETRICA, 5, 45);
	disciplinas.push_back(d3);
	Disciplina d4("Controle Linear I", "EEL570", ENG_AUTOMACAO, 5, 45);
	disciplinas.push_back(d4);
	#endif
}

// Esse método pode ser uma Query no banco de dados.

void SIGA::listarAlunos()
{
	cout << setw(15) << "NOME"
	   	<< setw(15) << "SOBRENOME"
		<< setw(12) << "DRE"
		<< setw(20) << "CURSO"
		<< setw(6) << "CRA"
		<< setw(10) << "PERIODO" << endl;

	for (Aluno aluno:alunos)
	{
		cout << aluno;
	}
}

void SIGA::listarDisciplinas()
{
	cout << setw(35) << "NOME"
	   	<< setw(8) << "CODIGO"
		<< setw(20) << "CURSO"
		<< setw(10) << "PERIODO"
	   	<< setw(10) << "VAGAS" << endl;

	for (Disciplina disciplina:disciplinas)
	{
		cout << disciplina;
	}
}

void SIGA::registrarAluno()
{
	string nome, sobrenome, DRE, cursoStr, CRAStr, periodoStr;
	float CRAFloat;
	unsigned periodoInt;
	unsigned cursoInt;
	curso_t curso;

	cout << "Insira os dados do aluno para registra-lo:"<< endl;
	cout << "Nome: ";
	getline(cin, nome);	

	if (nome.size() > MAX_COMPRIMENTO_NOME)
	{
		cout << "Comprimento do nome maior que o maximo permitido." << endl;
		return;
	}

	cout << "Sobrenome: ";	
	getline(cin, sobrenome);	

	if (sobrenome.size() > MAX_COMPRIMENTO_NOME)
	{
		cout << "Comprimento do sobrenome maior que o maximo permitido." << endl;
		return;	
	}

	cout << "DRE: ";	
	getline(cin, DRE);

	if (DRE.size() != COMPRIMENTO_DRE)
	{
		cout << "Comprimento do DRE invalido (correto: "<< COMPRIMENTO_DRE << ")." << endl;
		return;
	}
	else 
	{
		if ( !(DRE.find_first_not_of("0123456789") == string::npos))
		{
			cout << "DRE contem caracteres nao numericos. " << endl;
			return;
		}
	}

	cout << "Curso: " << endl;

	cout << "[0] ENGENHARIA ELETRICA" << endl;
	cout << "[1] ENGENHARIA ELETRONICA" << endl;
	cout << "[2] ENGENHARIA AUTOMACAO" << endl;
	cout << "[3] ENGENHARIA COMPUTACAO" << endl;

	cout << ">> ";
	getline(cin, cursoStr);
	try
	{
		cursoInt = stoi(cursoStr);
		if (cursoInt > NUM_CURSOS-1)
		{
			cout << "Entrada invalida." << endl;
			
			return;	
		}

		switch(cursoInt)
		{
			case 0:
				curso = ENG_ELETRICA;
				break;
			case 1:
				curso = ENG_ELETRONICA; 
				break;
			case 2:
				curso = ENG_AUTOMACAO; 
				break;
			case 3:
				curso = ENG_COMPUTACAO; 
				break;
		}

	}
	catch (const invalid_argument& ia)
	{
		cout << "Argumento invalido." << endl;
		cout << "what(): " << ia.what() << endl;
		
		return;
	}

	cout << "CRA: ";
	getline(cin, CRAStr);

	try
	{
		CRAFloat = stof(CRAStr);
		if (CRAFloat > 10.0 || CRAFloat < 0.0)
		{
			cout << "Entrada invalida." << endl;
			
			return;	
		}
			
	}		
	catch (const invalid_argument& ia)
	{
		cout << "Argumento invalido." << endl;
		cout << "what(): " << ia.what() << endl;
		
		return;
	}

	cout << "Periodo: ";	
	getline(cin, periodoStr);	

	try
	{
		periodoInt = stoi(periodoStr);
		if (periodoInt > NUM_PERIODOS_GRADUACAO)
		{
			cout << "Entrada invalida." << endl;
			
			return;	
		}
	}
	catch (const invalid_argument& ia)
	{
		cout << "Argumento invalido." << endl;
		cout << "what(): " << ia.what() << endl;
		
		return;
	}

	Aluno a(nome, sobrenome, DRE, curso, CRAFloat, periodoInt);

	alunos.push_back(a);
}

void SIGA::registrarDisciplina()
{

	string nome, codigo, cursoStr, periodoStr, numVagasStr;
	int cursoInt;
	unsigned periodoInt, numVagasInt;
	curso_t curso;

	cout << "Insira os dados da disciplina para registra-la:"<< endl;
	cout << "Nome: ";
	getline(cin, nome);	

	if (nome.size() > MAX_COMPRIMENTO_DISCIPLINA)
	{
		cout << "Comprimento do nome maior que o maximo permitido." << endl;
		
		return;
	}

	cout << "Codigo: ";	
	getline(cin, codigo);

	if (codigo.size() != COMPRIMENTO_CODIGO_DISCIPLINA)
	{
		cout << "Comprimento do codigo invalido (correto: "<< COMPRIMENTO_CODIGO_DISCIPLINA << ")." << endl;
		
		return;
	}

	cout << "Curso: " << endl;

	cout << "[0] ENGENHARIA ELETRICA" << endl;
	cout << "[1] ENGENHARIA ELETRONICA" << endl;
	cout << "[2] ENGENHARIA AUTOMACAO" << endl;
	cout << "[3] ENGENHARIA COMPUTACAO" << endl;

	cout << ">> ";
	getline(cin, cursoStr);
	try
	{
		cursoInt = stoi(cursoStr);
		if (cursoInt > NUM_CURSOS-1)
		{
			cout << "Entrada invalida." << endl;
			
			return;	
		}

		switch(cursoInt)
		{
			case 0:
				curso = ENG_ELETRICA;
				break;
			case 1:
				curso = ENG_ELETRONICA; 
				break;
			case 2:
				curso = ENG_AUTOMACAO; 
				break;
			case 3:
				curso = ENG_COMPUTACAO; 
				break;
		}
	}
	catch (const invalid_argument& ia)
	{
		cout << "Argumento invalido." << endl;
		cout << "what(): " << ia.what() << endl;
		
		return;
	}

	cout << "Periodo: ";	
	getline(cin, periodoStr);	

	try
	{
		periodoInt = stoi(periodoStr);
		if (periodoInt > NUM_PERIODOS_GRADUACAO)
		{
			cout << "Entrada invalida." << endl;
			
			return;	
		}
	}
	catch (const invalid_argument& ia)
	{
		cout << "Argumento invalido." << endl;
		cout << "what(): " << ia.what() << endl;
		
		return;
	}

	cout << "Numero de vagas: ";
	getline(cin, numVagasStr);

	try
	{
		numVagasInt = stoi(numVagasStr);
		if (numVagasInt > MAX_NUM_VAGAS || numVagasInt < MIN_NUM_VAGAS)
		{
			cout << "Entrada invalida." << endl;
			
			return;	
		}
	}
	catch (const invalid_argument& ia)
	{
		cout << "Argumento invalido." << endl;
		cout << "what(): " << ia.what() << endl;
		
		return;
	}

	Disciplina d(nome, codigo, curso, periodoInt, numVagasInt);
	
	disciplinas.push_back(d);
}

void SIGA::registrarPedido(pedido_t _p)
{
	pedidosPendentes.push_back(_p);
}

bool SIGA::alunoExistePorDRE(string _DRE)
{
	// Essa funcao assume que o DRE recebido ja foi validado.
	bool alunoExiste = false;

	for (Aluno aluno:alunos)
		if (aluno.getDRE() == _DRE)
			alunoExiste = true;
	
	return alunoExiste;
}

bool SIGA::disciplinaExistePorCodigo(string _codigo)
{
	// Essa funcao assume que o DRE recebido ja foi validado.
	bool disciplinaExiste = false;

	for (Disciplina disciplina:disciplinas)
		if (disciplina.getCodigo() == _codigo)
			disciplinaExiste = true;
	
	return disciplinaExiste;
}


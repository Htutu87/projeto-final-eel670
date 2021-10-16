// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

// OBS:
// Ao fim dos métodos de registro, eu passo o objeto em sim como argumento para o push_back.
// Provavelmente o que é adicionado ao vetor membro é uma cópia do objeto criado aqui. 
// Tem problema? Ele só será acessado, de qualquer forma. Se der ruim, alterar para passar
// o endereço de memória (Ao fim das 3 funções de registro - aluno, disciplina, pedido).

#include "../include/siga.h"

SIGA::SIGA()
{
	#ifdef _DEBUG_
	cout << "_DEBUG_ defined." << endl;
	Aluno a1("Artur", "Amaral", "119057968", ENG_ELETRONICA, 6.2, 5);
	alunos.push_back(a1);
	Aluno a2("Bruno", "Ramos", "119057969", ENG_ELETRONICA, 6.2, 5);
	alunos.push_back(a2);
	Aluno a3("Gabriel", "Peroba", "119057970", ENG_AUTOMACAO, 6.2, 5);
	alunos.push_back(a3);
	Aluno a4("Carlos", "Eduardo", "119057971", ENG_ELETRICA, 6.2, 5);
	alunos.push_back(a4);
	Aluno a5("Breno", "Miranda", "119057972", ENG_COMPUTACAO, 6.2, 5);
	alunos.push_back(a5);

	Disciplina d1("Arquitetura de computadores", "EEL570", ENG_ELETRONICA, 5, 45);
	disciplinas.push_back(d1);
	Disciplina d2("Algoritmos e estruturas de dados", "EEL480", ENG_COMPUTACAO, 5, 45);
	disciplinas.push_back(d2);
	Disciplina d3("Circuitos Eletricos I", "EEL440", ENG_ELETRICA, 5, 45);
	disciplinas.push_back(d3);
	Disciplina d4("Controle Linear I", "EEL580", ENG_AUTOMACAO, 5, 45);
	disciplinas.push_back(d4);
	/*
	disciplinas[0].alunosInscritos.push_back(a1);
	disciplinas[0].alunosInscritos.push_back(a2);
	disciplinas[0].alunosInscritos.push_back(a3);
	*/
	#endif
}

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
	   	<< setw(10) << "VAGAS"
		<< setw(10) << "INSCRITOS" << endl;

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

void SIGA::registrarPedido()
{
	string DRE, codigo;
	pedido_t pedidoDeInscricao;

	cout << "PEDIDO DE INSCRICAO EM DISCIPLINA: " << endl;	

	cout << "DRE do solicitante: ";
	getline(cin, DRE);

	if (DRE.size() != COMPRIMENTO_DRE)
	{
		cout << "Comprimento do DRE invalido (correto: "<< COMPRIMENTO_DRE << ")." << endl;
		return;
	}


	if ( !(DRE.find_first_not_of("0123456789") == string::npos))
	{
		cout << "DRE contem caracteres nao numericos. " << endl;
		return;
	}

	if (!alunoExistePorDRE(DRE))
	{
		cout << "Este DRE nao existe no sistema." << endl;
		return;
	} 

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

	cout << "Codigo da disciplina almejada: ";
	getline(cin, codigo);

	if (codigo.size() != COMPRIMENTO_CODIGO_DISCIPLINA)
	{
		cout << "Comprimento do codigo invalido (correto: "<< COMPRIMENTO_CODIGO_DISCIPLINA << ")." << endl;
		return;
	}

	if (!disciplinaExistePorCodigo(codigo))
	{
		cout << "Este codigo de disciplina nao existe no sistema." << endl;	
		return;
	} 

	pedidoDeInscricao.DRE = DRE;
	pedidoDeInscricao.codigoDisciplina = codigo;

	pedidosPendentes.push_back(pedidoDeInscricao);
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

// Método para fins de depuração

void SIGA::printarDados()
{
	cout << "---- SIGA (Estado atual) ----" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "ALUNOS REGISTRADOS: " << endl;
	listarAlunos();
	cout << "----------------------------------------------------------" << endl;
	cout << "DISCIPLINAS REGISTRADAS: " << endl;
	listarDisciplinas();
	cout << "----------------------------------------------------------" << endl;
	cout << "PEDIDOS DE INSCRICAO: " << endl;
	for (pedido_t & pedido:pedidosPendentes)
	{
		cout << "\tDRE " << pedido.DRE << " pediu disciplina " 
		<< pedido.codigoDisciplina << endl;
	}	
	cout << "----------------------------------------------------------" << endl;
}


void SIGA::recebeDreDevolveAluno(string _DRE, Aluno & alunoRef)
{
	for (unsigned i=0; i < alunos.size(); i++)
	{
		if(alunos[i].getDRE() == _DRE)
		{
			alunoRef = alunos[i];
			cout << "[DEBUG] Aluno encontrado por DRE (i =" << i << ")." << endl;
		}
	}
}

/*
void SIGA::recebeCodigoDevolveDisciplina(string _codigo, Disciplina & disciplinaRef)
{
	for (unsigned i=0; i < disciplinas.size(); i++)
	{
		if(disciplinas[i].getCodigo() == _codigo)
		{
			Aluno a = Aluno();
			Aluno & aRef = a;

			disciplinaRef = disciplinas[i];
			disciplinaRef.inscreverAluno(aRef);
			cout << "[DEBUG] &disciplina (funcaoInterna()): ";
			cout << &disciplinas[i] << endl;
			cout << disciplinas[i];
			cout << "[DEBUG] Disciplina encontrada por codigo." << endl;
		}
	}
	cout << "[D] DEBUG" << endl;
}*/

void SIGA::processarPedidos()
{
	cout << "---\nPROCESSANDO PEDIDOS:" << endl;

	// AQUI ESTÁ O PROBLEMA, ESTOU CRIANDO ELAS LOCALMENTE.

	Aluno a = Aluno();
	Aluno & alunoRef = a;

	while(pedidosPendentes.size() != 0)
	{
		//recebeDreDevolveAluno(pedidosPendentes.back().DRE, alunoRef);
		//cout << "ALUNO ENCONTRADO: " << alunoRef.getNome() << endl;

		for (unsigned i = 0; i < alunos.size(); i++)
			if(alunos[i].getDRE() == pedidosPendentes.back().DRE)
				alunoRef = alunos[i];

		for (unsigned i = 0; i < disciplinas.size(); i++)
			if (disciplinas[i].getCodigo() == pedidosPendentes.back().codigoDisciplina)
				disciplinas[i].alunosInscritos.push_back(alunoRef);

		pedidosPendentes.pop_back();
	}

	cout << "---" << endl;
}

void SIGA::carregarDados()
{

}

void SIGA::salvarDados()
{
	
}
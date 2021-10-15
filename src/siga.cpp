// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/siga.h"

struct connection_details {
    const char *server, *user, *password, *database;
};

MYSQL* mysql_connection_setup(struct connection_details mysql_details)
{
    MYSQL *connection = mysql_init(NULL);

    if (!mysql_real_connect (connection, mysql_details.server,
                                            mysql_details.user,
                                            mysql_details.password,
                                            mysql_details.database, 0, NULL, 0 ) )
    {
        /*Se a conexão com a base de dados falhar, este trecho será executado.*/
        cout << "Connection error: " << mysql_error(connection) << endl;
        exit (1);
    }

    return connection;
}

MYSQL_RES* mysql_execute_query(MYSQL *connection, const char *sql_query)
{
    if (mysql_query (connection, sql_query) )
    {
        /*Se um erro ocorrer durante a query...*/
        cout << "MySQL query error: " << mysql_error(connection) << endl;
        exit(1);
    } 

    return mysql_use_result(connection);
}

SIGA::SIGA(){}
SIGA::~SIGA(){
	salvarDados();
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

void SIGA::registrarAluno(Aluno _a)
{
	alunos.push_back(_a);
}

void SIGA::registrarDisciplina(Disciplina _d)
{
	disciplinas.push_back(_d);
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



void SIGA::recebeDreRetornaAluno(string _DRE, Aluno * _alunoPtr)
{
	cout << "---\nrecebeDreRetornaAluno()" << endl;
	for (int i = 0; i < alunos.size(); i++)
		if (alunos[i].getDRE() == _DRE)
		{
			_alunoPtr = &alunos[i];
			return;
		}
	_alunoPtr = NULL;
}

void SIGA::recebeCodigoRetornaDisciplina(string _codigo, Disciplina * _disPtr)
{
	cout << "---\nrecebeCodigoRetornaDisciplina()" << endl;

	cout << "Codigo recebido: " << _codigo << endl;
	for (int i = 0; i < disciplinas.size(); i++)
	{	
		if (disciplinas[i].getCodigo() == _codigo)
		{
			_disPtr = &disciplinas[i];
			cout << "Retornando disciplina [add:" << &_disPtr << "]." << endl;
			return;
		}
	}
	//_disPtr = NULL;
}

void SIGA::carregarDados()
{
	

}

void SIGA::processarPedidos()
{
	cout << "---\nprocessarPedidos()" << endl;
	/*
	 * PROXIMOS PASSOS: Programar essa função que vai ler os
	 * pedidos pendentes e Dar um push_back no aluno para o
	 * vetor alunos inscritos das disciplinas. Após isso, a
	 * função carregar dados já deve conseguir montar umas querys
	 * bem feitas. 
	 * */

	/* PROBLEMA: O getAlunosInscritos está retornando um vetor vazio.
	 *
	 * Com certeza a inscrição e o requerimento pelo aluno se dão em
	 * duas instâncias distintas da classe Disciplina
	 *
	 * */

	pedido_t pedido;
	Aluno * aluno = new Aluno(); 
	Disciplina * disciplina = new Disciplina();

	while (pedidosPendentes.size() != 0)
	{

		pedido = pedidosPendentes.back();
		cout << "No pedidos: " << pedidosPendentes.size() << endl;
		cout << "Pedido.DRE: " << pedido.DRE << endl;
		cout << "Pedido.codigo: " << pedido.codigoDisciplina << endl;
		
		//cout << "Aluno address: " << aluno << endl;
		//cout << "Disciplina address: " << disciplina << endl;

		recebeDreRetornaAluno(pedido.DRE, aluno);
		recebeCodigoRetornaDisciplina(pedido.codigoDisciplina, disciplina);

		cout << "Voltando para processarPedidos()" << endl;

		//cout << "Aluno address: " << &aluno << endl;
		//cout << "Aluno nome: " << aluno.getCRA() << endl;
		
		//cout << "Disciplina address: " << disciplina << endl;

		cout << *aluno;

		if(&aluno != NULL && &disciplina != NULL)
		{
			cout << "Inscrevendo aluno na disciplina de endereco:" ;
		   	cout << &disciplina<< endl;
			disciplina->inscreverAluno(*aluno);
		}
		else
			cout << "Impossivel processar pedido." << endl;
		pedidosPendentes.pop_back();
	}
}

void SIGA::salvarDados()
{
	cout << "---\nsalvarDados()" << endl;

    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;

    struct connection_details mysqlDB;
    mysqlDB.server = "localhost";
    mysqlDB.user = "eel670";
    mysqlDB.password = "eel670";
    mysqlDB.database = "siga";

    con = mysql_connection_setup(mysqlDB);
/////////////////////////////
//
//
//
	string myQuery;
	string aux1, aux2;
	//vector <Aluno> & alunosInscritos = NULL;

	cout << "a" << endl;

	for (Disciplina & disciplina:disciplinas)
	{	
		cout << "b" << endl;
		cout << "--" << endl;
		cout << "[";
		cout << disciplina.getCodigo();
		cout << "] ";
		cout << disciplina.getNome() << endl;
		cout << "(add: ";
		cout << &disciplina;
		cout << ")." << endl;
		cout << "nO alunos inscritos: " << disciplina.getAlunosInscritos().size() << endl;
		cout << "--" << endl;

	}
/*
		for (int i = 0; i < alunosInscritos.size(); i++)
		{
			Aluno aluno = alunosInscritos[i];

			myQuery = "INSERT INTO siga." + disciplina.getNome() + " VALUES (";
			cout << i << endl;	
			myQuery.append("\"");
			myQuery.append(aluno.getNome());
			myQuery.append("\", ");

			myQuery.append("\"");
			myQuery.append(aluno.getSobrenome());
			myQuery.append("\", ");
			
			myQuery.append("\"");
			myQuery.append(aluno.getDRE());
			myQuery.append("\", ");

			myQuery.append(to_string(aluno.getCurso()));
			myQuery.append(", ");

			myQuery.append(to_string(aluno.getCRA()));
			myQuery.append(", ");

			myQuery.append(to_string(aluno.getPeriodo()));
			myQuery.append(");");
			
			cout << myQuery << endl;
		}
	}
*/
	//string myQuery = "INSERT INTO "

//INSERT INTO siga.calculoI (nome, sobrenome, DRE, curso, CRA, periodo) VALUES (Pedro, Ernesto, 118056079, 2, 7.0, 3);

/*
	string q1 = "SELECT * FROM siga.";
	string q2 = "calculoI;";
	string myQuery = q1 + q2;

    res = mysql_execute_query(con, myQuery.c_str());

    cout << "Displaying database output:\n" << endl;

    while ((row = mysql_fetch_row(res)) != NULL )
    {
        cout << "| " 
	<< row[0] << " | "
        << row[1] << " | "
        << row[2] << " | "
        << row[3] << " | "
        << row[4] << " | " 
	<< endl << endl;    
    }*/
/////////////////////////////////////q
    //mysql_free_result(res);
    mysql_close(con);
}

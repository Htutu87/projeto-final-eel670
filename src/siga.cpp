// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/siga.h"

SIGA::SIGA()
{


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


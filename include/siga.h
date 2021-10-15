// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef SIGA_H
#define SIGA_H

#include "disciplina.h" 

class SIGA {

	public:
		SIGA();
		void listarAlunos();
		void listarDisciplinas();
		void registrarAluno();
		void registrarDisciplina();	
		void registrarPedido();
		bool alunoExistePorDRE(string);
		bool disciplinaExistePorCodigo(string);	
		void printarDados();

	private:
		vector <Aluno> alunos;
		vector <Disciplina> disciplinas;
		vector <pedido_t> pedidosPendentes;
};

#endif

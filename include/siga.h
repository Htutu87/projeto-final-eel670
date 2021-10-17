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
		~SIGA();
		void listarAlunos();
		void listarDisciplinas();
		void registrarAluno();
		void registrarDisciplina();	
		void registrarPedido();	
		void printarDados();
		void processarPedidos();
		void limparBaseDeDados();
		void criarTabela(string);
		void deletarTabela(string);

	private:
		bool alunoExistePorDRE(string);
		bool disciplinaExistePorCodigo(string);
		void carregarDados();
		void salvarDados();

		vector <Aluno> alunos;
		vector <Disciplina> disciplinas;
		vector <pedido_t> pedidosPendentes;
};

#endif

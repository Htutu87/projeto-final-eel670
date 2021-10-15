// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef SIGA_H
#define SIGA_H

#include "disciplina.h"
#include <mysql.h>

class SIGA {

	public:
		SIGA();
		~SIGA();
		void listarAlunos();
		void listarDisciplinas();
		void registrarAluno(Aluno);
		void registrarDisciplina(Disciplina);	
		void registrarPedido(pedido_t);
		bool alunoExistePorDRE(string);
		bool disciplinaExistePorCodigo(string);	
		void carregarDados();
		void processarPedidos();
		void salvarDados();

	private:
		void recebeDreRetornaAluno(string, Aluno*);
		void recebeCodigoRetornaDisciplina(string, Disciplina*);
		
		vector <Aluno> alunos;
		vector <Disciplina> disciplinas;
		vector <pedido_t> pedidosPendentes;
};

#endif

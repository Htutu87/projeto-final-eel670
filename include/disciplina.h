// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h" 

class Disciplina {
	
	public:
		Disciplina() = default;
		Disciplina(string, string, curso_t, unsigned short, unsigned short);
		string getNome();
		string getCodigo();
		curso_t getCurso();
		unsigned short getPeriodo();
		unsigned short getNumVagas();
		void inscreverAluno(Aluno &);
		vector <Aluno > alunosInscritos;

	private:
		string nome;
		string codigo;
		curso_t curso;
		unsigned short periodo;
		unsigned short numVagas;
};

ostream & operator<<(ostream &, Disciplina);

#endif

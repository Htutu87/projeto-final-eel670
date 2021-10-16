// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef ALUNO_H
#define ALUNO_H

#include "exceptions.h" 

class Aluno {
	
	public:
<<<<<<< HEAD
		Aluno();
=======
		Aluno() = default;
>>>>>>> dev
		Aluno(string, string, string, curso_t, float, unsigned short);
		string getNome();
		string getSobrenome();
		string getDRE();
		curso_t getCurso();
		float getCRA();
		unsigned short getPeriodo();

	private:
		string nome;
		string sobrenome;
		string DRE;
		curso_t curso;
		float CRA;
		unsigned short periodo;
};

ostream & operator<<(ostream &, Aluno);
ostream & operator<<(ostream &, curso_t);

#endif

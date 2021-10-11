// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Exercício avaliado 04
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "common-deps.h"

class ConstrucaoInvalida : public exception {

	public:

		const char * what () const throw()
		{
			return "Contrucao invalida: Algum parametro do construtor nao obedece as normas de inicializacao.";
		}

};

#endif

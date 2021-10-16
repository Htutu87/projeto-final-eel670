// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef DEPS_H
#define DEPS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <exception>

#define MAX_COMPRIMENTO_NOME 20
#define COMPRIMENTO_DRE 9
#define NUM_CURSOS 4
#define MAX_PERIODOS 15
#define COMPRIMENTO_CODIGO_DISCIPLINA 6
#define MAX_COMPRIMENTO_DISCIPLINA 35
#define MAX_NUM_VAGAS 60
#define MIN_NUM_VAGAS 15
#define NUM_PERIODOS_GRADUACAO 10

using namespace std;

//-----------------------------
// Definição de tipos próprios
//-----------------------------

typedef struct pedido {
	string DRE;
	string codigoDisciplina;
} pedido_t;

typedef enum enum_curso{
	ENG_ELETRICA,
	ENG_ELETRONICA,
	ENG_AUTOMACAO,
	ENG_COMPUTACAO
} curso_t;

//-----------------------
// Declarações antecipadas
//-----------------------

inline void pressEnter();

#endif

// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/disciplina.h"

ostream & operator<<(ostream &, Disciplina);

ostream & operator<<(ostream & _cout, Disciplina _d)
{
	_cout << setw(35) << _d.getNome()
	   	<< setw(8) << _d.getCodigo()
		<< setw(20) << _d.getCurso()
		<< setw(10) << _d.getPeriodo()
		<< setw(10) << _d.getNumVagas() << endl;
	return _cout;
}

Disciplina::Disciplina(string _nome, string _codigo, curso_t _curso, unsigned short _periodo, unsigned short _numVagas)
{

	if (_nome.size() > MAX_COMPRIMENTO_DISCIPLINA)
	{
		cout << "[Erro construindo disciplina " << _nome 
			<< " ] Comprimento do nome maior que o permitido ("
			<< MAX_COMPRIMENTO_DISCIPLINA <<  ")" << endl;
		throw ConstrucaoInvalida();
	}

	nome = _nome;

	if (_codigo.size() != COMPRIMENTO_CODIGO_DISCIPLINA)
	{	
		cout << "[Erro construindo disciplina " << _nome 
			<< " ] Comprimento do codigo invalido (correto:"
			<< COMPRIMENTO_CODIGO_DISCIPLINA<<  ")"	<< endl;
		throw ConstrucaoInvalida();
	}

	codigo = _codigo;

	curso = _curso;

	if (_periodo > NUM_PERIODOS_GRADUACAO)
	{
		cout << "[Erro construindo disciplina " << _nome 
			<< " ] Periodo registrado esta fora dos limites da graduacao." << endl;
		throw ConstrucaoInvalida();
	}

	periodo = _periodo;

	if (_numVagas < MIN_NUM_VAGAS || _numVagas > MAX_NUM_VAGAS)
	{	
		cout << "[Erro construindo disciplina " << _nome 
			<< " ] Numero de vagas designado esta fora do intervalo permitido (" << MIN_NUM_VAGAS <<  " a " << MAX_NUM_VAGAS << ") Periodo registrado esta fora dos limites da graduacao." << endl;
		throw ConstrucaoInvalida();
	}

	numVagas = _numVagas;
}

string Disciplina::getNome()
{
	return nome;
}

string Disciplina::getCodigo()
{
	return codigo;
}

curso_t Disciplina::getCurso()
{
	return curso;
}

unsigned short Disciplina::getPeriodo()
{
	return periodo;
}

unsigned short Disciplina::getNumVagas()
{
	return numVagas;
}

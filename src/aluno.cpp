// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/aluno.h" 

//----------------------------------------
// Sobrecarga de operadores globais
//----------------------------------------

ostream & operator<<(ostream & _cout, curso_t _c)
{
	switch(_c)
	{
		case 0:
			_cout << "ENG. ELETRICA";
			break;	
		case 1:
			_cout << "ENG. ELETRONICA";
			break;
		case 2:
			_cout << "ENG. AUTOMACAO";
			break;
		case 3:
			_cout << "ENG. COMPUTACAO";
			break;
	}

	return _cout;
}

ostream & operator<<(ostream & _cout, Aluno _a)
{
	_cout << setw(15) << _a.getNome()
	   	<< setw(15) << _a.getSobrenome()
		<< setw(12) << _a.getDRE()
		<< setw(20) << _a.getCurso()
		<< setw(6) << _a.getCRA()
		<< setw(6) << _a.getPeriodo() << endl;
	return _cout;
}

Aluno::Aluno(string _nome, string _sobrenome, string _DRE,
	   		curso_t _curso, float _CRA, unsigned short _periodo)
{

	if (_nome.size() <= MAX_COMPRIMENTO_NOME)
	{
		nome = _nome;
	}
	else
	{
		cout << "[Erro Construindo aluno(a) " << nome << " ] Comprimento do nome acima do permitido (" 
			<< MAX_COMPRIMENTO_NOME << ")" << endl;
		throw ConstrucaoInvalida();
	}
	
	if (_sobrenome.size() <= MAX_COMPRIMENTO_NOME)
	{
		sobrenome = _sobrenome;
	}
	else
	{
		cout << "[Erro Construindo aluno(a) " << nome << " ] Comprimento do sobrenome acima do permitido (" 
			<< MAX_COMPRIMENTO_NOME << ")" << endl;
		throw ConstrucaoInvalida();
	}
		
	if (_DRE.size() == COMPRIMENTO_DRE)
	{
		if (_DRE.find_first_not_of("0123456789") == string::npos)
			DRE = _DRE;
		else 
		{	
			cout << "[Erro Construindo aluno(a) " << nome << " ] DRE contem caracteres nao numericos." << endl;
			throw ConstrucaoInvalida();
		}
	}
	else 
	{
		cout << "[Erro Construindo aluno(a) " << nome << " ] Comprimento do DRE invalido (correto: " << COMPRIMENTO_DRE << ")." << endl;
		throw ConstrucaoInvalida();
	}

	curso = _curso;

	if (_CRA < 0.0 || _CRA > 10.0)
	{
		cout << "[Erro Construindo aluno(a) " << nome << " ] CRA fora do intervalo valido (0.0 a 10.0)" << endl;
		throw ConstrucaoInvalida();
	}
	else 
	{
		CRA = _CRA;
	}
	
	if (_periodo > MAX_PERIODOS)
	{
		cout << "[Erro Construindo aluno(a) " << nome << " ] Periodo acima do limite valido (" << MAX_PERIODOS <<  ")" << endl;
		throw ConstrucaoInvalida();
	}
	else 
	{
		CRA = _CRA;
	}
	
	periodo = _periodo;

}

string Aluno::getNome() {
	return nome;
}

string Aluno::getSobrenome() {
	return sobrenome;
}

string Aluno::getDRE() {
	return DRE;
}

curso_t Aluno::getCurso() {
	return curso;
}

float Aluno::getCRA() {
	return CRA;
}

unsigned short Aluno::getPeriodo() {
	return periodo;
}

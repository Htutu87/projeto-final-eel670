#include <iostream>
using namespace std;

class inteiro {
    public:
        inteiro(int _v=0){valor = _v;}
        inteiro operator+(inteiro _i){return this->valor + _i.valor;}
        inteiro operator-(inteiro _i){return this->valor - _i.valor;}
        inteiro operator++(int i){return (this->valor)++;}
        inteiro operator--(int i){return (this->valor)--;}
        int valor;
};

int main()
{
    inteiro a(2);
    inteiro b(3);
    inteiro c;
    cout << "Inteiros definidos: " << endl; 
    cout << a.valor << endl;
    cout << b.valor << endl;
    c = a + b;
    cout << "Resultado da soma dos objetos:" << endl;
    cout << c.valor << endl;
    cout << (c++).valor << endl;
    cout << (c--).valor << endl;
    cout << (c - b).valor << endl;

    
    return 0;
}

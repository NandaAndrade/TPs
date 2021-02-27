#include <iostream>
//#include "Fibonacci.h"

using namespace std;

//Nosso Fibonacci começa de 1,1.

template <class T> T Fibonacci(T &a){
    T x = 0, y = 1, val = 1;
    for ( int i = 1; i < a; i++)
    {
        val = x + y;
        x = y;
        y = val;
    }
    return val;

}

int main()
{
    int limite;
    double limdou;
    cout << "Quantos numeros Fibonacci deseja gerar?" << endl;
    cin >> limite;
    cout << Fibonacci(limite)  << endl;
    cout << "Quantos numeros double Fibonacci deseja gerar?" << endl;
    cin >> limdou;
    cout << Fibonacci(limdou)  << endl;
}
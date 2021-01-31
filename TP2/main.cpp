//main.cpp
#include "matrix.h"
#include "matrix.cpp"
#include <iostream>

using namespace std;
int main()
{
    Matrix teste = Matrix(6, 2, 10);

    teste.print();
    int colunas = teste.getCols();
    int linhas = teste.getRows();
    cout << "A Matriz tem:" << endl;
    cout << colunas << " colunas e " << linhas << "linhas!" << endl;

    cout << "a transposta da matriz é:" << endl;
    teste = teste.transpose();
    teste.print();

    return 0;
}
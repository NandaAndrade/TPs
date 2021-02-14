#include <iostream>
#include "Matrix.h"


int main()
{
    Matrix teste = Matrix(6, 2, 10);

    teste.print();
    int colunas = teste.getCols();
    int linhas = teste.getRows();
    cout << "A Matriz tem:" << endl;
    cout << colunas << " colunas e " << linhas << " linhas!" << endl;

    cout << "a transposta da matriz eh:" << endl;
    Matrix transp = teste.transpose();
    transp.print();

    Matrix Y;
    Matrix X(3,1);
    /*ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    Matrix W(in);*/
    

    return 0;
}
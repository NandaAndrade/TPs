#include <iostream>
#include "matrix.h"

using namespace std;
int main()
{
    /*Matrix teste = Matrix(6, 2, 10);

    teste.print();
    int colunas = teste.getCols();
    int linhas = teste.getRows();
    cout << "A Matriz tem:" << endl;
    cout << colunas << " colunas e " << linhas << " linhas!" << endl;

    cout << "a transposta da matriz eh:" << endl;
    Matrix transp = teste.transpose();
    transp.print();*/

    Matrix Y;
    Y.print();
    Matrix X(3, 1);
    X.print();
    Matrix Z(3, 2, 7.0);
    Z.print();
    Matrix A(Z);
    A.print();
    Matrix B = A;
    B.print();

    double aux = B.get(1, 1);
    cout << aux << endl;
    A.unit();
    A.print();
    A.zeros();
    A.print();
    A.ones();
    A.print();

    double denger = Y.get(2, 2);

    /*ifstream in("myMatrix.txt");*/
    //Matrix W(in);

    return 0;
}
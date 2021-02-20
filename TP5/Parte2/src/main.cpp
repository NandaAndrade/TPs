#include <iostream>
#include "matrix.h"
#include <fstream>

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
    cout << "Matriz Y:" << endl;
    Y.print();
    Matrix X(3, 2);
    cout << "Matriz X:" << endl;
    X.print();
    Matrix Z(3, 2, 7.0);
    cout << "Matriz Y:" << endl;
    Z.print();
    Matrix A(Z);
    cout << "Matriz A:" << endl;
    A.print();
    Matrix B = A;
    cout << "Matriz B:" << endl;
    B.print();

    double aux = B.get(1, 1);
    cout << aux << endl;
    A.unit();
    cout << "Matriz A em indentidade:" << endl;
    A.print();
    A.zeros();
    cout << "Matriz A em zeros:" << endl;
    A.print();
    A.ones();
    cout << "Matriz A em uns:" << endl;
    A.print();
    cout << "Matriz B que é igual a A quando ela era setes:" << endl;
    B.print();

    ifstream in("myMatrix.txt"); // Defini que minha matriz possui a primeira linha com as dimensões da matriz a ser lida.
    Matrix W(in);
    W.print();

    //double denger = Y.get(2, 2);
    A += B;
    cout << "Matriz A+B:" << endl;
    A.print();
    Matrix D = Z + Z;
    cout << "Matriz D=z+z (z e de setes):" << endl;
    D.print();
    D -= Z;
    cout << "Matriz D-z:" << endl;
    D.print();
    Matrix E = X - D;
    cout << "Matriz E=(3,2) de zero - D anterior:" << endl;
    E.print();
    D *= 2;
    cout << "Matriz D*2:" << endl;
    D.print();
    Matrix F(2, 2, 2);
    cout << "Matriz F:" << endl;
    F.print();
    Matrix G(2, 2, 3);
    cout << "Matriz G:" << endl;
    G.print();
    Matrix H;
    H = F * G;
    cout << "Matriz H:" << endl;
    H.print();

    return 0;
}
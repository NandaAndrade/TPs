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
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix X(3, 2);
    cout << "Matriz X:" << endl;
    X.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix Z(3, 2, 7.0);
    cout << "Matriz Z:" << endl;
    Z.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix A(Z);
    cout << "Matriz A:" << endl;
    A.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix B = A;
    cout << "Matriz B:" << endl;
    B.print();
    cout<<"----------------------------------------------------------------"<<endl;
    double aux = B.get(1, 1);
    cout << aux << endl;
    cout<<"----------------------------------------------------------------"<<endl;
    A.unit();
    cout << "Matriz A em indentidade:" << endl;
    A.print();
    cout<<"----------------------------------------------------------------"<<endl;
    A.zeros();
    cout << "Matriz A em zeros:" << endl;
    A.print();
    cout<<"----------------------------------------------------------------"<<endl;
    A.ones();
    cout << "Matriz A em uns:" << endl;
    A.print();
    cout<<"----------------------------------------------------------------"<<endl;
    cout << "Matriz B que é igual a A quando ela era setes:" << endl;
    B.print();
    cout<<"----------------------------------------------------------------"<<endl;
    //ifstream in("myMatrix.txt"); // Defini que minha matriz possui a primeira linha com as dimensões da matriz a ser lida.
    //Matrix W(in);
    //W.print();

    //double denger = Y.get(2, 2);
    A += B;
    cout << "Matriz A+B:" << endl;
    A.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix D = Z + Z;
    cout << "Matriz D=z+z (z e de setes):" << endl;
    D.print();
    cout<<"----------------------------------------------------------------"<<endl;
    D -= Z;
    cout << "Matriz D-z:" << endl;
    D.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix E = X - D;
    cout << "Matriz E=(3,2) de zero - D anterior:" << endl;
    E.print();
    cout<<"----------------------------------------------------------------"<<endl;
    D *= 2;
    cout << "Matriz D*2:" << endl;
    D.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix F(2, 2, 2);
    cout << "Matriz F:" << endl;
    F.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix G(2, 2, 3);
    cout << "Matriz G:" << endl;
    G.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix H;
    H = F * G;
    cout << "Matriz H:" << endl;
    H.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix I(4, 4, 10);
    Matrix J(4, 4, 9);
    cout << "Matriz I:" << endl;
    I.print();
    I *= J;
    cout << "Matriz I:" << endl;
    I.print();
    cout<<"----------------------------------------------------------------"<<endl;
    Matrix K(4, 4, 5);
    Matrix L(4, 4, 7);
    K.print();
    K.diferent(L);
    L.print();
    cout<<"----------------------------------------------------------------"<<endl;
    L.transpose();
    L.print();
    cout<<"---------------------------"<<endl;
    K = ~L;
    K.print();
    cout<<"----------------------------------------------------------------"<<endl;
    L(3, 2) = 10;
    L.print();
    cout<<"----------------------------------------------------------------"<<endl;
    if(K == L){
        cout<<"K = L"<<endl;
    }else if(K != L){
        cout<<"K != L"<<endl;
    }else{
        cout<<":("<<endl;
    }
    cout<<"----------------------------------------------------------------"<<endl;

    return 0;
}
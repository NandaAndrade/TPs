// matrix.cpp
#include "matrix.h"
#include <iostream>

using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix(){
        nCols = 0;
        nRows = 0;
    }

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem){
        m = new double* [rows];
        nCols = cols;
        nRows = rows;
        for(int i=0;i<rows;i++){
            m[i]=new double[cols];
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                m[i][j] = elem;
            }
        }
    }

// destrutor
Matrix::~Matrix()
{
    for(int i=0;i<nRows;i++){
            delete[] m[i];
    }
    delete[] m;
}

// obtem o numero de linhas
int Matrix::getRows() const
{
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose()
{
    Matrix transposta = Matrix(nCols, nRows, m[0][0]);
    return transposta;
}

// imprime o conteudo da matriz
void Matrix::print() const
{
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
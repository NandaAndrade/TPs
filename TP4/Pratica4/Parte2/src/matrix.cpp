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
Matrix::Matrix(int rows, int cols, const double &elem = 0.0){
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

    //Construtor parametrico que cria a matriz a partir do arquivo myFile
    /*Matrix::Matrix(ifstream &myFile){
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
    }*/

// Construtor de Copia
Matrix::Matrix(const Matrix& that){
    m = new double* [that.nRows];
    this->nRows = that.nRows;
    this->nCols = that.nCols;
    cout << "Entrei no Construtor de Copia"<< endl;
    for(int i=0;i<nRows;i++){
        m[i]=new double[nCols];
     }

        for(int i=0;i<nRows;i++){
            for(int j=0;j<nCols;j++){
                m[i][j] = that.m[i][j];
            }
        }
        
    cout << "Sai do Construtor de Copia"<< endl;
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

// obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
double Matrix::get(int row, int col) const {
    return m[row][col];
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

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit(){
    
}

// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros(){
    
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
void Matrix::ones(){
    
}
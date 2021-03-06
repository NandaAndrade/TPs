// matrix.cpp
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a elem (double)
Matrix::Matrix( int rows, int cols, const double &elem)
{
    m = new double * [rows];
    nCols = cols;
    nRows = rows;
    for (int i = 1; i <= rows; i++)
    {
        m[i] = new double[nCols];
    }

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            m[i][j] = elem;
        }
    }
}

//Construtor parametrico que cria a matriz a partir do arquivo myFile
Matrix::Matrix(ifstream &myF){
    cout << "Entrei na matriz de arquivo" << endl;
    string line;
    double **m;
    /*int cols = 0;
    getline(myF, line, '\n');
    
    for( int j = 1 ;j <= line.length() ; j++ ){
        if(line[j-1] != ' '){
            cols++;
        }
            
    }

    m = new double* [cols];*/

    int k = 1;
    int l =1;

    while (getline (myF, line)) {
        cout << "Fiz o getline" << endl;
           for( int j = 1 ;j <= line.length() ; j++ ){
            if(line[j-1] != ' '){
                cout << "Copiando dados" << endl;
                m[k][l] = atof(&line[j-1]);
                l++;
            }
            
        }

    }

    
    /*cout << "Entrei na matriz de arquivo" << endl;
    do{
        getline(myF, line, '\n');

        for( int j = 1 ;j <= line.length() ; j++ ){
            if(line[j-1] != ' '){
                cout << "Copiando dados" << endl;
                m[k][l] = atof(&line[j-1]);
                l++;
            }
            
        }
    l++;
    }while (!myF.eof());*/
    
}

// Construtor de Copia
Matrix::Matrix(const Matrix &that)
{
    m = new double *[that.nRows];
    this->nRows = that.nRows;
    this->nCols = that.nCols;
    cout << "Entrei no Construtor de Copia" << endl;
    for (int i = 1; i <= nRows; i++)
    {
        m[i] = new double[nCols];
    }

    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            m[i][j] = that.m[i][j];
        }
    }

    cout << "Sai do Construtor de Copia" << endl;
}

// destrutor
Matrix::~Matrix()
{
    for (int i = 1; i <= nRows; i++)
    {
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
int Matrix::getCols() const
{
    return nCols;
}

// obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
double Matrix::get(int row, int col) const
{
    if (nRows >= row && nCols >= col)
    {
        return m[row][col];
    }
    else
    {
        cout << "posicao nao encontrada" << endl;
        exit(1);
    }
}

// retorna uma matriz transposta
Matrix Matrix::transpose()
{
    Matrix transposta = Matrix(nCols, nRows, m[1][1]);
    return transposta;
}

// imprime o conteudo da matriz
void Matrix::print() const
{
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit()
{
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            if (i == j)
            {
                m[i][j] = 1;
            }
            else
            {
                m[i][j] = 0;
            }
        }
    }
}

// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros()
{
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            m[i][j] = 0;
        }
    }
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguaia a 1
void Matrix::ones()
{
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            m[i][j] = 1;
        }
    }
}
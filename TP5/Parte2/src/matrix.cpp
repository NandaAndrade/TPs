// matrix.cpp
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, const double &elem)
{

    m = new double *[rows];
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
Matrix::Matrix(ifstream &myF)
{

    cout << "Entrei no Construtor de Arquivo" << endl;

    int rows, cols;
    myF.open("myMatrix.txt");
    myF >> rows >> cols;
    cout << rows << ", " << cols << endl;

    //Alocação dinâmica para a matriz:

    m = new double *[rows]; //m é um ponteiro de arrays do tamanho rows
    nCols = cols;
    nRows = rows;
    for (int i = 1; i <= rows; i++)
    {
        m[i] = new double[nCols];
    }

    //Leitura e armazeenamento dos parametros

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            myF >> m[i][j];
            cout << "o elemento " << i << "," << j << " da matriz e: " << m[i][j] << endl;
        }
    }
    cout << "Saí do Construtor de Arquivo" << endl;
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

Matrix Matrix::diferent(const Matrix &that)
{
    that.m[1][1] = 2;
    that.m[1][2] = 4;
    that.m[1][3] = 8;
    that.m[1][4] = 1;
    that.m[2][1] = 7;
    return that;
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

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
////////////////      SOBRECARGA     ////////////////////////
////////////////          DE         ////////////////////////
////////////////     OPERADORES     /////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

Matrix Matrix ::operator+(const Matrix &that)
{
    assert(nRows == that.nRows && nCols == that.nCols);
    Matrix tmp(nRows, nCols);
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            tmp.m[i][j] = this->m[i][j] + that.m[i][j];
        }
    }
    return tmp;
}

Matrix Matrix ::operator-(const Matrix &that)
{
    assert(nRows == that.nRows && nCols == that.nCols);
    Matrix tmp(nRows, nCols);
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            tmp.m[i][j] = this->m[i][j] - that.m[i][j];
        }
    }
    return tmp;
}

Matrix &Matrix ::operator*(const Matrix &that)
{
    assert(this->nCols == that.nRows);
    Matrix *p;
    Matrix tmp(this->nRows, that.nCols);
    for (int i = 1; i <= this->nRows; i++)
    {
        for (int j = 1; j <= that.nCols; j++)
        {
            tmp.m[i][j] = this->m[i][j] * that.m[j][i];
        }
    }
    p = &tmp;
    return *p;
}

void Matrix ::operator*=(const int n)
{
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            this->m[i][j] = this->m[i][j] * n;
        }
    }
}
Matrix &Matrix::operator*=(const Matrix &that)
{
    assert(this->nCols == that.nRows);
    for (int i = 1; i <= this->nRows; i++)
    {
        for (int j = 1; j <= that.nCols; j++)
        {
            this->m[i][j] = this->m[i][j] * that.m[j][i];
        }
    }
    return *this;
}

Matrix &Matrix ::operator+=(const Matrix &that)
{

    assert(nRows == that.nRows && nCols == that.nCols);
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            m[i][j] += that.m[i][j];
        }
    }
    return *this;
}

Matrix &Matrix ::operator-=(const Matrix &that)
{

    assert(nRows == that.nRows && nCols == that.nCols);
    for (int i = 1; i <= nRows; i++)
    {
        for (int j = 1; j <= nCols; j++)
        {
            m[i][j] -= that.m[i][j];
        }
    }
    return *this;
}

double &Matrix::operator()(int i, int j)
{
    return (m[i][j]);
}
bool Matrix::operator==(const Matrix &that)
{
    if (this->nRows == that.nRows && this->nCols == that.nCols)
    {
        for (int i = 1; i <= nRows; i++)
        {
            for (int j = 1; j <= nCols; j++)
            {
                if (this->m[i][j] == that.m[i][j])
                {
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool Matrix::operator!=(const Matrix &that)
{
    if (this->nRows == that.nRows && this->nCols == that.nCols)
    {
        for (int i = 1; i <= nRows; i++)
        {
            for (int j = 1; j <= nCols; j++)
            {
                if (this->m[i][j] != that.m[i][j])
                {
                    return true;
                }
                else
                {
                }
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}
ostream &operator<<(ostream &out, const Matrix &M)
{
    for (int i = 1; i <= M.nRows; i++)
    {
        for (int j = 1; j <= M.nCols; j++)
        {
            out << M.m[i][j] << ' ';
        }
        out << endl;
    }
    return out;
};

istream &operator>>(istream &in, const Matrix &M)
{
    for (int i = 1; i <= M.nRows; i++)
    {
        for (int j = 1; j <= M.nCols; j++)
        {
            in >> M.m[i][j];
        }
    }
    return in;
};
Matrix operator~(const Matrix &M)
{
    Matrix X = M;
    return X.transpose();
}